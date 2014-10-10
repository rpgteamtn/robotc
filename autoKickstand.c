#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)

#include "autoIR.c"
#include "measureIR"

int encodeA
int encodeB
int encodeC
int encodeD

#define distA1
#define distA2
#define distA3
#define distB1
#define distB2
#define distC1
#define distC2
#define distD1
#define distD2

void turnRight()
{
	motor[rightFront] = 100;
	motor[leftFront] = 0;
}

void turnLeft()
{
	motor[leftFront] = 100;
	motor[rightFront] = 0;
}


task main()
{

	if(nMotorEncoder[leftFront, rightFront] =encodeA)
	{
		getIRReading();
		if(reading = yeah)
		{
			go forward distA1;
			turnRight();
			go forward distA2;
			turnLeft();
			go forward distA3;
		}
	}

	else if(nMotorEncoder[leftFront, rightFront] =encodeB)
	{
		getIRReading;
		if(reading = yeah)
		{
			turnLeft();
			go forward distB1;
			turn 45 right;
			go forward distA2;
			turnLeft();
			go forward distA3;
		}
	}

	else if(nMotorEncoder <= C)
	{
		getIRReading();
		if(reading = yeah)
		{
			turnLeft();
			go forward distC1;
			turnLeft();
			go forward distC2;
		}
	}

	else if(nMotorEncoder = encodeD)
	{
		turnLeft();
		go forward distD1;
		turnRight();
		go forward distD2;
	}
}
}
