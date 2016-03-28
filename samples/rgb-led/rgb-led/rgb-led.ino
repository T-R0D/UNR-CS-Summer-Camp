/**
 * 
 */

const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

const int SHOW_TIME = 500; // milliseconds

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // by using combinations of red, green, and blue we can
  // make many different colors
  
  set_rgb_led(255, 0, 0); // red
  delay(SHOW_TIME); 

  set_rgb_led(0, 255, 0); // green
  delay(SHOW_TIME);

  set_rgb_led(0, 0, 255); // blue
  delay(SHOW_TIME);

  set_rgb_led(255, 255, 0); // red + green = yellow
  delay(SHOW_TIME);

  set_rgb_led(80, 0, 80); // red + blue = purple
  delay(SHOW_TIME);

  set_rgb_led(0, 255, 255); // green + blue = aqua
  delay(SHOW_TIME);

  set_rgb_led(0, 0, 0); // off
  delay(SHOW_TIME);

  // try to make your own colors too!
}

// using a function can make our code more readable
// and help us write fewer lines to do the same thing
int set_rgb_led(int r_val, int g_val, int b_val) {
  analogWrite(RED, r_val);
  analogWrite(GREEN, g_val);
  analogWrite(BLUE, b_val);
  return 0;
}

