#include <functionality/storage/FileSystem.hpp>

FileSystem::FileSystem(fs::FS& fileSystem) : _mFs(fileSystem) {}

void FileSystem::init() {
  while (!LittleFS.begin(FILESYSTEM_FORMAT_ON_FAIL)) {
    DEBUG_PRINTLN("File system filed to start!");
    delay(5000);
  }
  _loadSettings();
}

void FileSystem::diskUsage() {
  _totalSpaceBytes = LittleFS.totalBytes();
  _usedSpaceBytes = LittleFS.usedBytes();

  DEBUG_PRINTF("Used space: %d/%d\n", _usedSpaceBytes, _totalSpaceBytes);
}

void FileSystem::createDirectory(const char* path) {
  if (!_mFs.exists(path)) {
    if (!_mFs.mkdir(path)) {
      DEBUG_PRINTLN("Create directory failed");
    }
  }
}

String FileSystem::listDirectory(const char* path) {
  File folder = _mFs.open(path);

  if (!folder || !folder.isDirectory()) {
    DEBUG_PRINTF("'%s' is not a folder!", path);
    return "NULL";
  }

  String dirContent = "";
  File fContent = folder.openNextFile();

  while (fContent) {
    if (fContent.isDirectory()) {
      if (dirContent.equals("")) {
        dirContent += "(D)" + String(fContent.name());
      } else {
        dirContent += ",(D)" + String(fContent.name());
      }
    } else {
      if (dirContent.equals("")) {
        dirContent += "(F)" + String(fContent.name());
      } else {
        dirContent += ",(F)" + String(fContent.name());
      }
    }
    fContent = folder.openNextFile();
  }

  return dirContent;
}

void FileSystem::readFile(const char* filename, bool createIfNotExists) {
  File file = _mFs.open(filename, FILE_READ, createIfNotExists);
  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file for reading");
    return;
  }

  DEBUG_PRINTLN("File content:");
  while (file.available()) {
    DEBUG_PRINT((char)file.read());
  }
  DEBUG_PRINTLN();
  file.close();
}

void FileSystem::appendFile(const char* filename, const char* content,
                            bool createIfNotExists) {
  File file = _mFs.open(filename, FILE_APPEND, createIfNotExists);
  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file for writing");
    return;
  }

  if (file.print(content) == 0) {
    DEBUG_PRINTLN("Write failed");
  }
  file.close();
}

void FileSystem::writeFile(const char* filename, const char* content,
                           bool createIfNotExists) {
  File file = _mFs.open(filename, FILE_WRITE, createIfNotExists);
  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file for writing");
    return;
  }

  if (file.print(content) == 0) {
    DEBUG_PRINTLN("Write failed");
  }
  file.close();
}

void FileSystem::_loadSettings(bool createIfUnavailable) {
  // load display settings
  String settingsParameters[] = {FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS,
                                 FS_VAR_SETTINGS_DISPLAY_TIMEOUT,
                                 FS_VAR_SETTINGS_THEMES_THEME_DARK,
                                 FS_VAR_SETTINGS_THEMES_WALLPAPER,
                                 FS_VAR_SETTINGS_THEMES_FONT_SMALL,
                                 FS_VAR_SETTINGS_THEMES_FONT_MEDIUM,
                                 FS_VAR_SETTINGS_THEMES_FONT_LARGE,
                                 FS_VAR_SETTINGS_CONNECTIVITY_BLE,
                                 FS_VAR_SETTINGS_NETWORKING_HOTSPOT_NAME,
                                 FS_VAR_SETTINGS_NETWORKING_WIFI_STATE,
                                 FS_VAR_SETTINGS_DATE_TIME_DATE,
                                 FS_VAR_SETTINGS_DATE_TIME_TIME,
                                 FS_VAR_SETTINGS_DATE_TIME_SYNC,
                                 FS_VAR_SETTINGS_DATE_TIME_TIMEZONE};

  String settingsParDefaults[] = {FS_DEF_SETTINGS_DISPLAY_BRIGHTNESS,
                                  FS_DEF_SETTINGS_DISPLAY_TIMEOUT,
                                  FS_DEF_SETTINGS_THEMES_THEME_DARK,
                                  FS_DEF_SETTINGS_THEMES_WALLPAPER,
                                  FS_DEF_SETTINGS_THEMES_FONT_SMALL,
                                  FS_DEF_SETTINGS_THEMES_FONT_MEDIUM,
                                  FS_DEF_SETTINGS_THEMES_FONT_LARGE,
                                  FS_DEF_SETTINGS_CONNECTIVITY_BLE,
                                  FS_DEF_SETTINGS_NETWORKING_HOTSPOT_NAME,
                                  FS_DEF_SETTINGS_NETWORKING_WIFI_STATE,
                                  FS_DEF_SETTINGS_DATE_TIME_DATE,
                                  FS_DEF_SETTINGS_DATE_TIME_TIME,
                                  FS_DEF_SETTINGS_DATE_TIME_SYNC,
                                  FS_DEF_SETTINGS_DATE_TIME_TIMEZONE};

  for (int i = 0;
       i < sizeof(settingsParameters) / sizeof(settingsParameters[0]); i++) {
    String setting =
        _readSetting(settingsParameters[i].c_str(),
                     settingsParDefaults[i].c_str(), createIfUnavailable);
    DEBUG_PRINTF("Variable: %s :: Default: %s\n", settingsParameters[i].c_str(),
                 settingsParDefaults[i].c_str());
    DEBUG_PRINTF("%s: %s\n", settingsParameters[i], setting);
  }
}

String FileSystem::readSetting(const char* variable) {
  String filename = "";
  if (String(variable).equals(FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SETTINGS_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_THEMES_THEME_DARK) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_WALLPAPER) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_SMALL) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_MEDIUM) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_LARGE)) {
    filename = FS_SETTINGS_THEMES_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_CONNECTIVITY_BLE)) {
    filename = FS_SETTINGS_CONNECTIVITY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_NETWORKING_HOTSPOT_NAME) ||
             String(variable).equals(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE)) {
    filename = FS_SETTINGS_NETWORK_INTERNET_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_DATE) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIME) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_SYNC) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIMEZONE)) {
    filename = FS_SETTINGS_DATE_TIME_FILEPATH;
  }

  File file = _mFs.open(filename, FILE_READ);

  if (!file || file.isDirectory()) {
    DEBUG_PRINTF("Failed to open file for reading: %s\n", filename);
    return "Failed to open " + String(filename);
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  String value = doc[variable];

  file.close();

  DEBUG_PRINTF("%s: %s\n", variable, value);
  return value;
}

String FileSystem::_readSetting(const char* variable, const char* defaultValue,
                                bool createIfUnavailable) {
  String filename = "";
  JsonDocument doc;

  if (String(variable).equals(FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SETTINGS_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_THEMES_THEME_DARK) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_WALLPAPER) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_SMALL) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_MEDIUM) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_LARGE)) {
    filename = FS_SETTINGS_THEMES_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_CONNECTIVITY_BLE)) {
    filename = FS_SETTINGS_CONNECTIVITY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_NETWORKING_HOTSPOT_NAME) ||
             String(variable).equals(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE)) {
    filename = FS_SETTINGS_NETWORK_INTERNET_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_DATE) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIME) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_SYNC) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIMEZONE)) {
    filename = FS_SETTINGS_DATE_TIME_FILEPATH;
  }

  DEBUG_PRINTF("Reading setting: %s\n", filename);
  File file = _mFs.open(filename, FILE_READ, createIfUnavailable);

  if (!file) {
    DEBUG_PRINTF("'%s' does not exist\n", filename);
    if (file.isDirectory()) {
      DEBUG_PRINTF("The Path '%s' is a directory\n", filename);
      return "Failed to open " + String(filename);
    }

    file = _mFs.open(filename, FILE_WRITE, createIfUnavailable);

    if (!file || file.isDirectory()) {
      DEBUG_PRINTF("Failed to open file for writing: %s\n", filename);
      return "Failed to open " + String(filename);
    }
    deserializeJson(doc, file);

    doc[variable] = defaultValue;
    String value = defaultValue;

    file.seek(0);
    if (serializeJson(doc, file) == 0) {
      DEBUG_PRINTF("Failed to write to file: %s\n", filename);
    }

    file.close();
    return value;
  }

  deserializeJson(doc, file);

  String value = doc[variable];

  if (value.equals("") || value == "null") {
    DEBUG_PRINTF("Applying default setting for '%s' <- '%s'\n", filename,
                 defaultValue);
    file = _mFs.open(filename, FILE_WRITE, createIfUnavailable);

    if (!file || file.isDirectory()) {
      DEBUG_PRINTF("Failed to open file for writing: %s\n", filename);
      return "Failed to open " + String(filename);
    }

    doc[variable] = defaultValue;
    value = defaultValue;

    file.seek(0);
    if (serializeJson(doc, file) == 0) {
      DEBUG_PRINTF("Failed to write to file: %s\n", filename);
    }
  }

  file.close();
  return value;
}

void FileSystem::editSetting(const char* variable, const char* value) {
  String filename = "";
  if (String(variable).equals(FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SETTINGS_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_THEMES_THEME_DARK) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_WALLPAPER) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_SMALL) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_MEDIUM) ||
             String(variable).equals(FS_VAR_SETTINGS_THEMES_FONT_LARGE)) {
    filename = FS_SETTINGS_THEMES_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_CONNECTIVITY_BLE)) {
    filename = FS_SETTINGS_CONNECTIVITY_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_NETWORKING_HOTSPOT_NAME) ||
             String(variable).equals(FS_VAR_SETTINGS_NETWORKING_WIFI_STATE)) {
    filename = FS_SETTINGS_NETWORK_INTERNET_FILEPATH;
  } else if (String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_DATE) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIME) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_SYNC) ||
             String(variable).equals(FS_VAR_SETTINGS_DATE_TIME_TIMEZONE)) {
    filename = FS_SETTINGS_DATE_TIME_FILEPATH;
  }

  File file = _mFs.open(filename, FILE_READ);
  if (!file) {
    DEBUG_PRINTF("Failed to open file for editing: %s\n", filename);
    return;
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  file = _mFs.open(filename, FILE_WRITE);
  doc[variable] = value;

  file.seek(0);
  if (serializeJson(doc, file) == 0) {
    DEBUG_PRINTF("Failed to edit to file: %s\n", filename);
  }
  file.close();
}

void FileSystem::deleteFile(const char* path) {
  if (!_mFs.remove(path)) {
    DEBUG_PRINTF("Delete failed: %s\n", path);
  }
}

void FileSystem::saveCredentials(filesystem_credentials_t type, const char* key,
                                 const char* value) {
  String filename = "";
  switch (type) {
    case CREDENTIALS_WIFI:
      filename = FS_SETTINGS_NETWORK_WIFI_CREDENTIALS_FILEPATH;
      break;
  }

  File file = _mFs.open(filename, FILE_APPEND, true);
  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file for writing");
    return;
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  doc[key] = value;

  file.seek(0);
  if (serializeJson(doc, file) == 0) {
    DEBUG_PRINTLN("Failed to write to file");
  }
  file.close();
}

// SQLite implementation
Database::Database() { sqlite3_initialize(); }

Database::~Database() {
  sqlite3_close(_db);
  sqlite3_free(_zErrMsg);
}

int Database::openDB(const char* filename, sqlite3** db) {
  int code = sqlite3_open(filename, db);
  if (code != SQLITE_OK) {
    DEBUG_PRINTF("Failed to open database: %s\n", sqlite3_errmsg(*db));
  }
  return code;
}

int Database::executeQuery(const char* sql) {
  int code = sqlite3_exec(_db, sql, NULL, 0, &_zErrMsg);
  if (code != SQLITE_OK) {
    DEBUG_PRINTF("Failed to execute query: %s\n", _zErrMsg);
  }
  return code;
}

void Database::close() {
  sqlite3_close(_db);
  sqlite3_free(_zErrMsg);
}
