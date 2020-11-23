#include "L298N_MotorDriver.h"

// Make a motor object 
// Arduino Pin 3 ( pin must have PWM capability), 
//   is connected to the driver board pin EN (enable)
// Arduino Pin 2, is connected to the driver board pin IN1 (H-bridge path 1)
// Arduino Pin 4, is connected to the driver board pin IN2 (H-bridge path 2)
// Set the pins for one motor which uses this dual driver board.
L298N_MotorDriver motor(3,2,4);

// Define the Pin on which the potentiometer is connected
int potiPin = A0;

void setup() {
  
  pinMode(potiPin, INPUT);
  
  motor.setDirection(false);   // Sets the direction ( depending on the wiring ) 
  motor.enable();              // Turns the motor on
}

void loop() {

	// Read the voltage value of the potentiometer
	int potiValue = analogRead(potiPin);
	
	// We need to scale the potiValue down, so we are in a valid speed range
	byte speed = map(potiValue, 0, 1024, 0, 255);
	
	// Sets the speed for the motor. 0 - 255
	motor.setSpeed(speed);      

	
	delay(20);
}