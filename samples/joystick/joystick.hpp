/**
 * Interface for a joystick "controller".
 */
#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP

#include <Arduino.h>
#include <math.h>

class Joystick {
 public:
  enum Position {
    EAST,
    NEUTRAL,
    NORTH,
    NORTHEAST,
    NORTHWEST,
    SOUTH,
    SOUTHEAST,
    SOUTHWEST,
    WEST
  };

  Joystick();
  void init(uint8_t x_pin, uint8_t y_pin, uint8_t z_pin);
  void set_tolerance(uint16_t tolerance);
  void set_neutral_value(uint16_t neutral_value);
  Position get_position() const;
  bool get_button_pressed() const;
  int16_t get_x() const;
  int16_t get_y() const;
  int16_t get_z() const;

 private:
  const double PI_OVER_EIGHT = 0.392699;
  const double THREE_PI_OVER_EIGHT = 1.178097;
  const double FIVE_PI_OVER_EIGHT = 1.963495;
  const double SEVEN_PI_OVER_EIGHT = 2.748893;

  double get_hypotenuse_(int16_t x, int16_t y) const;
  Position get_position_(int16_t x, int16_t y) const;

  uint8_t x_pin_;
  uint8_t y_pin_;
  uint8_t z_pin_;
  int16_t tolerance_; // The default innaccuracy of the joystick.
  int16_t neutral_value_; // The value the joystick should provide in the
                          // "neutral" position.
};

#endif // JOYSTICK_HPP
