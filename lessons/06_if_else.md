## Learning
Sometimes, we want our programs to make a simple choice. We may want them to
do one thing if a simple condition is true, or do something else in any other
case. It is important to remember that an `else` can only come after an `if`,
but you don't always need to have an `else` if you don't want one. Experiment
with the following example, just like in the last lesson.

Example:
```
#define THE_BOT_YOURE_LOOKING_FOR 5

int g_bot_id = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (g_bot_id == THE_BOT_YOURE_LOOKING_FOR) {
        Serial.print(g_bot_id)
        Serial.println(" FOUND!");
    } else {
        Serial.println("This is not the bot you're looking for...");
    }

    g_number += 1;
}
```

## Challenges
1. Setup 2 LEDs. Write some code that increases a number by 1 with each
   loop iteration. Your program should light one of the LEDs if the number is
   positive, or the other one if the number is negative.
2. Write a short program that divides a number by another. Declare variables
   for each number, and store the result in another variable. If the divisor
   is 0, print an error message; otherwise, do the division and print out the
   math problem and its result.
3. Modify your solution for the previous challenge. If the dividend is also
   0, then report that the answer "might be 0, might be undefined"; otherwise
   print the same error message as before.
4. `(Extra)` Make one up!
