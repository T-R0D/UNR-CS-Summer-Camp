/**
 * LM35 Temperature Sensor Sample
 * 
 * Demonstrates the use of the LM35 temperature sensor.
 * 
 * Board: Arduino UNO
 */

#define TEMP_SENSOR  A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = read_lm35_celcius(TEMP_SENSOR);

  Serial.print("Celcius: ");
  Serial.println(temp);

  Serial.print("Farenheit: ");
  Serial.println(celcius_to_farenheit(temp));
  Serial.println("");

  delay(1000);
}

float read_lm35_celcius(int sensor_pin) {
/**
 * Converts voltage read from sensor and converts it to a Celcius temperature.
 * 
 * Performs a voltage reading on the specified pin. The voltage reading conversion
 * uses "magic numbers" derived from values found in the LM35's data sheet. This
 * function does assume that the Arduino is using a reference voltage of 5.0V (this
 * is generally the "default", when nothing has been done with the AREF pin).
 *
 * Inputs
 *   sensor_pin: the pin whose voltage will be read.
 *  
 * Outputs
 *   celcius: the temperature in degrees celcius indicated by the sensor.
 */
 
  int reading = analogRead(sensor_pin);
  float celcius = (reading * 0.4882815) + 5;
  return celcius; 
}

float celcius_to_farenheit(float celcius) {
/**
 * Converts a number representing Celcius temperature to Farenheit.
 *
 * Uses the standard formula for converting Celcius to Farenheit.
 * 
 * Input
 *   celcius: a number representing a celcius temperature.
 *   
 * Output
 *   farenheit: a number representing a farenheit temperature.
 */
  
  return ((celcius * 9.0) / 5.0) + 32.0;
}

