#include "BYJ48_Stepper.h"

// public:
BYJ48_Stepper::BYJ48_Stepper(int in_1, int in_2, int in_3, int in_4) {
/**
 * Basic constructor for a BYJ48_Stepper controller object.
 *
 * Constructs the object, defaulting to a clockwise direction and a speed
 * of 1 rpm.
 *
 * Inputs
 *   in_1: the pin corresponding to IN1 on the driver board.
 *   in_2: the pin corresponding to IN2 on the driver board.
 *   in_3: the pin corresponding to IN3 on the driver board.
 *   in_4: the pin corresponding to IN4 on the driver board.
 */
    this->in_1 = in_1;
    pinMode(this->in_1, OUTPUT);
    this->in_2 = in_2;
    pinMode(this->in_2, OUTPUT);
    this->in_3 = in_3;
    pinMode(this->in_3, OUTPUT);
    this->in_4 = in_4;
    pinMode(this->in_4, OUTPUT);

    this->direction = CW;

    this->step_time = DEFAULT_PHASE_TIME;
}

int BYJ48_Stepper::set_clockwise() {
/**
 * Sets the motor direction to clockwise.
 */
    this->direction = CW;
}

int BYJ48_Stepper::set_counter_clockwise() {
/**
 * Sets the motor direction to counter-clockwise.
 */
    this->direction = CCW;
}

int BYJ48_Stepper::set_speed(float rpm) {
/**
 * Sets the motor speed to the given speed, constrained to an appropriate range.
 */
    this->step_time = DEFAULT_PHASE_TIME / constrain(rpm, MIN_RPM, MAX_RPM);
}

int BYJ48_Stepper::turn(float revolutions) {
/**
 * Causes the motor to turn the specified number of revolutions.
 */
    this->step(revolutions * STEPS_PER_ROTATION);
}

int BYJ48_Stepper::step(int n_steps) {
/**
 * Causes the motor to turn the specified number of steps.
 */
    // Time that the next step of the motor will be complete.
    unsigned long next_step_complete = micros();

    for (int i = 0; i < n_steps; i++) {
        if (this->direction == CW) {
            for (int phase = 7; phase >= 0; phase--) {
                next_step_complete = micros() + this->step_time;
                set_motor_phase(phase);
                while (micros() < next_step_complete) {};
            }
        } else {
            for (int phase = 0; phase < 8; phase++) {
                next_step_complete = micros() + this->step_time;
                set_motor_phase(phase);
                while (micros() < next_step_complete) {};
            }
        }
    }
}

// private:
int BYJ48_Stepper::set_motor_phase(const int phase) {
/**
 * Sets the IO pins to execute the given phase of the motor cycle.
 */
    switch (phase) {
        case 0:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_2, LOW);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, HIGH);
        break;
        case 1:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_3, HIGH);
            digitalWrite(this->in_4, HIGH);
        break;
        case 2:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_2, LOW);
            digitalWrite(this->in_3, HIGH);
            digitalWrite(this->in_4, LOW);
        break;
        case 3:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_2, HIGH);
            digitalWrite(this->in_3, HIGH);
            digitalWrite(this->in_4, LOW);
        break;
        case 4:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_2, HIGH);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, LOW);
        break;
        case 5:
            digitalWrite(this->in_1, HIGH);
            digitalWrite(this->in_2, HIGH);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, LOW);
        break;
        case 6:
            digitalWrite(this->in_1, HIGH);
            digitalWrite(this->in_2, LOW);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, LOW);
        break;
        case 7:
            digitalWrite(this->in_1, HIGH);
            digitalWrite(this->in_2, LOW);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, HIGH);
        break;
        default:
            digitalWrite(this->in_1, LOW);
            digitalWrite(this->in_2, LOW);
            digitalWrite(this->in_3, LOW);
            digitalWrite(this->in_4, LOW);
        break;
    }
}


//class BYJ48_StepperMotor {
// public:
//  static const int CW  = -1;
//  static const int CCW =  1;
//  static constexpr float MAX_RPM = 17.3;
//  static constexpr float MIN_RPM =  0.5;
//  static const int STEPS_PER_ROTATION = 512;
//  static const int PHASES_PER_STEP = 8;
//  static const int DEFAULT_SPEED = 1;
//  // Time for 1 rev./min; in usec; ~14468.
//  static const uint64_t DEFAULT_PHASE_TIME =
//    (1000L * 1000L * 60L) / (STEPS_PER_ROTATION * PHASES_PER_STEP);
//
//
//  BYJ48_StepperMotor(int _, int in_1, int in_2, int in_3, int in_4) {
//    this->in_1 = in_1;
//    pinMode(this->in_1, OUTPUT);
//    this->in_2 = in_2;
//    pinMode(this->in_2, OUTPUT);
//    this->in_3 = in_3;
//    pinMode(this->in_3, OUTPUT);
//    this->in_4 = in_4;
//    pinMode(this->in_4, OUTPUT);
//
//    this->direction = CW;
//
//    this->step_time = DEFAULT_PHASE_TIME;
//  }
//
//  int set_clockwise() {
//    this->direction = CW;
//  }
//
//  int set_counter_clockwise() {
//    this->direction = CCW;
//  }
//
//  int set_speed(float rpm) {
//    this->step_time = DEFAULT_PHASE_TIME / constrain(rpm, MIN_RPM, MAX_RPM);
//  }
//
//  int turn(float revolutions) {
//    this->step(revolutions * STEPS_PER_ROTATION);
//  }
//
//  int step(int n_steps) {
//    // Time that the next step of the motor will be complete.
//    unsigned long next_step_complete = micros();
//
//    for (int i = 0; i < n_steps; i++) {
//      if (this->direction == CW) {
//        for (int phase = 7; phase >= 0; phase--) {
//          next_step_complete = micros() + this->step_time;
//          set_motor_phase(phase);
//          while (micros() < next_step_complete) {};
//        }
//      } else {
//        for (int phase = 0; phase < 8; phase++) {
//          next_step_complete = micros() + this->step_time;
//          set_motor_phase(phase);
//          while (micros() < next_step_complete) {};
//        }
//      }
//    }
//  }
//
// private:
//  int set_motor_phase(const int phase) {
//    switch (phase) {
//      case 0:
//        digitalWrite(this->in_1, LOW);
//        digitalWrite(this->in_2, LOW);
//        digitalWrite(this->in_3, LOW);
//        digitalWrite(this->in_4, HIGH);
//     break;
//     case 1:
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_3, HIGH);
//       digitalWrite(this->in_4, HIGH);
//     break;
//     case 2:
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_2, LOW);
//       digitalWrite(this->in_3, HIGH);
//       digitalWrite(this->in_4, LOW);
//     break;
//     case 3:
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_2, HIGH);
//       digitalWrite(this->in_3, HIGH);
//       digitalWrite(this->in_4, LOW);
//     break;
//     case 4:
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_2, HIGH);
//       digitalWrite(this->in_3, LOW);
//       digitalWrite(this->in_4, LOW);
//     break;
//     case 5:
//       digitalWrite(this->in_1, HIGH);
//       digitalWrite(this->in_2, HIGH);
//       digitalWrite(this->in_3, LOW);
//       digitalWrite(this->in_4, LOW);
//     break;
//       case 6:
//       digitalWrite(this->in_1, HIGH);
//       digitalWrite(this->in_2, LOW);
//       digitalWrite(this->in_3, LOW);
//       digitalWrite(this->in_4, LOW);
//     break;
//     case 7:
//       digitalWrite(this->in_1, HIGH);
//       digitalWrite(this->in_2, LOW);
//       digitalWrite(this->in_3, LOW);
//       digitalWrite(this->in_4, HIGH);
//     break;
//     default:
//       digitalWrite(this->in_1, LOW);
//       digitalWrite(this->in_2, LOW);
//       digitalWrite(this->in_3, LOW);
//       digitalWrite(this->in_4, LOW);
//     break;
//    }
//  }
//
//  int in_1;
//  int in_2;
//  int in_3;
//  int in_4;
//
//  int direction;
//
//  int step_time;
//};
