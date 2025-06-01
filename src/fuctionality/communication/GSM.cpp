#include <functionality/communication/GSM.hpp>

GSM::GSM(const int8_t rx, const int8_t tx, const uint32_t baud) {
  _gsmSerial = new EspSoftwareSerial::UART(rx, tx);
  _gsmSerial->begin(baud);
}

GSM::~GSM() { delete _gsmSerial; }

void GSM::init() const {
  // Send AT command to check if the GSM module is connected
  _sendCommandLn("AT");
  delay(100);
  _processResponse(nullptr, 0);

  // Check network signal strength
  _sendCommandLn("AT+CSQ");
  delay(100);
  _processResponse(nullptr, 0);

  // Check if the SIM card is inserted
  _sendCommandLn("AT+CPIN?");
  delay(100);
  _processResponse(nullptr, 0);

  // Check if the SIM card is ready
  _sendCommandLn("AT+CREG?");
  delay(100);
  _processResponse(nullptr, 0);

  // Read network operator
  _sendCommandLn("AT+COPS?");
  delay(100);
  _processResponse(nullptr, 0);

  // Read SIM information
  _sendCommandLn("AT+CCID");
  delay(100);
  _processResponse(nullptr, 0);

  // Set SMS mode to text
  _sendCommandLn("AT+CMGF=1");
  delay(100);
  _processResponse(nullptr, 0);

  // Set SMS storage to SIM
  _sendCommandLn(R"(AT+CPMS="SM","SM","SM")");
  delay(100);
  _processResponse(nullptr, 0);

  // configure SMS to notify the MCU when a new SMS is received
  _sendCommandLn("AT+CNMI=2,2,0,0,0");
  delay(100);
  _processResponse(nullptr, 0);

  // Set the GSM module to send the caller ID when ringing
  _sendCommandLn("AT+CLIP=1");
  delay(100);
  _processResponse(nullptr, 0);

  DEBUG_PRINTLN("GSM module initialized");
}

String GSM::getNetworkOperator() const {
  _sendCommandLn("AT+COPS?");
  delay(100);
  _processResponse(nullptr, 0);

  // The response will be something like: "+COPS: <mode>,<format>,<oper>,<stat>"
  // where <oper> is the network operator name
  String response = "";
  while (_gsmSerial->available()) {
    response += static_cast<char>(_gsmSerial->read());
  }

  const int startIndex = response.indexOf("\"") + 1;
  const int endIndex = response.indexOf("\"", startIndex);
  return response.substring(startIndex, endIndex);
}

short

GSM::getSignalStrength() const {
  _sendCommandLn("AT+CSQ");
  delay(100);
  _processResponse(nullptr, 0);

  // The response will be something like: "+CSQ: <rssi>,<ber>"
  // where <rssi> is the signal strength in dBm
  String response = "";
  while (_gsmSerial->available()) {
    response += static_cast<char>(_gsmSerial->read());
  }

  const int startIndex = response.indexOf(":") + 1;
  const int endIndex = response.indexOf(",");
  const String rssiStr = response.substring(startIndex, endIndex);
  return static_cast<short>(rssiStr.toInt());
}

void GSM::sendSMS(const char *number, const char *message) const {
  _sendCommand("AT+CMGS=\"");
  _sendCommand(number);
  _sendCommandLn("\"");
  delay(100);
  _processResponse(nullptr, 0);

  _sendCommand(message);
  _sendCommandW(0x1A);  // End of message character (Ctrl+Z) / ASCII code 26
  delay(100);
  _processResponse(nullptr, 0);
}

void GSM::call(const char *number) const {
  _sendCommand("ATD");  // ATD+<number>; eg. ATD+1234567890;
  _sendCommand(number);
  _sendCommandLn(";");
  delay(100);
  _processResponse(nullptr, 0);
}

void GSM::answer() const {
  _sendCommandLn("ATA");
  delay(100);
  _processResponse(nullptr, 0);
}

void GSM::hangup() const {
  _sendCommandLn("ATH");
  delay(100);
  _processResponse(nullptr, 0);
}

// ============================================================================
void GSM::_processResponse(char *res, const unsigned int resSize) const {
  String response = "";

  while (_gsmSerial->available()) {
    response += static_cast<char>(_gsmSerial->read());
  }
  DEBUG_PRINTF("Response: %s\n", response.c_str());

  // put the response to the provided buffer
  if (res != nullptr) {
    response.toCharArray(res, resSize);  // Assuming res has enough space
  }
}

void GSM::_sendCommand(const char *command) const {
  _gsmSerial->print(command);
}

void GSM::_sendCommandW(const int value) const { _gsmSerial->write(value); }

void GSM::_sendCommandLn(const char *command) const {
  _gsmSerial->println(command);
}

void GSM::_sendCommandLn(const int value) const { _gsmSerial->println(value); }

void GSM::_sendCommandLn(const char *command1, const char *command2) const {
  _gsmSerial->print(command1);
  _gsmSerial->println(command2);
}

void GSM::_sendCommandLn(const char *command1, const char *command2,
                         const char *command3) const {
  _gsmSerial->print(command1);
  _gsmSerial->print(command2);
  _gsmSerial->println(command3);
}

void GSM::readSMS(uint8_t index, char *message) const {
  _sendCommand("AT+CMGR=");
  _sendCommandLn(index);
  delay(100);
  // TODO: Assuming message buffer is 256 bytes. Change this
  _processResponse(message, 256);
}
