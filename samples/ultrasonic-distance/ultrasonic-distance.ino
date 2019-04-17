/**
 * Asample sketch demonstrating the use of an HC-SR04
 * Ultrasonic Distance Sensor.
 * 
 * The sensor seems to be effetive at detecting objects between 5 and 100
 * centimeters.
 */

#define ULTRASONIC_TRIGGER_PIN   9
#define ULTRASONIC_ECHO_PIN     10

#define SPEED_OF_SOUND_CM_PER_US 0.034

void setup() {
  Serial.begin(9600);
  
  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
}

void loop() {
  int distance_in_cm = read_ultrasonic_sensor();

  Serial.print("Distance: ");
  Serial.print(distance_in_cm);
  Serial.println("cm");

  delay(1000);
}

int read_ultrasonic_sensor() {
  // Activate the sensor to send out pulses of sound for a short while.
  digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  // Listen for a high pulse. The duration represents how long our
  // sound pulse took to make it away from and back to the sensor.
  unsigned long round_trip_time = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);

  // Compute the one-way distance from the sensor to whatever reflected
  // our sound waves back to us.
  int distance_in_cm = int((round_trip_time * SPEED_OF_SOUND_CM_PER_US) / 2);
  return distance_in_cm;
}

