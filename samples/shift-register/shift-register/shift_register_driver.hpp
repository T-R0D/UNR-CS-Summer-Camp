/**
 *
 */

#ifndef _SHIFT_REGISTER_DRIVER_HPP_
#define _SHIFT_REGISTER_DRIVER_HPP_ 1

#include <Arduino.h>

class ShiftRegisterDriver {
 public:
  static const uint8_t UNINITIALIZED;
  static const uint8_t SUCCESS;
  static const uint8_t FAILURE;
 
  ShiftRegisterDriver();

  uint8_t attach(uint8_t latch, uint8_t clock, uint8_t data);

  uint8_t clear();
  uint8_t all_on();
  uint8_t shift_in(const uint8_t data_bit);
  uint8_t set_to_array(const uint8_t outputs[8]);
  uint8_t set_to(const int data_byte);
  uint8_t set_to(const uint8_t data_byte);

 private:
  uint8_t _latch;
  uint8_t _clock;
  uint8_t _data;
};

#endif // #ifndef _SHIFT_REGISTER_DRIVER_HPP_
