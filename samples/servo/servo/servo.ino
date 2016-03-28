/**
 * 
 */

#include <Servo.h>

const int SERVO_SIGNAL_PIN = 10;

const int LOW_ = 45;
const int MEDIUM = 90;
const int HIGH_ = 135;

const int PAUSE_TIME = 500; // milliseconds

Servo servo;

void setup() {
  servo.attach(SERVO_SIGNAL_PIN);
}

void loop() {
  // we can set the servo to turn to predetermined
  // positions...
  servo.write(LOW_);
  delay(PAUSE_TIME);

  servo.write(MEDIUM);
  delay(PAUSE_TIME);
  
  servo.write(HIGH_);
  delay(PAUSE_TIME);

  // ... or with loops we can gradually move it along an arc
  for (int angle = 180; angle >= 0; angle -= 5) {
    servo.write(angle);
    delay(5);
  }
  delay(PAUSE_TIME * 4);
}
