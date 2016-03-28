RGB LED
=======

Description
-----------
RGB LEDs take 3 inputs to shine with different colors from the same bulb!


Usage Notes
-----------
ALWAYS put resistors on your data lines to the RGB LED, or else it will burn
up and become unusable.

If you want to get different shades of colors from your RGB LED, you must use
PWM capable pins and use an `analogWrite` instead of a `digitalWrite`.
