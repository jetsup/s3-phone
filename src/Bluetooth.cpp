#include <Bluetooth.hpp>

void _bluetoothDiscoveredCb(BTAdvertisedDevice* discoveredDevice);

DiscoveredDevice s3DiscoveredDevices[10];
int discoveredDevicesCount;

S3Bluetooth::S3Bluetooth(const String btName) : _bluetoothName(btName) {
  _bluetooth = new BluetoothSerial();
}

void S3Bluetooth::activateBluetooth() {  //
  _bluetooth->begin(_bluetoothName);
}

void S3Bluetooth::discoverDevices() {  //
  _bluetooth->discoverAsync(_bluetoothDiscoveredCb);
}

void S3Bluetooth::connect() {
  _bluetooth->begin(_bluetoothName);
  _bluetooth->connect(_bluetoothName);
}

void S3Bluetooth::disconnect() {
  _bluetooth->discoverAsyncStop();
  _bluetooth->discoverClear();
  _bluetooth->disconnect();
}

void S3Bluetooth::sendText(const char* data) {}

void S3Bluetooth::receiveText(char* data) {}

void S3Bluetooth::setBluetoothName(String btName) {  //
  _bluetoothName = btName;
}

String S3Bluetooth::getBluetoothName() {  //
  return _bluetoothName;
}

// ===============================================================================
void _bluetoothDiscoveredCb(BTAdvertisedDevice* discoveredDevice) {
  s3DiscoveredDevices[discoveredDevicesCount].btAddress =
      discoveredDevice->getAddress();

  s3DiscoveredDevices[discoveredDevicesCount].btCOD =
      (discoveredDevice->haveCOD()) ? discoveredDevice->getCOD() : -1;

  s3DiscoveredDevices[discoveredDevicesCount].btName =
      (discoveredDevice->haveName())
          ? String(discoveredDevice->getName().c_str())
          : "Unnamed";

  s3DiscoveredDevices[discoveredDevicesCount].btRSSI =
      (discoveredDevice->haveRSSI()) ? discoveredDevice->getRSSI() : -1;

  discoveredDevicesCount++;
}
