#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <Arduino.h>
#include <IPAddress.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiGeneric.h>
#include <WiFiUdp.h>
#include <ui_utils.h>

#include <Utils.hpp>

class Network {
 private:
  IPAddress _localIPAddress;
  IPAddress _gatewayIPAddress;
  char* _ssid;
  const char* _password;
  long _previousConnectionRetryTime;
  int8_t _previousFoundDeviceCount;
  bool _isConnected;
  bool _shouldConnect;  // whether the user wants to connect to the network
  bool _isStation;
  bool _isAccessPoint;
  bool _refreshUI = false;

 public:
  /**
   * @brief Construct a new Network object
   */
  Network();

  /**
   * @brief Configure the device as a client to a WiFi
   */
  void enableStationMode();

  /**
   * @brief Configure the devise as an access point
   */
  void enableAccessPionMode();

  /**
   * @brief Scan for available WiFi networks
   * @return The number of networks found. If the number is not `0`, the
   * networks array are populated.
   */
  uint8_t scanAccessPoints();

  /**
   * @brief WiFi detected changed and should refresh the UI
   */
  bool shouldRefreshUI();

  /**
   * @brief Update the variable for refreshing UI
   */
  void setRefreshUI(bool refresh);

  /**
   * @brief Initialize the network connection and connect to the network
   * @param ssid The network to connect to
   * @param password The password of the network to connect to
   */
  void connect(String ssid, String password = "");

  /**
   * @brief Try to connect to the network with the previously entered
   * credentials
   */
  void reconnect();

  /**
   * @brief Disconnect from the network
   */
  void disconnect();

  /**
   * @brief Loop function to be called in the main loop
   */
  void loop();

  /**
   * @brief Check if the device is connected to the network
   *
   * @return true if the device is connected to the network
   * @return false if the device is not connected to the network
   */
  bool isConnected();

  /**
   * @brief Set whether the device should connect to the network
   *
   * @param shouldConnect `true` if the device should connect to the network
   * `false` if the device should disconnect from the network
   */
  void setShouldConnect(bool shouldConnect);

  /**
   * @brief Get the local IP address of the device
   *
   * @return IPAddress The local IP address of the device
   */
  IPAddress getLocalIPAddress();

  /**
   * @brief Get the gateway IP address of the device
   *
   * @return IPAddress The gateway IP address of the device
   */
  IPAddress getGatewayIPAddress();
};

#endif  // NETWORK_HPP_
