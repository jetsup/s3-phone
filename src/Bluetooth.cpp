#include <Bluetooth.hpp>

int discoveredDevicesCount;
DiscoveredDevice discoveredDevices[10];

S3Bluetooth::S3Bluetooth(String btName, int scanTime)
    : _bluetoothName(btName), _scanTime(scanTime) {}

void S3Bluetooth::clientModeInit() {
  BLEDevice::init("");
  _bleScan = BLEDevice::getScan();
  _bleScan->setAdvertisedDeviceCallbacks(new S3DeviceAdvertiseCallback());
  _bleScan->setActiveScan(true);
  _bleScan->setInterval(100);
  _bleScan->setWindow(99);
}

void S3Bluetooth::clientScanServers() {
  // TODO: implement
}

void S3Bluetooth::clientTerminate() {
  _bleScan->clearResults();
  _bleScan->stop();
}

void S3Bluetooth::serverModeInit() {
  BLEDevice::init(_bluetoothName.c_str());
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  _pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(
      0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
}

void S3Bluetooth::serverSetData(String data) {
  //
  _pCharacteristic->setValue(data.c_str());
}

//

void S3DeviceAdvertiseCallback::onResult(BLEAdvertisedDevice advertisedDevice) {
  DiscoveredDevice dDevice = {
      advertisedDevice.getAddress().toString().c_str(),
      (advertisedDevice.haveRSSI()) ? advertisedDevice.getRSSI() : -1,
      (advertisedDevice.haveName()) ? String(advertisedDevice.getName().c_str())
                                    : "",
      advertisedDevice.getServiceUUID(),
  };
  discoveredDevices[discoveredDevicesCount++] = dDevice;
}
