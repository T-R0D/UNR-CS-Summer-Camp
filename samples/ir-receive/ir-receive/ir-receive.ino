/**
 * 
 */

#include <IRremote.h>

const int ANTI_SPAM_TIME = 100; // milliseconds

// sometimes it's easier to write numbers in hexadecimal (base-16)
// we can use digits 0-9 and A-F, and put a '0x' in front of it
const uint32_t NO_DATA = 0xFFFFFFFF;

const uint32_t FIVE_KEY  = 0xFF38C7;
const uint32_t PLUS_KEY  = 0xFF906F;
const uint32_t MINUS_KEY = 0xFFA857;

const int IR_RECV_PIN = 11;

IRrecv ir_receiver(IR_RECV_PIN);
decode_results ir_results;
int volume = 0;

void setup() {
  Serial.begin(9600);
  ir_receiver.enableIRIn(); // start the receiver
}

void loop() {
  bool ir_data_received = ir_receiver.decode(&ir_results);
  uint32_t value = ir_results.value;

  // make sure that data was received and that it wasn't garbage
  if (ir_data_received) {
    ir_receiver.resume(); // start accepting ir signals again
  
    if (value != NO_DATA) {

      // depending on the signal we get, we can do different things
      if (value == FIVE_KEY) {
        Serial.println("What was I supposed to do on '5'?");
        
      } else if (value == PLUS_KEY) {
        volume += 1;
        Serial.print("Volume set to: "); Serial.println(volume);
      
      } else if (value == MINUS_KEY) {
        volume -= 1;
        Serial.print("Volume set to: "); Serial.println(volume);
      
      } else {
        // printing the recieved code like this is how we can find out
        // what code was sent from the remote
        Serial.print("Received an unrecognized code: ");
        Serial.println(ir_results.value, HEX);
        // take out the print statement when you are done debuging though!
      }
    }
  }
  
  delay(ANTI_SPAM_TIME);
}

