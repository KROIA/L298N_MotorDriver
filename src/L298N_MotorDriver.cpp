#include "L298N_MotorDriver.h"

L298N_MotorDriver::L298N_MotorDriver(byte enable, byte inA, byte inB)
{
	m_enable_pin  = enable;
	m_inA_pin     = inA;
	m_inB_pin     = inB;
	
	pinMode(m_enable_pin,OUTPUT);
	pinMode(m_inA_pin,OUTPUT);
	pinMode(m_inB_pin,OUTPUT);
	
	this->disable();
	this->setSpeed(0);
	this->setDirection(false);
}
L298N_MotorDriver::~L298N_MotorDriver()
{
	
}

void L298N_MotorDriver::setSpeed(byte speed)
{
	m_speed = speed;
	
	if(m_enable)
	{
		analogWrite(m_enable_pin,m_speed);
	}
}
byte L298N_MotorDriver::getSpeed()
{
	return m_speed;
}

void L298N_MotorDriver::setDirection(bool direction)
{
	m_direction = direction;
	
	if(m_direction)
	{
		digitalWrite(m_inB_pin,false);
		#ifndef L298N_MotorDriver__DISABLE_DELAY
			delayMicroseconds(10);
		#endif
		digitalWrite(m_inA_pin,true);
	}
	else
	{
		digitalWrite(m_inA_pin,false);
		#ifndef L298N_MotorDriver__DISABLE_DELAY
			delayMicroseconds(10);
		#endif
		digitalWrite(m_inB_pin,true);
	}		
}
bool L298N_MotorDriver::getDirection()
{
	return m_direction;
}

void L298N_MotorDriver::enable()
{
	this->setEnabled(true);
}
void L298N_MotorDriver::disable()
{
	this->setEnabled(false);
}
void L298N_MotorDriver::setEnabled(bool enabled)
{
	m_enable = enabled;
	if(m_enable)
	{
		analogWrite(m_enable_pin,m_speed);
	}
	else
	{
		analogWrite(m_enable_pin,0);
	}
}
bool L298N_MotorDriver::isEnabled()
{
	return m_enable;
}





