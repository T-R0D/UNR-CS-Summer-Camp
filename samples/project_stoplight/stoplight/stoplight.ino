/**
 * 4-Way Stoplight
 * 
 * A simple 4-way stoplight simulator.
 * 
 * Uses a naive round-robinning algorithm for letting cars through. Let's one
 * direction of traffic through at a time; rotates clockwise through each
 * direction. Each direction of traffic fully completes before the next
 * direction gets its turn.
 * 
 * Board: Arduino Uno
 * 
 * Other Materials:
 *   4 x Red LED
 *   4 x Yellow LED
 *   4 X Green LED
 * 
 * Author: Terence Henriod
 */
 //123456789012345678901234567890123456789012345678901234567890123456789012345678

#define PRE_GREEN_TIME      100
#define GREEN_TIME         2400
#define YELLOW_TIME         500
#define ALL_STOPPED_TIME    500

#define NORTH_GREEN_LIGHT    11
#define NORTH_YELLOW_LIGHT   12
#define NORTH_RED_LIGHT      13

#define WEST_GREEN_LIGHT      5
#define WEST_YELLOW_LIGHT     6
#define WEST_RED_LIGHT        7

#define EAST_GREEN_LIGHT      8
#define EAST_YELLOW_LIGHT     9
#define EAST_RED_LIGHT       10

#define SOUTH_GREEN_LIGHT     2
#define SOUTH_YELLOW_LIGHT    3
#define SOUTH_RED_LIGHT       4




void setup() {
  initialize_light_block(NORTH_GREEN_LIGHT, NORTH_YELLOW_LIGHT, NORTH_RED_LIGHT);

  initialize_light_block(WEST_GREEN_LIGHT, WEST_YELLOW_LIGHT, WEST_RED_LIGHT);

  initialize_light_block(EAST_GREEN_LIGHT, EAST_YELLOW_LIGHT, EAST_RED_LIGHT);

  initialize_light_block(SOUTH_GREEN_LIGHT, SOUTH_YELLOW_LIGHT, SOUTH_RED_LIGHT);
}

void loop() {
  allow_traffic(NORTH_GREEN_LIGHT, NORTH_YELLOW_LIGHT, NORTH_RED_LIGHT);

  allow_traffic(SOUTH_GREEN_LIGHT, SOUTH_YELLOW_LIGHT, SOUTH_RED_LIGHT);

  allow_traffic(EAST_GREEN_LIGHT, EAST_YELLOW_LIGHT, EAST_RED_LIGHT);

  allow_traffic(WEST_GREEN_LIGHT, WEST_YELLOW_LIGHT, WEST_RED_LIGHT);
}

void initialize_light_block(int green_light, int yellow_light, int red_light) {
  pinMode(green_light, OUTPUT);
  digitalWrite(green_light, LOW);
  
  pinMode(yellow_light, OUTPUT);
  digitalWrite(yellow_light, LOW);
  
  pinMode(red_light, OUTPUT);
  digitalWrite(red_light, HIGH);
}

void allow_traffic(int green_light, int yellow_light, int red_light) {
  // Turn all of the lights off to put things in a known state.
  digitalWrite(green_light, LOW);
  digitalWrite(yellow_light, LOW);
  digitalWrite(red_light, LOW);

  // Let traffic through with a green light.
  digitalWrite(green_light, HIGH);
  delay(GREEN_TIME);

  // Start warning traffic that it should stop soon with a yellow light.
  digitalWrite(green_light, LOW);
  digitalWrite(yellow_light, HIGH);
  delay(YELLOW_TIME);

  // Turn on the red light to stop traffic.
  digitalWrite(yellow_light, LOW);
  digitalWrite(red_light, HIGH);
  delay(ALL_STOPPED_TIME);
}

