#include <Helpers.hpp>

S3Time::S3Time(const int8_t offset, const char* server, bool updateTimeOnInternet)
    : _timezoneHours(offset),
      _server(server),
      _updateTimeOnInternet(updateTimeOnInternet) {
  _timeClient = new NTPClient(_ntpUDP, _server, _timezoneHours * 3600, 60000);

  _timeClient->begin();
  _timeClient->forceUpdate();

  _esp32Time = new ESP32Time(_timezoneHours * 3600);
  _esp32Time->setTime(_timeClient->getEpochTime());
}

S3Time::S3Time(const char* datetime, const int8_t offset, const bool updateTimeOnInternet)
    : _timezoneHours(offset), _updateTimeOnInternet(updateTimeOnInternet) {
  _esp32Time = new ESP32Time(_timezoneHours * 3600);
  _esp32Time->setTime(atol(datetime + 17), atoi(datetime + 14),
                      atoi(datetime + 10), atoi(datetime + 8),
                      atoi(datetime + 5), atoi(datetime));
}

S3Time::S3Time(int8_t offset, const char* server, uint32_t updateInterval,
               bool updateTimeOnInternet)
    : _timezoneHours(offset),
      _server(server),
      _updateInterval(updateInterval),
      _updateTimeOnInternet(updateTimeOnInternet) {
  _timeClient =
      new NTPClient(_ntpUDP, _server, _timezoneHours * 3600, _updateInterval);

  _timeClient->begin();
  _timeClient->forceUpdate();

  _esp32Time = new ESP32Time(_timezoneHours * 3600);
  _esp32Time->setTime(_timeClient->getEpochTime());
}

void S3Time::fetchTime(const bool force) const
{
  if (force) {
    _timeClient->forceUpdate();
  } else {
    _timeClient->update();
  }

  _esp32Time->setTime(_timeClient->getEpochTime());
}

void S3Time::setTimeZone(const float offset) {
  _timezoneHours = offset;
  if (_timeClient == nullptr) {
    _timeClient = new NTPClient(_ntpUDP, _server, _timezoneHours * 3600, 60000);
    _timeClient->begin();
  }
  _timeClient->setTimeOffset(_timezoneHours * 3600);
  _esp32Time->offset = _timezoneHours * 3600;
}

void S3Time::setServer(const char* server) {
  this->_server = server;
  _timeClient->setPoolServerName(server);
}

void S3Time::setUpdateInterval(uint32_t updateInterval) {
  this->_updateInterval = updateInterval;
  _timeClient->setUpdateInterval(updateInterval);
}

void S3Time::loop() {
  if (_esp32Time->getMinute() != _nowMinute ||
      _esp32Time->getHour() != _nowHour || _esp32Time->getDay() != _nowDay ||
      _esp32Time->getMonth() != _nowMonth ||
      _esp32Time->getYear() != _nowYear) {
    _timeUpdated = true;
    _nowMinute = _esp32Time->getMinute();
    _nowHour = _esp32Time->getHour();
    _nowDay = _esp32Time->getDay();
    _nowMonth = _esp32Time->getMonth();
    _nowYear = _esp32Time->getYear();

    /**
     * %a - abbreviated weekday name (Thu)
     * %Y - year (2024)
     * %m - month (01)
     * %d - day of the month (01)
     *
     * %H - hour (24-hour clock) (09)
     * %M - minute (03)
     */

    DEBUG_PRINTF("Time: %s/%s/%s %s :: %s\n", _esp32Time->getTime("%d").c_str(),
                 _esp32Time->getTime("%m").c_str(), _esp32Time->getTime("%Y").c_str(),
                 _esp32Time->getTime("%a").c_str(), _esp32Time->getTime("%H:%M").c_str());
  }
}

void S3Time::updateS3Time(const bool fromInternet, const int updateInterval) {
  if (fromInternet) {
    if (_timeClient == nullptr) {
      _timeClient = new NTPClient(_ntpUDP, _server, _timezoneHours * 3600,
                                  updateInterval);
      _timeClient->begin();
    }
    _timeClient->forceUpdate();

    _ntpTimeUpdated = true;
  }
}

bool S3Time::isNtpTimeUpdated() const { return _ntpTimeUpdated; }

void S3Time::setNtpTimeUpdated(const bool isUpdated) { _ntpTimeUpdated = isUpdated; }

bool S3Time::isTimeUpdated() {
  if (_timeUpdated) {
    _timeUpdated = false;
    return true;
  }

  return false;
}
