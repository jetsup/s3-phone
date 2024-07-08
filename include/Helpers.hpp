#pragma once

#include <Arduino.h>
#include <ESP32Time.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class S3Time : public ESP32Time {
 private:
  int8_t timeZone;
  const char* server;
  uint32_t updateInterval;
  WiFiUDP ntpUDP;
  NTPClient* timeClient;
  ESP32Time* esp32Time;

 private:
  S3Time() = delete;

 public:
  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param server NTP server eg "pool.ntp.org"
   */
  S3Time(int8_t offset, const char* server);

  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param datetime Date and time in `YYYY-MM-DD HH:MM:SS` format
   */
  S3Time(const char* datetime = "2024-01-01 00:00:00", int8_t offset = 0);

  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param server NTP server eg "pool.ntp.org"
   * @param updateInterval Update interval in milliseconds
   */
  S3Time(int8_t offset, const char* server, uint32_t updateInterval);

  /**
   * @brief Fetch time from NTP server
   * @param force Force update
   */
  void fetchTime(bool force = false);

  /**
   * @brief Set timezone offset
   * @param offset Timezone offset eg 8, -8
   */
  void setTimeZone(int8_t offset);

  /**
   * @brief Set NTP server
   * @param server NTP server eg "pool.ntp.org"
   */
  void setServer(const char* server);

  /**
   * @brief Set update interval
   * @param interval Update interval in milliseconds
   */
  void setUpdateInterval(uint32_t interval);
};