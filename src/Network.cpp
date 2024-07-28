#include <Network.hpp>

Network::Network(char* ssid, const char* password)
    : _ssid(ssid),
      _password(password),
      _previousConnectionRetryTime(0),
      _isConnected(false) {}

void Network::connect() { WiFi.begin(_ssid, _password); }

void Network::disconnect() { WiFi.disconnect(); }

bool Network::isConnected() { return _isConnected; }

void Network::loop() {
  if (_shouldConnect && !_isConnected) {
    if (millis() - _previousConnectionRetryTime > 5000) {
      _previousConnectionRetryTime = millis();
      connect();
    }
  } else if (!_shouldConnect && _isConnected) {
    if (millis() - _previousConnectionRetryTime > 5000) {
      _previousConnectionRetryTime = millis();
      disconnect();
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    _isConnected = true;

    _localIPAddress = WiFi.localIP();
    _gatewayIPAddress = WiFi.gatewayIP();
  } else {
    _isConnected = false;
  }
}

void Network::setShouldConnect(bool shouldConnect) {
  _shouldConnect = shouldConnect;
}

IPAddress Network::getLocalIPAddress() { return _localIPAddress; }

IPAddress Network::getGatewayIPAddress() { return _gatewayIPAddress; }
