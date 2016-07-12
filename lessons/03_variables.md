## Learning
Variables are how our programs "remember" things. Variables hold data, and then
we can use or update that data later.

Some examples:
```
// This is a constant.
#define BLINK_TIME 500
// This is another constant.
const int  DIFFERENT_BLINK_TIME = 300;

// This is a global variable
int g_high_score = 5;

void setup() {
    // declaring some variables
    String phrase = "Hi there!";  // string variables hold text
    int sheep_counted = 2;        // int variables hold whole numbers
    float inches = 3.26;          // float variables hold fractional numbers

    // we can update variable values, or use them to make new values.
    String long_phrase = phrase + " Nice to meet you!";
    // Serial.println(sheep_counted);

    delay(BLINK_TIME);
}

void loop() {
}
```

Notice at the top of the program, we have some "constants". Constants are
very good to use because they make our code more readable, and we only
have to change the value in one place if we need to. What if we want to
make the blink time shorter? We can just change the value of the constant
at the top of the program instead of having to look for and change all of
the `500` that we may have typed. Also, constants can't be accidentally
changed, so they help keep bugs out of our programs. Notice that there are two
ways of declaring constants, either way is fine.

Something that might get tricky is that variables all have a "scope", meaning
that they only live inside a pair of "{}". They are created at the "{" and they
die and are forgotten at the corresponding "}". On some occasions, we need
variables to live outside of the "{}", so we make them global. We name these
variables like "g_<something>" to help us remember that they are global. Global
variables can be accessed from anywhere in the program after they have been
declared.

## Challenges

1. Write a program that declares variables to hold your name, age, and
   temperature. Declare one of these values as a constant instead of a
   normal variable.

2. Modify your program to assign new values to the variables later in the
   program.

3. Modify your program to print the values of your variables at each step of
   the program. You will need to add the Serial printing code like we used
   in an earlier lesson.

4. `(Extra)` Modify your program to print the variable's name and its
   type before printing its value.
