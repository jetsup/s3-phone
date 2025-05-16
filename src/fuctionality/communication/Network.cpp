#include <functionality/communication/Network.hpp>
#include <utility>

Network::Network(String hostname)
    : _previousConnectionRetryTime(0), _isConnected(false),
      _shouldConnect(false), _previousFoundDeviceCount(0), _hostname(std::move(hostname)) {
  // setup mDNS
  mdns_init();
  mdns_hostname_set(_hostname.c_str());
  mdns_instance_name_set(_hostname.c_str());
}

Network::~Network() {
  //
}

void Network::enableStationMode() {
  WiFiClass::mode(WIFI_STA);
  _isStation = true;
}

void Network::enableAccessPionMode() {
  WiFiClass::mode(WIFI_AP);
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

  const int16_t foundDevices = WiFi.scanComplete();
  if (foundDevices > 0) {
    for (int i = 0; i < foundDevices; i++) {
      strncpy(discoveredWiFiNames[i], String(WiFi.SSID(i)).c_str(),
              MAX_WIFI_NAME_LENGTH);
      discoveredWiFiRSSI[i] = WiFi.RSSI(i);
      discoveredWiFiChannel[i] = WiFi.channel(i);
      discoveredWiFiOpen[i] = WiFi.encryptionType(i) == WIFI_AUTH_OPEN;

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
  }

  return foundDevices;
}

bool Network::shouldRefreshUI() const { return _refreshUI; }

void Network::setRefreshUI(const bool refresh) { _refreshUI = refresh; }

void Network::setHostname(const String &hostname) { _hostname = hostname; }

void Network::connect(const String &ssid, const String &password) {
  if (_ssid != ssid || _password != password) {
    _ssid = ssid;
    _password = password;

    WiFi.disconnect(); // disconnect if it was previously connected
    _isConnected = false;
    _shouldConnect = true;

    WiFi.begin(_ssid, _password);
  }
}

String Network::getPassword() {
  if (_isConnected) {
    return _password;
  }
  return {};
}

String Network::getSSID() {
  if (_isConnected) {
    return _ssid;
  }
  return {};
}

bool Network::credentialsSaved() const { return _credentialsSaved; }

void Network::setCredentialsSaved(const bool saved) {
  _credentialsSaved = saved;
}

void Network::reconnect() const {
  if (_shouldConnect) {
    WiFi.begin(_ssid, _password);

    DEBUG_PRINTF("Reconnecting to '%s'::'%s'\n", _ssid.c_str(),
                 _password.c_str());
  }
}

void Network::disconnect() {
  WiFi.disconnect();
  _credentialsSaved = false;
}
bool Network::hasInternet() const { return _hasInternet; }

bool Network::isConnected() const { return _isConnected; }

bool Network::shouldConnect() const { return _shouldConnect; }

void Network::loop() {
  if (_shouldConnect && !_isConnected) {
    if (millis() - _previousConnectionRetryTime > S3WIFI_RECONNECT_TIMEOUT) {
      _previousConnectionRetryTime = millis();
      reconnect();
    }
  } else if (!_shouldConnect && _isConnected) {
    if (millis() - _previousConnectionRetryTime > S3WIFI_RECONNECT_TIMEOUT) {
      _previousConnectionRetryTime = millis();
      disconnect();
    }
  }

  if (WiFiClass::status() == WL_CONNECTED && !_isConnected) {
    _isConnected = true;

    _localIPAddress = WiFi.localIP();
    _gatewayIPAddress = WiFi.gatewayIP();

    DEBUG_PRINTF(">>> IP: %s GIP: %s <<<\n", _localIPAddress.toString().c_str(),
                 _gatewayIPAddress.toString().c_str());
  }

  if (WiFiClass::status() != WL_CONNECTED) {
    _isConnected = false;
  }

  // scan either when connected or not
  scanAccessPoints();
}

void Network::setShouldConnect(const bool shouldConnect) {
  _shouldConnect = shouldConnect;
}

IPAddress Network::getLocalIPAddress() { return _localIPAddress; }

IPAddress Network::getGatewayIPAddress() { return _gatewayIPAddress; }
