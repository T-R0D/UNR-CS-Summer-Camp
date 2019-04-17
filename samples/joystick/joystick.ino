#include "joystick.hpp"

#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_Z A2

Joystick g_joystick;

void setup() {
  Serial.begin(9600);

  g_joystick.init(JOYSTICK_X, JOYSTICK_Y, JOYSTICK_Z);
}

void loop() {
  Joystick::Position position = g_joystick.get_position();

  Serial.println("JOYSTICK STATUS");
  Serial.println("---------------");

  Serial.print("Position: ");
  Serial.println(position_to_name(position));
  Serial.print("Pressed:  ");
  Serial.println(g_joystick.get_button_pressed() ? "YES" : "no");

  Serial.println("Raw Output");
  Serial.print("X: ");Serial.println(g_joystick.get_x());
  Serial.print("Y: ");Serial.println(g_joystick.get_y());
  Serial.print("Z: ");Serial.println(g_joystick.get_z());

  Serial.println("");

  delay(1000);
}

String position_to_name(Joystick::Position position) {
  if (position == Joystick::Position::EAST) {
    return "East";
  } else if (position == Joystick::Position::NEUTRAL) {
    return "Neutral";
  } else if (position == Joystick::Position::NORTH) {
    return "North";
  } else if (position == Joystick::Position::NORTHEAST) {
    return "NorthEast";
  } else if (position == Joystick::Position::NORTHWEST) {
    return "NorthWest";
  } else if (position == Joystick::Position::SOUTH) {
    return "South";
  } else if (position == Joystick::Position::SOUTHEAST) {
    return "SouthEast";
  } else if (position == Joystick::Position::SOUTHWEST) {
    return "SoutWest";
  } else if (position == Joystick::Position::WEST) {
    return "West";
  } else {
    return "?!?";
  }
}

