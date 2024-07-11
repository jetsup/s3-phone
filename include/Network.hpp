#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <Arduino.h>
#include <IPAddress.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class Network {
 private:
  IPAddress _localIPAddress;
  IPAddress _gatewayIPAddress;
  char* _ssid;
  const char* _password;
  long _previousConnectionRetryTime;
  bool _isConnected;
  bool _shouldConnect;  // whether the user wants to connect to the network

 public:
  Network() = delete;

  /**
   * @brief Construct a new Network object
   *
   * @param ssid The SSID of the network to connect to
   * @param password The password of the network to connect to
   */
  Network(char* ssid, const char* password);

  /**
   * @brief Initialize the network connection and connect to the network
   */
  void connect();

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