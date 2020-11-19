#include "L298N_MotorDriver.h"

// Make a motor object 
// Arduino Pin 3 ( pin must have PWM capability), 
//   is connected to the driver board pin EN (enable)
// Arduino Pin 2, is connected to the driver board pin IN1 (H-bridge path 1)
// Arduino Pin 4, is connected to the driver board pin IN2 (H-bridge path 2)
// Set the pins for one motor which uses this dual driver board.
L298N_MotorDriver motor(3,2,4);

void setup() {
  motor.setSpeed(100);         // Sets the speed for the motor. 0 - 255
  motor.setDirection(false);   // Sets the direction ( depending on the wiring ) 
  motor.enable();              // Turns the motor on
}

void loop() {


}