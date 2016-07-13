#include "notes.h"

#define BUZZER 3

#define ONE_SECOND 1000
#define MELODY_LENGTH 8

int melody[MELODY_LENGTH] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3,
  NOTE_G3, NOTE_REST, NOTE_B3, NOTE_C4
};

int note_durations[MELODY_LENGTH] = {
  QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,
  QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE
};

void setup() {
  pinMode(BUZZER, OUTPUT);

  // We can play a tone with the built-in function like this:
  tone(BUZZER, NOTE_A3); // Play the A3 note. 
  delay(ONE_SECOND);     // Let it play for 1 second.
  noTone(BUZZER);        // Stop the tone from playing.
  
  tone(BUZZER, NOTE_C); // Play the C3 note. 
  delay(ONE_SECOND);     // Let it play for 1 second.
  noTone(BUZZER);        // Stop the tone from playing.

  // We can also store information in arrays like above and
  // play a whole song:
  for (int i = 0; i < MELODY_LENGTH; i++) {
    tone(BUZZER, melody[i]);
    delay(note_durations[i]);
    noTone(BUZZER);
    delay(BETWEEN_NOTES); 
  }
}

void loop() {
  /* ignore this */
  delay(120000);
  play_dusty_old_tune(BUZZER);
  /* ignore this */
}

