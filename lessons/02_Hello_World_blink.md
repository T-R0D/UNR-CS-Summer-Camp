## Learning
When it comes to embedded systems (like Arduino), we often can't print text
to a monitor, so a different kind of Hello World is to blink an on-board LED.

This program is also simple:

```
#define BLINK_TIME 500 // milliseconds
#define LED_PIN 13 // special pin that controls LED light

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(BLINK_TIME);
    digitalWrite(LED_PIN, LOW);
    delay(BLINK_TIME);
}
```

We use `#define BLINK_TIME 500` to create a constant. This helps make our code
more readable (now we don't have to guess what "500" is for), and easier to
change (if we wanted our blink time to be 300 milliseconds, we can change it
once at the top instead of everywhere else in the code).

`pinMode(LED_PIN, OUTPUT);` is how we setup a pin, kind of like how we did
`Serial.begin(9600);`.

Code in the loop function gets run over and over. Once it finishes, it
just starts over.

`digitalWrite(LED_PIN, HIGH);` is how we turn the LED on,
`digitalWrite(LED_PIN, HIGH);` is how we turn it off.

We use `delay(BLINK_TIME);` to make the Arduino wait for a while. Computers
(even small ones like the Arduino) are very fast. Without the delay, the
Arduino would turn the LED on and off so fast, we might not see the LED come
on at all!

## Challenges
1. Modify the blink program to blink faster or slower.
2. Write a blink program that does a special pattern, not like the boring
   example.
3. `(Extra)` Blink a short message of your choice in Morse Code. (A classic is "SOS")
4. `(Extra)` Write a blink program that varies the length of the blinks but only
uses two calls to digitalWrite. (You probably can't do this one until you've learned more)
