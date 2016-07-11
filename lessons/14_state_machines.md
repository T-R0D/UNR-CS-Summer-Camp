## Learning
If you want to make your programs easy to understand and easy to update,
you should apply the concept of a "state-machine". The idea here is that
your program should move from one "state" to the next in an easy to follow
fashion.

We can implement a state machine using function calls in our loop() function
to make it easy to understand. Then all of the code that defines each state
can be neatly packaged in a function definition.

It is not necessary, but it is very likely that each state will use a
while loop to keep your program in a particular state as long as it needs
to be there.

The "state-machine" is an excellent strategy if you want to make a game!

It can often help to draw a picture of the states your program will move
through. You can even use good old-fashioned paper!

Example:
```
/**
 * A simple example of a state machine. This program starts in a waiting
 * state, then moves to a show state, and then starts the whole thing over.
 *
 *  -------->  ----------------           --------------         ---------
 *  Arduino    | Wait for     |  ----->   | Play light |  ---->  | Short |
 *  start-up   | button-press |  button   | show       |  show   | pause |
 *             ----------------  pressed  --------------  ends   ---------
 *                    ^                                          v
 *                    |                                          |
 *                    --------------<--------------------<--------
 *                                       pause ends
 */

#define LED            13
#define ACTION_BUTTON   4

void setup() {
    Serial.begin(9600);

    pinMode(LED, OUTPUT);

    pinMode(ACTION_BUTTON, INPUT);
}

void loop() {
    wait_to_start();

    play_light_show();

    delay(1000);
}

void wait_to_start() {
    bool button_pressed = false;

    while (!button_pressed) {
        Serial.println("Press the action button to begin!")

        // Poll the button for half a second.
        for (i = 0; i < 100; i++) {
            if (digitalRead(ACTION_BUTTON) == HIGH) {
                button_pressed = true;
            }
            delay(5);
        }
    }

    Serial.println("Let's begin!");
}

void play_light_show() {
    Serial.println("Are you ready for a show?");
    delay(500);

    for (i = 0; i < 5; i++) {
        digitalWrite(LED, HIGH);
        delay(i * 50);

        digitalWrite(LED, LOW);
        delay(i * 50);
    }

    Serial.println("I hope you enjoyed the show!");
    delay(1000);
}
```


## Challenges
1. Write a simple program that uses a state machine to count to 3 in different
   languages. Use a different state for each language.
2. Write a simple program that executes different behavior based on the
   light levels in the room. The program starts with a polling state, where
   the program reads the light reading in the room to find the lowest one for
   1 minute. If the light reading indicates darkness, the program should move
   to a state where an LED is left on for 1 minute. If the light reading is
   too high, the program should move to a state that ensures that the LED is
   off. Finally, the program should start the cycle over.
3. Make up one!
4. `(Extra)` Use the state-machine strategy in your project!
