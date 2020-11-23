/*
Autor 	Alex Krieg
Datum 	23.11.2020
*/
#ifndef L298N_MOTORDTIVER_H
#define	L298N_MOTORDTIVER_H

#include "arduino.h"
#define L298N_MotorDriver__DISABLE_DELAY


class L298N_MotorDriver
{
	public:
		L298N_MotorDriver(byte enable, byte inA, byte inB);
		~L298N_MotorDriver();

		
		void setSpeed(byte speed);
		byte getSpeed();
		
		void setDirection(bool direction);
		bool getDirection();
		
		void enable();
		void disable();
		void setEnabled(bool enabled);
		bool isEnabled();

	private:

		bool m_enable;	
		byte m_inA;	
		byte m_inB;	
		byte m_speed;
		bool m_direction;
		
		byte m_enable_pin;
		byte m_inA_pin;
		byte m_inB_pin;
};
#endif