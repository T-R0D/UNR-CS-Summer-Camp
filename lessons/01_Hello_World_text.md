## Learning
Our very first program is going to have the Arduino say hello to the world.
This is the classic first program you would write any time you use a new
language or technology.

The program is very simple:
```
void setup() {
    Serial.begin(9600);
    Serial.println("Hello World!");
}

void loop() {
}
```
Upload the program, and open the serial monitor to see what the Arduino has
to say.

We always need to use `Serial.begin(9600);` to start up the thing that let's
the Arduino print text.

Then we use `Serial.println("Hello World!");` To print Hello World on one line.

In this example we passed a string (any text inside the "" quotes) to
Serial.println. We could also pass numbers, like `Serial.println(777);` or
`Serial.println(98.6)`.

Finally, we can print things without moving to a new line with Serial.print.
For example, see what the following program does:
```
void setup() {
    Serial.begin(9600);
    Serial.print("Hello");
    Serial.print(" ");
    Serial.print("World");
    Serial.print(" again!");
}

void loop() {
}
```

## Challenges
1. Write an Arduino program that can say hello to you (make the Arduino say your name).
2. Make the Arduino say more than one thing (maybe say hello and then say a silly sentence).
3. Write an Arduino program that says a number (not with a string).
4. `(Extra)` Write an Arduino program that says something over and over.
