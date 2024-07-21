#include <FileSystem.hpp>

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
  String settingsParameters[] = {FS_VAR_SYSTEM_DISPLAY_BRIGHTNESS,
                                 FS_VAR_SYSTEM_DISPLAY_TIMEOUT};
  String settingsParDefaults[] = {FS_DEF_SYSTEM_DISPLAY_BRIGHTNESS,
                                  FS_DEF_SYSTEM_DISPLAY_TIMEOUT};

  for (int i = 0;
       i < sizeof(settingsParameters) / sizeof(settingsParameters[0]); i++) {
    String setting =
        _readSetting(settingsParameters[i].c_str(),
                     settingsParDefaults[i].c_str(), createIfUnavailable);
    DEBUG_PRINTF("Load: %s\n", setting);
  }
}

String FileSystem::readSetting(const char* variable) {
  String filename = "";
  if (String(variable).equals(FS_VAR_SYSTEM_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SYSTEM_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  }
  File file = _mFs.open(filename, FILE_READ);

  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file");
    return "Failed to open " + String(filename);
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  String value = doc[variable];

  file.close();
  return value;
}

String FileSystem::_readSetting(const char* variable, const char* defaultValue,
                                bool createIfUnavailable) {
  String filename = "";
  if (String(variable).equals(FS_VAR_SYSTEM_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SYSTEM_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  }

  File file = _mFs.open(filename, FILE_READ, createIfUnavailable);

  if (!file || file.isDirectory()) {
    DEBUG_PRINTLN("Failed to open file");
    return "Failed to open " + String(filename);
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  String value = doc[variable];

  if (value.equals("") || value == "null") {
    DEBUG_PRINTF("Applying default setting for '%s' <- '%s'\n", filename,
                 defaultValue);
    file = _mFs.open(filename, FILE_WRITE, createIfUnavailable);

    if (!file || file.isDirectory()) {
      DEBUG_PRINTLN("Failed to open file for writing");
      return "Failed to open " + String(filename);
    }

    doc[variable] = defaultValue;
    value = defaultValue;

    file.seek(0);
    if (serializeJson(doc, file) == 0) {
      DEBUG_PRINTLN("Failed to write to file");
    }
  }

  file.close();
  return value;
}

void FileSystem::editSetting(const char* variable, const char* value) {
  String filename = "";
  if (String(variable).equals(FS_VAR_SYSTEM_DISPLAY_BRIGHTNESS) ||
      String(variable).equals(FS_VAR_SYSTEM_DISPLAY_TIMEOUT)) {
    filename = FS_SETTINGS_DISPLAY_FILEPATH;
  }

  File file = _mFs.open(filename, FILE_READ);
  if (!file) {
    DEBUG_PRINTLN("Failed to open file for editing");
    return;
  }

  JsonDocument doc;
  deserializeJson(doc, file);

  file = _mFs.open(filename, FILE_WRITE);
  doc[variable] = value;

  file.seek(0);
  if (serializeJson(doc, file) == 0) {
    DEBUG_PRINTLN("Failed to write to file");
  }
  file.close();
}

void FileSystem::deleteFile(const char* path) {
  if (!_mFs.remove(path)) {
    DEBUG_PRINTLN("Delete failed");
  }
}
