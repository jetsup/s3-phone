#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <LittleFS.h>
#include <SD.h>
#include <sqlite3.h>

#include <Config.hpp>
#include <Utils.hpp>

#include "ui/helpers/ui_contacts.h"
#include "ui/helpers/ui_utils.h"

typedef enum {
  CREDENTIALS_WIFI,
} filesystem_credentials_t;

class FileSystem {
  size_t _totalSpaceBytes = 0;
  size_t _usedSpaceBytes = 0;
  FS &_mFs;

 public:
  FileSystem() = delete;

  explicit FileSystem(FS &fileSystem = LittleFS);

 private:
  /**
   * @brief This will be called diring powerup to load saved settings or create
   * defaults if settings not available
   */
  void _loadSettings(bool createIfUnavailable = true);

  /**
   * @brief Read user/system settings a JSON file
   * @param variable The name of the variable to read
   * @param defaultValue The default value of the variable if not present/set
   * @param createIfUnavailable Create the file with this `filename` if it is
   * not saved in the filesystem
   * @return Setting value
   */
  String _readSetting(const char *variable, const char *defaultValue,
                      bool createIfUnavailable = true) const;

  /**
   * @brief Create a file in the file system
   * @param filepath The name of the file to be created. Should start with `/`
   * @return `true` if the file was created successfully, `false` otherwise
   */
  bool _createFile(const char *filepath);

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
  void createDirectory(const char *path) const;

  /**
   * @brief Create a directory
   * @param path The directory to list its content
   */
  String listDirectory(const char *path) const;

  /**
   * @brief Read a file
   * @param filename The name of the file
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void readFile(const char *filename, bool createIfNotExists = true) const;

  /**
   * @brief Append content to the end of a file
   * @param filename The name of the file
   * @param content The content to append
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void appendFile(const char *filename, const char *content,
                  bool createIfNotExists = true) const;

  /**
   * @brief Write to a file
   * @param filename The name of the file
   * @param content The content to write
   * @param createIfNotExists Create the file if it does not exist, by default
   */
  void writeFile(const char *filename, const char *content,
                 bool createIfNotExists = true) const;

  /**
   * @brief Read user/system settings a JSON file
   * @param variable The name of the variable to read
   * @return Setting value
   */
  String readSetting(const char *variable) const;

  /**
   * @brief Edit a setting in a JSON file
   * @param variable The name of the variable to edit
   * @param value The new value of the variable
   * @note createIfUnavailable Create the file with this `filename` if it is not
   * saved in the filesystem
   */
  void editSetting(const char *variable, const char *value) const;

  /**
   * @brief Delete a file from the file system
   */
  void deleteFile(const char *path) const;

  void saveCredentials(filesystem_credentials_t type, const char *key,
                       const char *value) const;

  /**
   * @brief Add or edit the content of a JSON file
   * @param filepath The file containing the JSON object
   * @param key The key of the JSON file
   * @param value The value associated with the key
   */
  void saveToJSON(const char *filepath, const char *key, const char *value);

  /**
   * @brief Edit the content of the JSON including the key
   * @param filepath The file containing the JSON object
   * @param prevKey The previous key to be replaced
   * @param newKey The new key to be added
   * @param value The value associated with the new key
   */
  void editDataJSON(const char *filepath, const char *prevKey,
                    const char *newKey, const char *value) const;

  /**
   * @brief Get the total number of items in a JSON file
   * @param filepath The file containing the JSON object
   * @return The total number of items in the JSON file
   */
  size_t getTotalItemsInJSON(const char *filepath) const;

  /**
   * @brief Read the `keys` and `values` of a JSON document and store them in a
   * variables
   * @param filepath The filename of the JSON file
   * @param keys The buffer to store all the keys in the JSON file
   * @param values The buffer to store all the values associated with the
   * corresponding key
   */
  void readKeyValueJSON(const char *filepath, char **keys, char **values) const;

  /**
   * @brief Delete the data associated with the `key` from the JSON
   * @param filepath The JSON file containing the data
   * @param key The key associated with the data to be deleted
   */
  void deleteDataJSON(const char *filepath, const char *key) const;
};

// SQLite database
class Database {
 private:
  sqlite3 *_db;  // hold the opened database
  sqlite3_stmt *_stmt;
  char *_zErrMsg = nullptr;
  int _rc;

 public:
  Database();

  ~Database();

  /**
   * @brief Open a database file and and assign it to the `db` pointer. If the
   * database file does not exist, it will be created.
   * @param filename The name of the database file
   * @param db The pointer to the database
   * @return SQLITE_OK if successful
   */
  static int openDB(const char *filename, sqlite3 **db);

  /**
   * @brief Execute a query on the database
   * @param sql The SQL query to execute
   * @return SQLITE_OK if successful
   */
  int executeQuery(const char *sql);

  /**
   * @brief Close the database. This is similar to calling the destructor
   */
  void close() const;
};
