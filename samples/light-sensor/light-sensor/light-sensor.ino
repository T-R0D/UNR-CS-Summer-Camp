#define LIGHT_SENSOR A0

void setup() {
  Serial.begin(9600);

  // Initialize the pin to read the light sensor.
  pinMode(LIGHT_SENSOR, INPUT);
}

void loop() {
  // Grab the value from the sensor.
  // High values mean it's dark, low values mean it's light.
  int light_reading = analogRead(LIGHT_SENSOR);

  // Report the value that was read.
  Serial.print("The light sensor reads: ");
  Serial.println(light_reading);

  // A short delay so that data isn't being faster than a
  // human can read it.
  delay(100);
}

