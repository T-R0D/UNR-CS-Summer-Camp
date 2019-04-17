#include "joystick.hpp"

Joystick::Joystick() {
  x_pin_ = A0;
  y_pin_ = A0;
  z_pin_ = A0;
  tolerance_ = 25;
  neutral_value_ = 1024 / 2;
}

void Joystick::init(uint8_t x_pin, uint8_t y_pin, uint8_t z_pin) {
  x_pin_ = x_pin;
  y_pin_ = y_pin;
  z_pin_ = z_pin;
  pinMode(z_pin_, INPUT);
}

Joystick::Position Joystick::get_position() const {
  int16_t x = get_x();
  int16_t y = get_y();
  return get_position_(x, y);
}

void Joystick::set_tolerance(uint16_t tolerance) {
  tolerance_ = tolerance_;
}

void Joystick::set_neutral_value(uint16_t neutral_value) {
  neutral_value_ = neutral_value;
}

bool Joystick::get_button_pressed() const {
  return get_z() == 0;
}

int16_t Joystick::get_x() const {
  return analogRead(x_pin_) - neutral_value_;
}

int16_t Joystick::get_y() const {
  return analogRead(y_pin_) - neutral_value_;
}

int16_t Joystick::get_z() const {
  return analogRead(z_pin_);
}

double Joystick::get_hypotenuse_(int16_t x, int16_t y) const {
  return sqrt(square((double) x) + square((double) y));
}

Joystick::Position Joystick::get_position_(int16_t x, int16_t y) const {
  bool x_is_neutral = -this->tolerance_ < x && x < this->tolerance_;
  bool y_is_neutral = -this->tolerance_ < y && y < this->tolerance_;
  if (x_is_neutral && y_is_neutral) {
    return NEUTRAL;
  } else if (x_is_neutral) {
    return y > 0 ? SOUTH : NORTH;
  } else if (y_is_neutral) {
    return x > 0 ? EAST : WEST;
  }

  double hypotenuse = get_hypotenuse_(x, y);
  double angle = acos((double) x / hypotenuse);
  if (y > 0) {
    if (angle < PI_OVER_EIGHT) {
      return EAST;
    } else if (angle < THREE_PI_OVER_EIGHT) {
      return SOUTHEAST;
    } else if (angle < FIVE_PI_OVER_EIGHT) {
      return SOUTH;
    } else if (angle < SEVEN_PI_OVER_EIGHT) {
      return SOUTHWEST;
    } else {
      return WEST;
    }
  } else { // y < 0
    if (angle < PI_OVER_EIGHT) {
      return EAST;
    } else if (angle < THREE_PI_OVER_EIGHT) {
      return NORTHEAST;
    } else if (angle < FIVE_PI_OVER_EIGHT) {
      return NORTH;
    } else if (angle < SEVEN_PI_OVER_EIGHT) {
      return NORTHWEST;
    } else {
      return WEST;
    }
  }
}
