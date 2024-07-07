#include <GSM.hpp>

GSM::GSM(uint8_t rx, uint8_t tx, uint32_t baud) {
  _gsmSerial = new EspSoftwareSerial::UART(rx, tx);
  _gsmSerial->begin(baud);
}

GSM::~GSM() { delete _gsmSerial; }

void GSM::init() {
  // Send AT command to check if the GSM module is connected
  _sendCommandLn("AT");
  delay(100);
  _processResponse();

  // Check network signal strength
  _sendCommandLn("AT+CSQ");
  delay(100);
  _processResponse();

  // Check if the SIM card is inserted
  _sendCommandLn("AT+CPIN?");
  delay(100);
  _processResponse();

  // Check if the SIM card is ready
  _sendCommandLn("AT+CREG?");
  delay(100);
  _processResponse();

  // Read network operator
  _sendCommandLn("AT+COPS?");
  delay(100);
  _processResponse();

  // Read SIM information
  _sendCommandLn("AT+CCID");
  delay(100);
  _processResponse();

  // Set SMS mode to text
  _sendCommandLn("AT+CMGF=1");
  delay(100);
  _processResponse();

  // Set SMS storage to SIM
  _sendCommandLn("AT+CPMS=\"SM\",\"SM\",\"SM\"");
  delay(100);
  _processResponse();

  // configure SMS to notify the MCU when a new SMS is received
  _sendCommandLn("AT+CNMI=2,2,0,0,0");
  delay(100);
  _processResponse();

  // Set the GSM module to send the caller ID when ringing
  _sendCommandLn("AT+CLIP=1");
  delay(100);
  _processResponse();

  DEBUG_PRINTLN("GSM module initialized");
}

void GSM::sendSMS(const char *number, const char *message) {
  _sendCommand("AT+CMGS=\"");
  _sendCommand(number);
  _sendCommandLn("\"");
  delay(100);
  _processResponse();

  _sendCommand(message);
  _sendCommandW(0x1A);  // End of message character (Ctrl+Z) / ASCII code 26
  delay(100);
  _processResponse();
}

void GSM::call(const char *number) {
  _sendCommand("ATD");  // ATD+<number>; eg. ATD+1234567890;
  _sendCommand(number);
  _sendCommandLn(";");
  delay(100);
  _processResponse();
}

void GSM::answer() {
  _sendCommandLn("ATA");
  delay(100);
  _processResponse();
}

void GSM::hangup() {
  _sendCommandLn("ATH");
  delay(100);
  _processResponse();
}

// ============================================================================
void GSM::_processResponse() {
  String response = "";

  while (_gsmSerial->available()) {
    response += (char)_gsmSerial->read();
  }
  DEBUG_PRINTF("Response: %s\n", response.c_str());
}

void GSM::_sendCommand(const char *command) { _gsmSerial->print(command); }

void GSM::_sendCommandW(const int value) { _gsmSerial->write(value); }

void GSM::_sendCommandLn(const char *command) { _gsmSerial->println(command); }

void GSM::_sendCommandLn(const int value) { _gsmSerial->println(value); }

void GSM::_sendCommandLn(const char *command1, const char *command2) {
  _gsmSerial->print(command1);
  _gsmSerial->println(command2);
}

void GSM::_sendCommandLn(const char *command1, const char *command2,
                         const char *command3) {
  _gsmSerial->print(command1);
  _gsmSerial->print(command2);
  _gsmSerial->println(command3);
}

void GSM::readSMS(uint8_t index, char *message) {
  _sendCommand("AT+CMGR=");
  _sendCommandLn(index);
  delay(100);
  _processResponse();
}
