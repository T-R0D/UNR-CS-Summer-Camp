/**
 *  
 */

#include "shift_register_driver.hpp"


const uint8_t ShiftRegisterDriver::UNINITIALIZED = 0;
const uint8_t ShiftRegisterDriver::SUCCESS = 0;
const uint8_t ShiftRegisterDriver::FAILURE = 1;

ShiftRegisterDriver::ShiftRegisterDriver() {
  this->_latch = 0;
  this->_clock = 0;
  this->_data = 0;
}


uint8_t ShiftRegisterDriver::attach(
    uint8_t latch, uint8_t clock, uint8_t data) {
      
  this->_latch = latch;
  this->_clock = clock;
  this->_data = data;

  pinMode(this->_latch, OUTPUT);
  pinMode(this->_clock, OUTPUT);
  pinMode(this->_data, OUTPUT);

  digitalWrite(this->_latch, HIGH);
  digitalWrite(this->_clock, LOW);
  digitalWrite(this->_data, LOW);

  return SUCCESS;
}


uint8_t ShiftRegisterDriver::clear() {
  // there is an SRCLEAR (active low) pin that can do this, but
  // this way we use fewer Arduino pins
  return this->set_to(0b00000000);
}


uint8_t ShiftRegisterDriver::all_on() {
  return this->set_to(0b11111111);
}


uint8_t ShiftRegisterDriver::shift_in(const uint8_t data_bit) {
  digitalWrite(this->_latch, LOW);  
  digitalWrite(this->_data, data_bit);
  digitalWrite(this->_clock, HIGH);  
  digitalWrite(this->_clock, LOW);
  digitalWrite(this->_latch, HIGH);
  return SUCCESS;
}


uint8_t ShiftRegisterDriver::set_to_array(const uint8_t outputs[8]) {
  this->clear();
  digitalWrite(this->_latch, LOW);
  for (int i = 7; i >= 0; i--) {  
    digitalWrite(this->_data, outputs[i]);
    digitalWrite(this->_clock, HIGH);  
    digitalWrite(this->_clock, LOW);
  }
  digitalWrite(this->_latch, HIGH);
  return SUCCESS;
}


uint8_t ShiftRegisterDriver::set_to(const int data) {
  uint8_t data_byte = data & 0xFF;
  this->set_to(data_byte);
  return SUCCESS;
}


uint8_t ShiftRegisterDriver::set_to(const uint8_t data_byte) {
  digitalWrite(this->_latch, LOW); 
  shiftOut(this->_data, this->_clock, LSBFIRST, (byte) data_byte);
  digitalWrite(this->_latch, HIGH);
  return SUCCESS;
}
