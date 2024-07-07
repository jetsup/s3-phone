#ifndef GSM_HPP_
#define GSM_HPP_

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <Config.hpp>
#include <Utils.hpp>

class GSM {
 private:
  EspSoftwareSerial::UART *_gsmSerial;
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
  GSM(uint8_t rx, uint8_t tx, uint32_t baud);

  ~GSM();

  /**
   * @brief Initialize the GSM module
   */
  void init();

  /**
   * @brief Send an SMS
   * @param number Phone number of the recipient
   * @param message Message
   */
  void sendSMS(const char *number, const char *message);

  /**
   * @brief Read SMS message
   * @param index Index of the message
   * @param message Buffer to store the message
   */
  void readSMS(uint8_t index, char *message);

  /**
   * @brief Call a number
   * @param number Phone number to call
   */
  void call(const char *number);

  /**
   * @brief Answer an incoming call
   */
  void answer();

  /**
   * @brief Hang up a call
   */
  void hangup();

 private:
  /**
   * @brief Process the response from the GSM module
   */
  void _processResponse();

  /**
   * @brief Send a command to the GSM module
   * @param command Command to send
   */
  void _sendCommand(const char *command);

  /**
   * @brief Send a command to the GSM module
   * @param command Command to send
   */
  void _sendCommandW(const int value);

  /**
   * @brief Send a command to the GSM module
   * @param command Command to send
   */
  void _sendCommandLn(const char *command);

  /**
   * @brief Send a command to the GSM module
   * @param value Command to send
   */
  void _sendCommandLn(const int value);
  /**
   * @brief Send a command to the GSM module
   * @param command1 Command to send
   * @param command2 Command to send
   */
  void _sendCommandLn(const char *command1, const char *command2);

  /**
   * @brief Send a command to the GSM module
   * @param command1 Command to send
   * @param command2 Command to send
   * @param command3 Command to send
   */
  void _sendCommandLn(const char *command1, const char *command2,
                      const char *command3);
};

#endif  // GSM_HPP_