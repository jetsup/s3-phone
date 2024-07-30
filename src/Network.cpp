#include <Network.hpp>

Network::Network(String hostname)
    : _previousConnectionRetryTime(0),
      _isConnected(false),
      _shouldConnect(false),
      _previousFoundDeviceCount(0),
      _hostname(hostname) {}

Network::~Network() {
  //
}

void Network::enableStationMode() {
  WiFi.mode(WIFI_STA);
  _isStation = true;
}

void Network::enableAccessPionMode() {
  WiFi.mode(WIFI_AP);
  _isAccessPoint = true;
}

uint8_t Network::scanAccessPoints() {
  if (!_scanning) {
    if (!_isStation) {
      enableStationMode();
    }
    WiFi.scanNetworks(true, true);
    _scanning = true;
  }

  int16_t foundDevices = WiFi.scanComplete();
  if (foundDevices > 0) {
    for (int i = 0; i < foundDevices; i++) {
      strncpy(discoveredWiFiNames[i], String(WiFi.SSID(i)).c_str(),
              MAX_WIFI_NAME_LENGTH);
      discoveredWiFiRSSI[i] = WiFi.RSSI(i);
      discoveredWiFiOpen[i] = WiFi.encryptionType(i) == WIFI_AUTH_OPEN;

      DEBUG_PRINTF("Name: %s RSSI: %d Open: %d\n", discoveredWiFiNames[i],
                   discoveredWiFiRSSI[i], discoveredWiFiOpen[i]);
      if (i == MAX_WIFI_DISCOVERABLE) {
        break;
      }
    }
    _scanning = false;
    
    if (foundDevices != _previousFoundDeviceCount) {
      _refreshUI = true;
    } else {
      _refreshUI = false;
    }

    _previousFoundDeviceCount = foundDevices;
    discoveredWiFiCount = foundDevices;
    DEBUG_PRINTF("Refresh: %d-%d :: Found: %d\n", _refreshUI, shouldRefreshUI(),
                 discoveredWiFiCount);
  }

  return foundDevices;
}

bool Network::shouldRefreshUI() { return _refreshUI; }

void Network::setRefreshUI(bool refresh) { _refreshUI = refresh; }

void Network::connect(String ssid, String password) {
  _ssid = (char*)ssid.c_str();
  _password = password.c_str();

  WiFi.disconnect();  // disconnect if it was previously connected
  _isConnected = false;
  _shouldConnect = true;

  WiFi.setHostname(_hostname.c_str());
  WiFi.begin(_ssid, _password);
}

void Network::reconnect() {
  if (_shouldConnect) {
    WiFi.setHostname(_hostname.c_str());
    WiFi.begin(_ssid, _password);
  }
}

void Network::disconnect() { WiFi.disconnect(); }

bool Network::isConnected() { return _isConnected; }

void Network::loop() {
  if (_shouldConnect && !_isConnected) {
    if (millis() - _previousConnectionRetryTime > 5000) {
      _previousConnectionRetryTime = millis();
      reconnect();
    }
  } else if (!_shouldConnect && _isConnected) {
    if (millis() - _previousConnectionRetryTime > 5000) {
      _previousConnectionRetryTime = millis();
      disconnect();
    }
  }

  if (WiFi.status() == WL_CONNECTED && !_isConnected) {
    _isConnected = true;

    _localIPAddress = WiFi.localIP();
    _gatewayIPAddress = WiFi.gatewayIP();
  } else {
    _isConnected = false;
  }

  // scan either when connected or not
  scanAccessPoints();
}

void Network::setShouldConnect(bool shouldConnect) {
  _shouldConnect = shouldConnect;
}

IPAddress Network::getLocalIPAddress() { return _localIPAddress; }

IPAddress Network::getGatewayIPAddress() { return _gatewayIPAddress; }
