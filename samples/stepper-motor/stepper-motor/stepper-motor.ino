/**
 *
 */

#include "BYJ48_Stepper.h"

#define IN1   8
#define IN2   9
#define IN3  10
#define IN4  11

#define SEPARATION_TIME 2000 // milliseconds

BYJ48_Stepper g_stepper(IN1, IN2, IN3, IN4);

void setup() {
  // Setup for the motor is done in the controller object.

  // The motor starts with a direction of clockwise and speed
  // of 1 RPM. We can make it turn a specified number of
  // revolutions. This takes a while, so this code is in
  // setup to only run once.
  g_stepper.turn(1.0);
  delay(SEPARATION_TIME);
}

void loop() {
  // The motor can be set to turn the other direction, and turn
  // faster. We can use a float number for the speed like "5.4",
  // which is 5.4 rpm.
  g_stepper.set_counter_clockwise();
  g_stepper.set_speed(5.4);
  g_stepper.turn(1.0);
  delay(SEPARATION_TIME);

  // We can set the speed to any number between 0.5 and 17.3.
  // If you don't want to remember that, you can always use the
  // constants BYJ48_Stepper::MIN_RPM and
  // BYJ48_Stepper::MAX_RPM.
  // If we want more precision, we can also specify a numer of
  // steps for the motor to turn.
  g_stepper.set_clockwise();
  g_stepper.set_speed(BYJ48_Stepper::MAX_RPM);
  g_stepper.step(256);
  delay(SEPARATION_TIME);

  g_stepper.turn(1.0);
  delay(250);
  
  g_stepper.turn(1.0);
  delay(250);
  
  g_stepper.turn(1.0);
  delay(SEPARATION_TIME);
}

