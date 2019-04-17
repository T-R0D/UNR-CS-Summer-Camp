/**
 * A sample sketch demonstrating basic use of a 4x4 keypad and the
 * Arduino community keypad library.
 * 
 * For API documentation:
 * https://playground.arduino.cc/Code/Keypad/
 * 
 * Helpful information and circut schematics can be found here:
 * http://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
 */
#include <Keypad.h>

#define PASSCODE_LEN 4
#define KEYPAD_ROWS     4
#define KEYPAD_COLUMNS  4
const byte KEYPAD_ROW_PINS[KEYPAD_ROWS] = {2, 3, 4, 5};
const byte KEYPAD_COLUMN_PINS[KEYPAD_COLUMNS] = {6, 7, 8, 9};
const char KEYPAD_KEYS[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
Keypad g_keypad(makeKeymap(KEYPAD_KEYS),
    KEYPAD_ROW_PINS, KEYPAD_COLUMN_PINS, KEYPAD_ROWS, KEYPAD_COLUMNS);

char g_passcode[PASSCODE_LEN] = {'1', '2', '3', '4'};

void setup() {
  Serial.begin(9600);
  Serial.println("Press * to enter a password for validation");
  Serial.println("      # to set a new password");
}

void loop() {
  char key = g_keypad.getKey();
  while (key != '*' && key != '#') {
    // We could really do whatever we want here, blink LEDs, etc.
    delay(50);
    key = g_keypad.getKey();
  }

  if (key == '*') {
    Serial.println("Enter a passcode one key at a time...");
    bool passcode_matches = collect_passcode(g_passcode);
    if (passcode_matches) {
      Serial.println("Passcode match!");
    } else {
      Serial.println("Invalid passcode entered.");
    }
  } else if (key == '#') {
    // We should probably check to see if the user knows the old
    // pasword before we let them set a new one, but this is just
    // an example so...
    Serial.println("Enter a new passcode, one key at a time.");
    bool passcode_set_successfully = set_passcode(g_passcode);
    if (passcode_set_successfully) {
      Serial.println("Passcode updated successfully!");
    } else {
      Serial.println("Passcode NOT changed.");
    }
  }
}

bool set_passcode(char passcode[PASSCODE_LEN]) {
  char entry[PASSCODE_LEN];
  for (int i = 0; i < PASSCODE_LEN; i += 1) {
    entry[i] = g_keypad.waitForKey();
  }

  // Assume the entry is valid. If we wanted to validate the
  // entered code, we could do that here.

  for (int i = 0; i < PASSCODE_LEN; i += 1) {
    passcode[i] = entry[i];
  }
  return true; // The passcode was successfully changed.
}

bool collect_passcode(char correct_passcode[PASSCODE_LEN]) {
  char entry[PASSCODE_LEN];
  for (int i = 0; i < PASSCODE_LEN; i += 1) {
    entry[i] = g_keypad.waitForKey();
  }

  bool passcode_matches = true;
  for (int i = 0; i < PASSCODE_LEN; i += 1) {
    if (entry[i] != correct_passcode[i]) {
      passcode_matches = false;
    }
  }
  return passcode_matches;
}

