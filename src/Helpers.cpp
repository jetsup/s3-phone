#include <Helpers.hpp>

S3Time::S3Time(int8_t offset, const char* server, bool updateTimeOnInternet)
    : _timeZone(offset),
      _server(server),
      _updateTimeOnInternet(updateTimeOnInternet) {
  _timeClient = new NTPClient(_ntpUDP, _server, _timeZone * 3600, 60000);

  _timeClient->begin();
  _timeClient->forceUpdate();

  _esp32Time = new ESP32Time(_timeZone * 3600);
  _esp32Time->setTime(_timeClient->getEpochTime());
}

S3Time::S3Time(const char* datetime, int8_t offset, bool updateTimeOnInternet)
    : _timeZone(offset), _updateTimeOnInternet(updateTimeOnInternet) {
  _esp32Time = new ESP32Time(_timeZone * 3600);
  _esp32Time->setTime(atol(datetime + 17), atoi(datetime + 14),
                      atoi(datetime + 10), atoi(datetime + 8),
                      atoi(datetime + 5), atoi(datetime));
}

S3Time::S3Time(int8_t offset, const char* server, uint32_t updateInterval,
               bool updateTimeOnInternet)
    : _timeZone(offset),
      _server(server),
      _updateInterval(updateInterval),
      _updateTimeOnInternet(updateTimeOnInternet) {
  _timeClient =
      new NTPClient(_ntpUDP, _server, _timeZone * 3600, _updateInterval);

  _timeClient->begin();
  _timeClient->forceUpdate();

  _esp32Time = new ESP32Time(_timeZone * 3600);
  _esp32Time->setTime(_timeClient->getEpochTime());
}

void S3Time::fetchTime(bool force) {
  if (force) {
    _timeClient->forceUpdate();
  } else {
    _timeClient->update();
  }

  _esp32Time->setTime(_timeClient->getEpochTime());
}

void S3Time::setTimeZone(int8_t offset) {
  _timeZone = offset;
  _timeClient->setTimeOffset(_timeZone * 3600);
  _esp32Time->offset = _timeZone * 3600;
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

    DEBUG_PRINTF("Time: %s/%s/%s %s :: %s\n", _esp32Time->getTime("%d"),
                 _esp32Time->getTime("%m"), _esp32Time->getTime("%Y"),
                 _esp32Time->getTime("%a"), _esp32Time->getTime("%H:%M"));
  }
}

bool S3Time::isTimeUpdated() {
  if (_timeUpdated) {
    _timeUpdated = false;
    return true;
  }

  return false;
}
