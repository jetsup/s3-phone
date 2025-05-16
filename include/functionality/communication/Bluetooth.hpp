#pragma once

#include <Arduino.h>
#include <BLEAdvertisedDevice.h>
#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEUtils.h>
#include <string.h>

#include <Config.hpp>

typedef struct {
  String btAddress;
  int rssi;
  String name;
  BLEUUID uuid;
} DiscoveredDevice;

extern int discoveredDevicesCount;
extern DiscoveredDevice discoveredDevices[10];

class S3Bluetooth {
 private:
  String _bluetoothName;
  int _scanTime;
  unsigned long _bluetoothBaud;
  BLEScan* _bleScan;
  BLECharacteristic *_pCharacteristic;

 public:
  S3Bluetooth() = delete;
  explicit S3Bluetooth(const String &btName, int scanTime = 5);
  void clientModeInit();
  static void clientScanServers();
  void clientTerminate() const;
  void serverModeInit();
  void serverSetData(const String &data) const;
};

class S3DeviceAdvertiseCallback final : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) override;
};
