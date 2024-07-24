#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BluetoothSerial.h>

typedef struct {
  BTAddress btAddress;
  uint32_t btCOD;
  String btName;
  int8_t btRSSI;
} DiscoveredDevice;

extern DiscoveredDevice s3DiscoveredDevices[10];
extern int discoveredDevicesCount;

class S3Bluetooth : private BluetoothSerial {
 private:
  String _bluetoothName;
  unsigned long _bluetoothBaud;
  BluetoothSerial* _bluetooth;
  BTAdvertisedDevice _discoveredDevices[10];

 public:
  S3Bluetooth() = delete;
  S3Bluetooth(const String btName);
  void activateBluetooth();
  void discoverDevices();
  void connect();
  void disconnect();
  void sendText(const char* data);
  void receiveText(char* data);
  void setBluetoothName(String btName);
  String getBluetoothName();
};

class S3BluetoothBLE {};
