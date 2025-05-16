#pragma once

#include <Arduino.h>
#include <ESP32Time.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ui/helpers/ui_utils.h>

#include <Config.hpp>
#include <Utils.hpp>

class S3Time : public ESP32Time {
 private:
  float _timezoneHours;
  const char* _server;
  uint32_t _updateInterval;
  WiFiUDP _ntpUDP;
  NTPClient* _timeClient = nullptr;
  ESP32Time* _esp32Time;
  bool _timeUpdated = false;
  bool _updateTimeOnInternet = true;
  bool _timeUpdatedOnInternet = false;
  bool _ntpTimeUpdated = false;

  int _nowMinute = -1;
  int _nowHour = -1;
  int _nowDay = -1;
  int _nowMonth = -1;
  int _nowYear = -1;

  int _lastTimeUpdate = 0;

 private:
  S3Time() = delete;

 public:
  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param server NTP server eg "pool.ntp.org"
   */
  S3Time(int8_t offset, const char* server, bool updateTimeOnInternet = true);

  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param datetime Date and time in `YYYY-MM-DD HH:MM:SS` format
   */
  S3Time(const char* datetime = "2024-01-01 00:00:00", int8_t offset = 0,
         bool updateTimeOnInternet = true);

  /**
   * @brief Construct a new S3Time object
   * @param offset Timezone offset eg 8, -8
   * @param server NTP server eg "pool.ntp.org"
   * @param updateInterval Update interval in milliseconds
   */
  S3Time(int8_t offset, const char* server, uint32_t updateInterval,
         bool updateTimeOnInternet = true);

  /**
   * @brief Fetch time from NTP server
   * @param force Force update
   */
  void fetchTime(bool force = false) const;

  /**
   * @brief Set timezone offset
   * @param offset Timezone offset in hours. e.g. 3.5 for GMT +03:30
   */
  void setTimeZone(float offset);

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

  /**
   * @brief Keep the time updated, call this in loop
   */
  void loop();

  /**
   * @brief Update time
   * @param fromInternet Update time from internet
   * @param updateInterval Update interval in milliseconds
   */
  void updateS3Time(bool fromInternet, int updateInterval = 60000);

  /**
   * @brief Check if NTP time is updated since
   */
  bool isNtpTimeUpdated() const;

  /**
   * @brief Update NTP time check variable
   */
  void setNtpTimeUpdated(bool isUpdated);

  /**
   * @brief Check if time is updated
   * @return true if time is updated, false otherwise
   */
  bool isTimeUpdated();
};
