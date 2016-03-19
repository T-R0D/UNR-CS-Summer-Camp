/**
 * 
 */
 
const int ONBOARD_LED = 13;
const int BUTTON = 7;

void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, LOW);
  
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, LOW);
}

void loop() {
  int reading = digitalRead(BUTTON);
  
  if (reading == HIGH) {
    digitalWrite(ONBOARD_LED, HIGH);
  } else {
    digitalWrite(ONBOARD_LED, LOW);
  }
}

