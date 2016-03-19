#include "seven_segment.hpp"

const int SHOW_TIME = 400; // milliseconds

SevenSegmentDisplay number_display;

void setup() {
  // the seven segment display is attached with
  // a on 2, b on 3, ... , g on 8 and h on 9
  number_display.attach_to(2,3,4,5,6,7,8,9);
}

void loop() {
  // show all of the numbers one at a time
  for (int i = 0; i <= 9; i++) {
    number_display.show(i);
    delay(SHOW_TIME);
    
    number_display.dot_on();
    delay(SHOW_TIME);
    
    number_display.clear();
    delay(SHOW_TIME);
    
    number_display.dot_off();
    delay(SHOW_TIME);

    // this is how we can show a symbol of our own making
    // this should show an "H"
    const uint8_t H_PATTERN[7] = {0, 1, 1, 0, 1, 1, 1};
    number_display.show_raw(H_PATTERN);
    delay(SHOW_TIME);
  }
}

