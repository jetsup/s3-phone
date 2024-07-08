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
  esp32Time->setTime(atol(datetime + 17), atoi(datetime + 11),
                     atoi(datetime + 14), atoi(datetime + 8),
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