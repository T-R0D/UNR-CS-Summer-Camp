#include "shift_register_driver.hpp"

int SR_LATCH_PIN = 5;
int SR_CLOCK_PIN = 6;
int SR_DATA_PIN = 4;
const int SHOW_TIME = 1000; // milliseconds

ShiftRegisterDriver shift_register;

void setup() {
  // bind our shift_register variable to the pins it should use
  shift_register.attach(SR_LATCH_PIN, SR_CLOCK_PIN, SR_DATA_PIN);
}
 
void loop() {

  // we can turn on the shift register's outputs on all at once...
  shift_register.all_on();
  delay(SHOW_TIME);

  // ... or turn them all off at once
  shift_register.clear();
  delay(SHOW_TIME);

  // this will shift in 8 bits one-at-a-time
  for (int i = 0; i < 8; i++) {
    // if i is  odd, we send a LOW...
    int data_value = LOW;
    
    // ...but, if i is even, send a HIGH
    if (i % 2 == 0) {
      data_value = HIGH;
    }

    shift_register.shift_in(data_value);
    delay(SHOW_TIME / 3);
  }
  
  shift_register.clear();
  delay(SHOW_TIME);

  // send an array of 8 values to the shift register
  // to set the pins with a given pattern
  const byte SOME_PATTERN_ARRAY[8] =
      {LOW, LOW, HIGH, HIGH, LOW, LOW, LOW, LOW};
  shift_register.set_to_array(SOME_PATTERN_ARRAY);
  delay(SHOW_TIME);

  shift_register.clear();
  delay(SHOW_TIME);

  // ...or send a single number written in binary (same thing!)
  const int SOME_PATTERN_NUMBER = 0b00110000;
  shift_register.set_to(SOME_PATTERN_NUMBER);
  delay(SHOW_TIME);

  shift_register.clear();
  delay(SHOW_TIME);
}

