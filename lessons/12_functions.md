## Learning
Do you ever get tired of writing the same code over and over? Or maybe, the
code just changes a little bit each time? Or maybe, You see a big chunk of
code and don't know what it does right away? Functions solve all of those
problems!

We won't go over the syntax of functions extensively, so just use the
patterns we set here, and ask someone for help if you need to do something
fancier. It is helpful to think of them like math functions as well. Think
about `f(x) = x + 4` and so `f(3) = 7`. It's the same idea!

Interestingly enough, you've already been writing 2 functions of
your own: setup and loop! You've also been calling many functions on your own,
like `Serial.println()`, `digitalWrite()`, and `delay()` just to name a few!

You have to define the function (typically this is done at the bottom
of your file), and then you "call" the function wherever you want its code
to execute.

A simple function that improves code readability might look like:
```
#define LED 13

void setup() {
    pinMode(LED, OUTPUT);

    do_blink_routine();
    delay(1000);
}

void loop() {
    do_blink_routine();
    delay(500);
}

void do_blink_routine() {
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(50);
}
```

This is the kind of function you will be most likely to use.

A function that's a little fancier and can change it's behavior based on a
parameter would look like:
```
#define LED 13

void setup() {
    pinMode(LED, OUTPUT);

    do_blink_routine(1);
    delay(1000);
}

void loop() {
    do_blink_routine(3);
    delay(500);
}

void do_blink_routine(int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(100);
        digitalWrite(LED, HIGH);
        delay(400);
        digitalWrite(LED, LOW);
        delay(50);
    }
}
```

Finally, a function that can actually summarize a computation would look like:
```
void setup() {
    Serial.begin(9600);

    int n1 = 5;
    int n2 = 78;
    int n3 = 4;

    int biggest_number = max_of_three(n1, n2, n3);

    Serial.print("The max of ");
    Serial.print(x1); Serial.print(", ");
    Serial.print(x2); Serial.print(", and ");
    Serial.print(x3); Serial.print(" is ");
    Serial.println(biggest_number);
}

void loop() {}

int max_of_three(int x1, int x2, int x3) {
    int biggest = x1;

    if (x2 > biggest) {
        biggest = x2;
    }

    if (x3 > biggest) {
        biggest = x3;
    }

    return biggest;
}
```

Be sure to ask your instructor(s) more about functions if you want to use them.
Functions are HIGHLY recommended!


## Challenges
1. Write your own function that greets a user.
2. Write a function that will run a blink routine on a specified Arduino pin.
   The idea is that you can write the blink code once, and have code that
   can blink on any pin you tell it to.
3. Write a function that computes the area of a circle, given a radius. Be
   sure to use the 'float' type instead of 'int'!
4. `(Extra)` Make up one!
