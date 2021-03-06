## Learning
What happens if you need your program to do the same thing multiple times?
Should you just copy and paste your code? NEVER! Use a `for` loop! This
keeps you writing code only once, and it is way easier to change the code
if you need to change the number of times your program does the special
thing.

There is actually more to know about `for` loops than I will explain. Just
use the pattern in the example (the `for (i ... )` line is the important
part).

Keep in mind that `i` is a variable, so you are allowed to use it in the loop
code if you want.

Example:
```
void setup() {
    Serial.begin(9600);

    Serial.println("I will say \"yay!\" 5 times.");
    for (int i = 0; i < 5; i++) {
        Serial.println("yay!");
    }
}

void loop() {
}
```

## Challenges
1. Write a blinky program that repeats a pattern 3 times and finishes with
   a long blink. The idea is that you should write an interesting blink
   pattern that repeats, but the sets of repetition are separated by an
   easy to recognize pattern.
2. Write a program that counts from 1 to 100 and prints out each number.
3. Write a program that counts from 1 to 5, 5 times. (Hint: nest a for loop
   in the first one, and use a variable named "j" for the inner loop.)
4. `(Extra)` Can you rewrite a for loop as a while loop? Can you rewrite a while
   loop as a for loop?
