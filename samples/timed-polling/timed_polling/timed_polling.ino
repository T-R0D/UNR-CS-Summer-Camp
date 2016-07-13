/**
 * This sketch demonstrates how to do a timed poll of a sensor. 
 * 
 * Try this code out to see what happens. Then swap out the
 * polling function call for the interruptible one and
 * see how that affects things.
 * 
 * Using the built-in millis() function, we can write loops that
 * allow us to have the Arduino do some "busy" waiting. By
 * wrapping things in a function, we can really write some
 * flexible, clean, reusable code. Keep in mind, it is possible
 * to read analog sensors too quickly, which is why we use a
 * short delay time (in this example SENSOR_COOLDOWN).
 */

#define BUTTON  8

#define DEFAULT_POLL_TIME   2000 // milliseconds
#define SENSOR_COOLDOWN        5 // milliseconds

void setup() {
  Serial.begin(9600);
}

void loop() {
  bool button_pressed = false;

  button_pressed = poll_button(DEFAULT_POLL_TIME);

  if (button_pressed) {
    Serial.println("The button was pressed!");
  } else {
    Serial.println("The button was not pressed!");
  }

  delay(1000);
  Serial.println("Let's try again!");
}

int poll_button(unsigned long poll_time) {
  int button_pressed = false;
  unsigned long poll_stop_time = millis() + poll_time;

  while (millis() < poll_stop_time) {
    if (!button_pressed) {
      button_pressed = digitalRead(BUTTON);
    }
    delay(SENSOR_COOLDOWN);
  }

  return button_pressed;
}

int interruptible_poll_button(unsigned long max_poll_time) {
  int button_pressed = false;
  unsigned long poll_stop_time = millis() + max_poll_time;

  while (millis() < poll_stop_time) {
    button_pressed = digitalRead(BUTTON);
    delay(SENSOR_COOLDOWN);

    if (button_pressed) {
      return button_pressed;
    }
  }

  return button_pressed;
}

