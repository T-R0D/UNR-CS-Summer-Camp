/**
 *
 */

#include "seven_segment.hpp"

SevenSegmentDisplay::SevenSegmentDisplay() {
}


uint8_t SevenSegmentDisplay::attach_to(const uint8_t a, const uint8_t b,
                                       const uint8_t c, const uint8_t d,
                                       const uint8_t e, const uint8_t f,
                                       const uint8_t g, const uint8_t h) {
  this->_pins[0] = a;
  this->_pins[1] = b;
  this->_pins[2] = c;
  this->_pins[3] = d;
  this->_pins[4] = e;
  this->_pins[5] = f;
  this->_pins[6] = g;
  this->_dot_pin = h;

  for (int i = 0; i < N_SEGMENTS; i++) {
    pinMode(this->_pins[i], OUTPUT);
  }
  pinMode(this->_dot_pin, OUTPUT);
}

uint8_t SevenSegmentDisplay::attach(const uint8_t pins[N_SEGMENTS + 1]) {
  for (int i = 0; i < N_SEGMENTS; i++) {
    this->_pins[i] = _pins[i];
  }
  this->_dot_pin = pins[N_SEGMENTS];
}

uint8_t SevenSegmentDisplay::clear() {
  for (int i = 0; i < N_SEGMENTS; i++) {
    digitalWrite(this->_pins[i], LOW);
  }

  return 0;
}


uint8_t SevenSegmentDisplay::show(const uint8_t n) {
  for (int i = 0; i < N_SEGMENTS; i++) {
    digitalWrite(this->_pins[i], _layouts[n][i]);
  }

  return 0;
}

uint8_t SevenSegmentDisplay::show_raw(const uint8_t segments[N_SEGMENTS]) {
  for (int i = 0; i < N_SEGMENTS; i++) {
    digitalWrite(this->_pins[i], segments[i]);
  }

  return 0;
}

uint8_t SevenSegmentDisplay::dot_on() {
  digitalWrite(this->_dot_pin, HIGH);
  return 0;
}


uint8_t SevenSegmentDisplay::dot_off() {
  digitalWrite(this->_dot_pin, LOW);
  return 0;
}

