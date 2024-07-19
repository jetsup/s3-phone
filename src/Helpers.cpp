#include <Helpers.hpp>

S3Time::S3Time(int8_t offset, const char* server)
    : timeZone(offset), server(server) {
  timeClient = new NTPClient(ntpUDP, server, offset * 3600, 60000);

  timeClient->begin();
  timeClient->forceUpdate();

  esp32Time = new ESP32Time(offset * 3600);
  esp32Time->setTime(timeClient->getEpochTime());
}

S3Time::S3Time(const char* datetime, int8_t offset) : timeZone(offset) {
  esp32Time = new ESP32Time(offset * 3600);
  esp32Time->setTime(atol(datetime + 17), atoi(datetime + 14),
                     atoi(datetime + 10), atoi(datetime + 8),
                     atoi(datetime + 5), atoi(datetime));
}

S3Time::S3Time(int8_t offset, const char* server, uint32_t updateInterval)
    : timeZone(offset), server(server), updateInterval(updateInterval) {
  timeClient = new NTPClient(ntpUDP, server, offset * 3600, updateInterval);

  timeClient->begin();
  timeClient->forceUpdate();

  esp32Time = new ESP32Time(offset * 3600);
  esp32Time->setTime(timeClient->getEpochTime());
}

void S3Time::fetchTime(bool force) {
  if (force) {
    timeClient->forceUpdate();
  } else {
    timeClient->update();
  }

  esp32Time->setTime(timeClient->getEpochTime());
}

void S3Time::setTimeZone(int8_t offset) {
  timeZone = offset;
  timeClient->setTimeOffset(offset * 3600);
  esp32Time->offset = offset * 3600;
}

void S3Time::setServer(const char* server) {
  this->server = server;
  timeClient->setPoolServerName(server);
}

void S3Time::setUpdateInterval(uint32_t updateInterval) {
  this->updateInterval = updateInterval;
  timeClient->setUpdateInterval(updateInterval);
}

void S3Time::loop() {
  if (esp32Time->getMinute() != _nowMinute ||
      esp32Time->getHour() != _nowHour || esp32Time->getDay() != _nowDay ||
      esp32Time->getMonth() != _nowMonth || esp32Time->getYear() != _nowYear) {
        
    _timeUpdated = true;
    _nowMinute = esp32Time->getMinute();
    _nowHour = esp32Time->getHour();
    _nowDay = esp32Time->getDay();
    _nowMonth = esp32Time->getMonth();
    _nowYear = esp32Time->getYear();

    /**
     * %a - abbreviated weekday name (Thu)
     * %Y - year (2024)
     * %m - month (01)
     * %d - day of the month (01)
     *
     * %H - hour (24-hour clock) (09)
     * %M - minute (03)
     */

    DEBUG_PRINTF("Time: %s/%s/%s %s :: %s\n", esp32Time->getTime("%d"),
                 esp32Time->getTime("%m"), esp32Time->getTime("%Y"),
                 esp32Time->getTime("%a"), esp32Time->getTime("%H:%M"));
  }
}

bool S3Time::isTimeUpdated() {
  if (_timeUpdated) {
    _timeUpdated = false;
    return true;
  }

  return false;
}
