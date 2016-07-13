/**
 *
 */
#ifndef _NOTES_H_
#define _NOTES_H_ 1

/** Note Durations **/
#define BETWEEN_NOTES   37
#define WHOLE_NOTE      1000
#define HALF_NOTE       (WHOLE_NOTE / 2)
#define QUARTER_NOTE    (WHOLE_NOTE / 4)
#define EIGHTH_NOTE     (WHOLE_NOTE / 8)
#define SIXTEENTH_NOTE  (WHOLE_NOTE / 16)

int dotted(int note_duration) {
  return 1.5 * note_duration;
}

/** Note Frequencies **/
#define NOTE_REST  0
#define NOTE_B0    31
#define NOTE_C1    33
#define NOTE_CS1   35
#define NOTE_D1    37
#define NOTE_DS1   39
#define NOTE_E1    41
#define NOTE_F1    44
#define NOTE_FS1   46
#define NOTE_G1    49
#define NOTE_GS1   52
#define NOTE_A1    55
#define NOTE_AS1   58
#define NOTE_B1    62
#define NOTE_C2    65
#define NOTE_CS2   69
#define NOTE_D2    73
#define NOTE_DS2   78
#define NOTE_E2    82
#define NOTE_F2    87
#define NOTE_FS2   93
#define NOTE_G2    98
#define NOTE_GS2   104
#define NOTE_A2    110
#define NOTE_AS2   117
#define NOTE_B2    123
#define NOTE_C3    131
#define NOTE_CS3   139
#define NOTE_D3    147
#define NOTE_DS3   156
#define NOTE_E3    165
#define NOTE_F3    175
#define NOTE_FS3   185
#define NOTE_G3    196
#define NOTE_GS3   208
#define NOTE_A3    220
#define NOTE_AS3   233
#define NOTE_B3    247
#define NOTE_C4    262
#define NOTE_CS4   277
#define NOTE_D4    294
#define NOTE_DS4   311
#define NOTE_E4    330
#define NOTE_F4    349
#define NOTE_FS4   370
#define NOTE_G4    392
#define NOTE_GS4   415
#define NOTE_A4    440
#define NOTE_AS4   466
#define NOTE_B4    494
#define NOTE_C5    523
#define NOTE_CS5   554
#define NOTE_D5    587
#define NOTE_DS5   622
#define NOTE_E5    659
#define NOTE_F5    698
#define NOTE_FS5   740
#define NOTE_G5    784
#define NOTE_GS5   831
#define NOTE_A5    880
#define NOTE_AS5   932
#define NOTE_B5    988
#define NOTE_C6    1047
#define NOTE_CS6   1109
#define NOTE_D6    1175
#define NOTE_DS6   1245
#define NOTE_E6    1319
#define NOTE_F6    1397
#define NOTE_FS6   1480
#define NOTE_G6    1568
#define NOTE_GS6   1661
#define NOTE_A6    1760
#define NOTE_AS6   1865
#define NOTE_B6    1976
#define NOTE_C7    2093
#define NOTE_CS7   2217
#define NOTE_D7    2349
#define NOTE_DS7   2489
#define NOTE_E7    2637
#define NOTE_F7    2794
#define NOTE_FS7   2960
#define NOTE_G7    3136
#define NOTE_GS7   3322
#define NOTE_A7    3520
#define NOTE_AS7   3729
#define NOTE_B7    3951
#define NOTE_C8    4186
#define NOTE_CS8   4435
#define NOTE_D8    4699
#define NOTE_DS8   4978

int play_tone_precise(int speaker, long frequency, long duration) {
/** Plays a tone using more precise timings.
 * 
 * Parameters
 *   speaker: The number of the pin to oscillate.
 *   frequency: The frequency of the tone to play.
 *   duration: The duration to play the tone for in milliseconds.
 *
 * Return
 *   error_code: Currently unused.
 */
  // Convert the duration to microseconds.
  duration *= 1000L;
  unsigned long start_time = micros();
  
  if (frequency > 0) {
      while (micros() < (start_time + duration)) {
        digitalWrite(speaker, HIGH);
        delayMicroseconds(frequency);
        digitalWrite(speaker, LOW);
        delayMicroseconds(frequency);
      }
  } else {
    digitalWrite(speaker, LOW);
    delayMicroseconds(duration);
  }

  delay(BETWEEN_NOTES);

  return 0;
}


int play_dusty_old_tune(int speaker) {
  // a NOTE_CS6
  // b NOTE_B5
  // C NOTE_AS5
  // D NOTE_GS5
  // E NOTE_FS5
  // F NOTE_F5
  // g NOTE_DS6
  // G NOTE_DS5
  // i NOTE_D5
  // q NOTE_E5
  // w NOTE_G5
  // x NOTE_D6
  // y NOTE_A5
  // z NOTE_C6

  const int N_NOTES = 60;
  const int ZXQ = SIXTEENTH_NOTE;

  const int notes[N_NOTES] =     {
     NOTE_DS6,  NOTE_CS6,   NOTE_B5,   NOTE_A5,  NOTE_DS6,  NOTE_CS6,   NOTE_B5,   NOTE_A5,
      NOTE_D6,   NOTE_C6,  NOTE_AS5,  NOTE_GS5,   NOTE_D6,   NOTE_C6,  NOTE_AS5,  NOTE_GS5,
     NOTE_CS6,   NOTE_B5,   NOTE_A5,   NOTE_G5,  NOTE_CS6,   NOTE_B5,   NOTE_A5,   NOTE_G5,
      NOTE_C6,  NOTE_AS5,  NOTE_GS5,  NOTE_FS5,   NOTE_C6,  NOTE_AS5,  NOTE_GS5,  NOTE_FS5,
      NOTE_B5,   NOTE_A5,   NOTE_G5,   NOTE_F5,  NOTE_AS5,  NOTE_GS5,  NOTE_FS5,   NOTE_E5,
      NOTE_A5,   NOTE_G5,   NOTE_F5,  NOTE_DS5,  NOTE_GS5,  NOTE_FS5,   NOTE_E5,   NOTE_D5,
    NOTE_REST, NOTE_REST, NOTE_REST, NOTE_REST, NOTE_REST, NOTE_REST, NOTE_REST, NOTE_REST,
     NOTE_CS6,   NOTE_C6,   NOTE_B5,  NOTE_AS5
  };
  const int durations[N_NOTES] = {
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ, ZXQ,
    EIGHTH_NOTE, dotted(EIGHTH_NOTE), dotted(EIGHTH_NOTE), WHOLE_NOTE
  };

  for (int i = 0; i < N_NOTES; i++) {
    play_tone_precise(speaker, notes[i], durations[i]);
  }
  noTone(speaker);
}

#endif