#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <LittleFS.h>
#include <SD.h>

#include <Config.hpp>
#include <Utils.hpp>

class FileSystem {
 private:
  size_t _totalSpaceBytes;
  size_t _usedSpaceBytes;

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
   * @brief Read a file
   * @param filename The name of the file
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void readFile(const char* filename, bool createIfNotExists = true);

  /**
   * @brief Write to a file
   * @param filename The name of the file
   * @param content The content to write
   * @param mode The mode to open the file in
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void writeFile(const char* filename, const char* content,
                 const char* mode = "a", bool createIfNotExists = true);

  /**
   * @brief Edit a setting in a JSON file
   * @param filename The name of the file
   * @param variable The name of the variable to edit
   * @param value The new value of the variable
   */
  void editSetting(const char* filename, const char* variable,
                   const char* value);

/**
 * @brief Delete a file from the file system
 */
  void deleteFile(const char* path);
};