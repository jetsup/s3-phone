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
  S3Bluetooth(String btName, int scanTime = 5);
  void clientModeInit();
  void clientScanServers();
  void clientTerminate();
  void serverModeInit();
  void serverSetData(String data);
};

class S3DeviceAdvertiseCallback : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice);
};
