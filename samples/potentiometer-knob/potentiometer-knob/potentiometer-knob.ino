/**
 * 
 */

const int KNOB = A0;

const int WEAK = 50;
const int MEDIUM = 400;
const int STRONG = 600;

const int SHOW_TIME = 500; // milliseconds

void setup() {
  pinMode(KNOB, INPUT);

  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(KNOB);

  Serial.print("The knob reading is: ");
  Serial.println(reading);

  if (reading <= WEAK) {
    Serial.println("That's a weak reading...");
  } else if (reading > WEAK && reading <= MEDIUM) {
    Serial.println("It's ok...");
  } else {
    Serial.println("Wow! That's a high reading!");
  }

  delay(SHOW_TIME);
}
