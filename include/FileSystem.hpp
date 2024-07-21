#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <LittleFS.h>
#include <SD.h>

#include <Config.hpp>
#include <Utils.hpp>

#include "ui_utils.h"

class FileSystem {
 private:
  size_t _totalSpaceBytes;
  size_t _usedSpaceBytes;
  fs::FS& _mFs;

 public:
  FileSystem() = delete;

  FileSystem(fs::FS& fileSystem = LittleFS);

 private:
  /**
   * @brief This will be called diring powerup to load saved settings or create
   * defaults if settings not available
   */
  void _loadSettings(bool createIfUnavailable = true);

  /**
   * @brief Read user/system settings a JSON file
   * @param filename The name of the file
   * @param variable The name of the variable to read
   * @param defaultValue The default value of the variable if not present/set
   * @param createIfUnavailable Create the file with this `filename` if it not
   * saved in the filesystem
   * @return Setting value
   */
  String _readSetting(const char* variable, const char* defaultValue,
                     bool createIfUnavailable = true);

 public:
  /**
   * @brief Initialize the file system. Formats the file system if it fails to
   * begin if FORMAT_ON_FAIL is set
   */
  void init();

  /**
   * @brief Query the disk usage
   */
  void diskUsage();

  /**
   * @brief Create a directory
   * @param path The path of the directory to create
   */
  void createDirectory(const char* path);

  /**
   * @brief Create a directory
   * @param path The directory to list its content
   */
  String listDirectory(const char* path);

  /**
   * @brief Read a file
   * @param filename The name of the file
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void readFile(const char* filename, bool createIfNotExists = true);

  /**
   * @brief Append content to the end of a file
   * @param filename The name of the file
   * @param content The content to append
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void appendFile(const char* filename, const char* content,
                  bool createIfNotExists = true);

  /**
   * @brief Write to a file
   * @param filename The name of the file
   * @param content The content to write
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void writeFile(const char* filename, const char* content,
                 bool createIfNotExists = true);

  /**
   * @brief Read user/system settings a JSON file
   * @param variable The name of the variable to read
   * @return Setting value
   */
  String readSetting(const char* variable);

  /**
   * @brief Edit a setting in a JSON file
   * @param variable The name of the variable to edit
   * @param value The new value of the variable
   * @param createIfUnavailable Create the file with this `filename` if it not
   * saved in the filesystem
   */
  void editSetting(const char* variable, const char* value);

  /**
   * @brief Delete a file from the file system
   */
  void deleteFile(const char* path);
};
