/**
 * An interface for ULN2003 chip to drive the 28BYJ-48 stepper motor.
 *
 * This code is designed to allow a microcontroller to properly interface with
 * a ULN2003 breakout to drive a 28BYJ-48 stepper motor. The code is meant to
 * provide a simple, blocking interface to drive the motor. The code can drive
 * the motor at 0.5 rpm at the slowest, and 17.3 rpm at the fastest. Attempts
 * to drive the motor at speeds outside this range are clamped to that range.
 *
 * Possible Improvements:
 *   1. Improve the minimum speed; currently moving slower leads to
 *      inaccuracy (running at 0.25 rpm takes only 2:15 for a revolution).
 *      Perhaps adding additional delays could help.
 *   2. Improve the speed on the high range; currently moving faster leads
 *      to motor lock-up. It is possible that the motor is not meant to move
 *      any faster. The clockwise direction seems to be capable of going
 *      faster without any changes, but for interface simplicity, the limit
 *      was kept the same for both directions. Also, this hasn't been timed
 *      for accuracy.
 */

#ifndef _BYJ48_STEPPER_
#define _BYJ48_STEPPER_ 1

#include <Arduino.h>

class BYJ48_Stepper {
 public:
    static const int CW  = -1;
    static const int CCW =  1;
    static constexpr float MAX_RPM = 17.3;
    static constexpr float MIN_RPM =  0.5;

    static const int STEPS_PER_ROTATION = 512;
    static const int PHASES_PER_STEP = 8;
    // Time for 1 rev./min; in usec; ~14468.
    static const uint64_t DEFAULT_PHASE_TIME =
        (1000L * 1000L * 60L) / (STEPS_PER_ROTATION * PHASES_PER_STEP);

    BYJ48_Stepper(int in_1, int in_2, int in_3, int in_4);

    int set_clockwise();
    int set_counter_clockwise();
    int set_speed(float rpm);

    int turn(float revolutions);
    int step(int n_steps);

 private:
    int set_motor_phase(const int phase);

    int in_1;
    int in_2;
    int in_3;
    int in_4;
    int direction;
    int step_time;
};

#endif