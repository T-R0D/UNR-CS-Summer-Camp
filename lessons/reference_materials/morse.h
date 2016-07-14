#ifndef _MORSE_H_
#define _MORSE_H_ 1

#define DOT_DURATION 100
#define DASH_DURATION 400
#define BETWEEN_DURATION 300
#define END_OF_STRING_DURATION 1000

void blink_dot(int pin) {
  digitalWrite(pin, HIGH);
  delay(DOT_DURATION);
  digitalWrite(pin, LOW);
  delay(BETWEEN_DURATION);
}

void blink_dash(int pin) {
  digitalWrite(pin, HIGH);
  delay(DASH_DURATION);
  digitalWrite(pin, LOW);
  delay(BETWEEN_DURATION);
}

void blink_char(int pin, char c) {
  switch(c) {
    case 'a':
    case 'A':
      blink_dot(pin);
      blink_dash(pin);
      break;
      
    case 'b':
    case 'B':
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case 'c':
    case 'C':
      blink_dash(pin);
      blink_dot(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;
      
    case 'd':
    case 'D':
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case 'e':
    case 'E':
      blink_dot(pin);
      break;
    
    case 'f':
    case 'F':
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;
    
    case 'g':
    case 'G':
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;
    
    case 'h':
    case 'H':
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
    
    case 'i':
    case 'I':
      blink_dot(pin);
      blink_dot(pin);
      break;
    
    case 'j':
    case 'J':
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
    
    case 'k':
    case 'K':
      blink_dash(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
    
    case 'l':
    case 'L':
      blink_dot(pin);
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
    
    case 'm':
    case 'M':
      blink_dash(pin);
      blink_dash(pin);
      break;
    
    case 'n':
    case 'N':
      blink_dash(pin);
      blink_dot(pin);
      break;
    
    case 'o':
    case 'O':
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
    
    case 'p':
    case 'P':
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;
    
    case 'q':
    case 'Q':
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
    
    case 'r':
    case 'R':
      blink_dot(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;
    
    case 's':
    case 'S':
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
    
    case 't':
    case 'T':
      blink_dash(pin);
      break;
    
    case 'u':
    case 'U':
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
    
    case 'v':
    case 'V':
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
    
    case 'w':
    case 'W':
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
    
    case 'x':
    case 'X':
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
    
    case 'y':
    case 'Y':
      blink_dash(pin);
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
    
    case 'z':
    case 'Z':
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case '1':
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
      
    case '2':
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
      
    case '3':
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
      
    case '4':
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dash(pin);
      break;
      
    case '5':
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;
      
    case '6':
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case '7':
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case '8':
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      blink_dot(pin);
      break;
      
    case '9':
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dot(pin);
      break;

    case '0':
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      blink_dash(pin);
      break;

    default:
      digitalWrite(pin, LOW);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
      delay(DOT_DURATION);
  }
}

void blink_morse(int pin, const char* str) {
  if(str == NULL) return;
  
  while(*str != '\0') {
    blink_char(pin, *str);
    str++;
  }

  delay(END_OF_STRING_DURATION);
}

#endif

