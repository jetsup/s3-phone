#include <FileSystem.hpp>

void FileSystem::init() {
  if (!LittleFS.begin()) {
    DEBUG_PRINTLN("File system failed to begin");
#if FILESYSTEM_FORMAT_ON_FAIL
    if (!LittleFS.format()) {
      DEBUG_PRINTLN("File system not formatted!");
    }
#endif
  }
}

void FileSystem::diskUsage() {
  _totalSpaceBytes = LittleFS.totalBytes();
  _usedSpaceBytes = LittleFS.usedBytes();

  DEBUG_PRINTF("Used space: %d/%d\n", _usedSpaceBytes, _totalSpaceBytes);
}

void FileSystem::createDirectory(const char* path) {
  if (!LittleFS.exists(path)) {
    if (!LittleFS.mkdir(path)) {
      DEBUG_PRINTLN("Create directory failed");
    }
  }
}

void FileSystem::readFile(const char* filename, bool createIfNotExists) {
  File file = LittleFS.open(filename, "r", createIfNotExists);
  if (!file) {
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

void FileSystem::writeFile(const char* filename, const char* content,
                           const char* mode, bool createIfNotExists) {
  File file = LittleFS.open(filename, mode, createIfNotExists);
  if (!file) {
    DEBUG_PRINTLN("Failed to open file for writing");
    return;
  }

  if (file.print(content) == 0) {
    DEBUG_PRINTLN("Write failed");
  }
  file.close();
}

void FileSystem::editSetting(const char* filename, const char* variable,
                             const char* value) {
  File file = LittleFS.open(filename, "r+");
  if (!file) {
    DEBUG_PRINTLN("Failed to open file for editing");
    return;
  }

  JsonDocument doc;
  deserializeJson(doc, file);
  doc[variable] = value;

  file.seek(0);
  if (serializeJson(doc, file) == 0) {
    DEBUG_PRINTLN("Failed to write to file");
  }
  file.close();
}

void FileSystem::deleteFile(const char* path) {
  if (!LittleFS.remove(path)) {
    DEBUG_PRINTLN("Delete failed");
  }
}
