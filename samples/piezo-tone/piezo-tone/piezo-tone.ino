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
  tone(BUZZER, NOTE_A3, ONE_SECOND);
  noTone(BUZZER);
  tone(BUZZER, NOTE_C3, ONE_SECOND);
  noTone(BUZZER);

  // We can also store information in arrays like above and
  // play a whole song:
  for (int i = 0; i < MELODY_LENGTH; i++) {
    tone(BUZZER, melody[i], note_durations[i]);
    delay(BETWEEN_NOTES);
    noTone(BUZZER); 
  }
}

void loop() {
  // ignore this
  delay(120000);
  play_dusty_old_tune(BUZZER);
}

