#include "L298N_MotorDriver.h"

L298N_MotorDriver motor(3,2,4);
void setup() {
  // put your setup code here, to run once:
  motor.setSpeed(100);
  motor.setDirection(false);
  motor.enable();
}

void loop() {
  // put your main code here, to run repeatedly:

}