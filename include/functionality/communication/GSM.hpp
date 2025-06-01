#ifndef GSM_HPP_
#define GSM_HPP_

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <Config.hpp>
#include <Utils.hpp>

class GSM {
private:
  EspSoftwareSerial::UART *_gsmSerial; // TODO: Migrate to HardwareSerial
  bool _responseReady = false, _isRinging = false, _isCallActive = false,
       _isCallAnswered = false, _isCallHungUp = true, _smsSendPending = false;

public:
  GSM() = delete;
  /**
   * @brief Construct a new GSM object
   * @param rx RX pin
   * @param tx TX pin
   * @param baud Baud rate
   */
  GSM(int8_t rx, int8_t tx, uint32_t baud);

  ~GSM();

  /**
   * @brief Initialize the GSM module
   */
  void init() const;

  /**
   * @brief Get the name of the network you are connected to
   * @return Name of the network operator
   */
  String getNetworkOperator() const;

  /**
   * @brief Check the strength of the GSM signal
   * @return Signal strength, a number between `0` and `31`, where 0 means no
   * signal and 31 means the best signal.
   */
  short getSignalStrength() const;

  /**
   * @brief Send an SMS
   * @param number Phone number of the recipient
   * @param message Message
   */
  void sendSMS(const char *number, const char *message) const;

  /**
   * @brief Read SMS message
   * @param index Index of the message
   * @param message Buffer to store the message
   */
  void readSMS(uint8_t index, char *message) const;

  /**
   * @brief Call a number
   * @param number Phone number to call starting with "+"
   */
  void call(const char *number) const;

  /**
   * @brief Answer an incoming call
   */
  void answer() const;

  /**
   * @brief Hang up a call
   */
  void hangup() const;

private:
  /**
   * @brief Process the response from the GSM module
   * @param res Buffer to store the response
   * @param resSize Size of the response buffer
   */
  void _processResponse(char *res, unsigned int resSize) const;

  /**
   * @brief Send a command to the GSM module
   * @param command Command to send
   */
  void _sendCommand(const char *command) const;

  /**
   * @brief Send a command to the GSM module
   * @param value Command to send
   */
  void _sendCommandW(int value) const;

  /**
   * @brief Send a command to the GSM module
   * @param command Command to send
   */
  void _sendCommandLn(const char *command) const;

  /**
   * @brief Send a command to the GSM module
   * @param value Command to send
   */
  void _sendCommandLn(int value) const;
  /**
   * @brief Send a command to the GSM module
   * @param command1 Command to send
   * @param command2 Command to send
   */
  void _sendCommandLn(const char *command1, const char *command2) const;

  /**
   * @brief Send a command to the GSM module
   * @param command1 Command to send
   * @param command2 Command to send
   * @param command3 Command to send
   */
  void _sendCommandLn(const char *command1, const char *command2,
                      const char *command3) const;
};

#endif // GSM_HPP_
