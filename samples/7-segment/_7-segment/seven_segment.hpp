/**
 *
 */

#include <Arduino.h>

class SevenSegmentDisplay {
 public:
  static const uint8_t N_SEGMENTS = 7;
  static const uint8_t N_DIGITS = 10;

  SevenSegmentDisplay();

  uint8_t attach_to(const uint8_t a, const uint8_t b, const uint8_t c,
                    const uint8_t d, const uint8_t e, const uint8_t f,
                    const uint8_t g, const uint8_t h);
  uint8_t attach(const uint8_t pins[N_SEGMENTS + 1]);

  uint8_t clear();
  uint8_t show(const uint8_t n);
  uint8_t show_raw(const uint8_t segments[N_SEGMENTS]);
  uint8_t dot_on();
  uint8_t dot_off();
 
 private:
  const uint8_t _layouts[N_DIGITS][N_SEGMENTS] = {
  // a  b  c  d  e  f  g
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
  // a  b  c  d  e  f  g
  };

  uint8_t _pins[N_SEGMENTS];
  uint8_t _dot_pin;
};
