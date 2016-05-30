#define LED 2

void setup() {
  // Configure the pin to drive the LED.
  pinMode(LED, OUTPUT);
}

void loop() {
  // Turn the LED on.
  digitalWrite(LED, HIGH);

  // Leave the LED on for 1 second.
  delay(1000);

  // Turn the LED off.
  digitalWrite(LED, LOW);

  // Leave the LED off for half a second.
  delay(500);
}

