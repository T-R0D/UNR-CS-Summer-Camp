## Learning
Do you ever have multiple variables that are all the same type? Wouldn't it
be cool if there was some kind of "super-variable" to hold a lot of
variables in one name? That's what arrays are for.

Arrays are a bit advanced for our purposes, but you might want to know
about them for holding lots of numbers. (Hint: if you want to make any songs
for the piezo buzzer, you might use an array to hold all of the note values.)

When you declare an array, you need to say how large it is, or how many
variables the array should contain. This should be done with a constant:
```
#define LIST_SIZE 3

int number_list[LIST_SIZE];
```

You can then access a particular variable in the array using a number
(aka an "index") representing the offset from the start of the array (it's
a little weird, but roll with it):
```
void setup() {
    number_list[0] = 9; // The first  variable/element is the 0th one
    number_list[1] = 8; // The second variable/element is the 1th one
    number_list[2] = 7; // The third  variable/element is the 2th one
}
```

You could also use a variable as an index to access array elements. That's
why for loops and arrays go together like peanut butter and chocolate:
```
#define LIST_SIZE 3

int number_list[LIST_SIZE];

void setup() {
    Serial.begin(9600);

    number_list[0] = 9; // The first  variable/element is the 0th one
    number_list[1] = 8; // The second variable/element is the 1th one
    number_list[2] = 7; // The third  variable/element is the 2th one

    for (int i = 0; i < LIST_SIZE; i++) {
        // Can you guess what gets printed out?
        Serial.println(number_list[i]);
    }
}

void loop() {}
```

If you try and access an element with an index >= the size of the array, your
program will crash, so be careful.

Finally, if you know what values should go in your array from the start,
you can use an initializer list to just assign the values to the
variables/elements the array contains:
```
#define LIST_SIZE 3

int number_list[LIST_SIZE] = {100, 50, 75};
```

Arrays can be very useful, so ask your instructor(s) more about them if
you think you want to use them.


## Challenges
1. Declare your own array variable. Make it hold 'char' type variables. The
   array should have 7 elements. Use an initializer list to store 7 letters of
   the alphabet.
2. Write a program that fills an array with interesting values using a for
   loop. "Interesting" might be "i * 2", or "0 if i is even, 1 otherwise".
   Use a second for loop to print the values and make sure things are working
   correctly.
3. Write a program that computes the mean of the values in an array. Provide
   the numbers yourself so that you can double check your program's answer.
   Be sure to use the 'float' type, and use an array size of 5.
4. `(Extra)` Make up one!
