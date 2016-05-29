#include "LiquidCrystal_I2C.h"

#define START_BUTTON 12

#define DISPLAY_TOP_LINE 0
#define DISPLAY_BOTTOM_LINE 1
#define DISPLAY_WIDTH 16

#define FLASH_TIME 200             // milliseconds
#define MESSAGE_DISPLAY_TIME 3000  // milliseconds

// This is how we create a variable to control the LCD display.
// It has a lot of "magic numbers" :(, but go with it.
LiquidCrystal_I2C  g_lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

// This could be a high score variable for a game or something.
unsigned long g_high_score = 0;

 
void setup()
{
    // We need these lines to setup our LCD display.
    g_lcd.begin (16,2); // for 16 x 2 LCD module
    g_lcd.setBacklightPin(3,POSITIVE);
    g_lcd.setBacklight(LOW);
}
 
void loop() {
  // This is an example of how we can use functions to make
  // our code cleaner and make a "state machine".
  game_idle_state();

  // Game play logic would go here.
  g_high_score += 112;
}

int game_idle_state() {
  bool idle = true;
  bool button_pressed = false;
  
  while (idle) {
    // Get people's attention.
    flash_screen(3);

    // Show the name of the game.
    g_lcd.clear(); // We need to clear out old text.
    g_lcd.setBacklight(HIGH);
    g_lcd.setCursor(0, DISPLAY_TOP_LINE);
    g_lcd.print("   SUPER PHUN   ");
    g_lcd.setCursor(0, DISPLAY_BOTTOM_LINE);
    g_lcd.print("    THYME!!!    ");

    // Check to see if the game should start.
    button_pressed = poll_button(START_BUTTON, MESSAGE_DISPLAY_TIME);
    if (button_pressed) {
      idle = false;
    }

    // Show the high score.
    g_lcd.clear(); // We need to clear out old text.
    g_lcd.setBacklight(HIGH);
    g_lcd.setCursor(0, DISPLAY_TOP_LINE);
    g_lcd.print("High Score:");
    g_lcd.setCursor(5, DISPLAY_BOTTOM_LINE);
    g_lcd.print(g_high_score);
    delay(MESSAGE_DISPLAY_TIME);

    // Check to see if the game should start.
    button_pressed = poll_button(START_BUTTON, MESSAGE_DISPLAY_TIME);
    if (button_pressed) {
      idle = false;
    }
  }

  // Show a simple message to indicate the game will start soon.
  flash_screen(2);
  g_lcd.clear();
  g_lcd.setBacklight(HIGH);
  g_lcd.setCursor(0, DISPLAY_TOP_LINE);
  g_lcd.print("  GET READY!");
  delay(MESSAGE_DISPLAY_TIME);
  g_lcd.setBacklight(LOW);
  delay(MESSAGE_DISPLAY_TIME);
  
  return 0;
}

int flash_screen(unsigned int times) {
  // Just like the blink program!
  g_lcd.clear();
  
  for (int i = 0; i < times; i++) {
    g_lcd.setBacklight(HIGH);
    delay(FLASH_TIME);
    g_lcd.setBacklight(LOW);
    delay(FLASH_TIME);   
  }
  
  return 0;
}

bool poll_button(int pin, unsigned long poll_time) {
  bool button_pressed = false;
  unsigned long start_time = millis();

  while (millis() < (poll_time + start_time)) {
    if (digitalRead(pin) == HIGH) {
      button_pressed = true; 
    }
  }

  return button_pressed;
}

