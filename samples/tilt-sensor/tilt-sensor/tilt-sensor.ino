/**
 * 
 */

#define TILT_SENSOR   2
#define ONBOARD_LED  13

void setup() {
  pinMode(TILT_SENSOR, INPUT);
}

void loop() {
  int reading = digitalRead(TILT_SENSOR);

  if (reading == HIGH) {
    digitalWrite(ONBOARD_LED, HIGH);
  } else {
    digitalWrite(ONBOARD_LED, LOW);
  }

  delay(100);
}
