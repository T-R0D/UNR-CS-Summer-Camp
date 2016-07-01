/**
 * 
 */

#define VIBRATION_SENSOR  A0

#define MIN_VIBRATION_THRESHOLD  30

void setup() {
  Serial.begin(9600);

  pinMode(VIBRATION_SENSOR, INPUT);
}

void loop() {
  int reading = analogRead(VIBRATION_SENSOR);

  if (reading > MIN_VIBRATION_THRESHOLD) {
    Serial.print("Vibration: ");
    Serial.println(reading);
    Serial.println("");
    delay(250);
  }
}
