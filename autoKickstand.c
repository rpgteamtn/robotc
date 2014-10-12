#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "programs\functions\twoWheelMovement.c"
#include "drivers\hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "drivers\hitechnic-irseeker-v2.h"
//#include "programs\functions\Common.c"

#define pointA 3
#define pointB 8
#define pointC 15
#define pointD 20
#define distanceA1 36.0
#define distanceA2 24.0
#define distanceB1 23.0
#define distanceB2 10.0
#define distanceC1 15.0
#define distanceC2 13.0
#define distanceD1 3.0
#define distanceD2 18.0
#define distanceD3 13.0

void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	//nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	//nMotorEncoder[leftBack] = 0;
}

int getIRReading(tSensors ir_seeker)
{
	wait1Msec(1);                              // Wait 1 ms
	int ir = HTIRS2readACDir(ir_seeker);      // IR receiver -> ir variable
	wait1Msec(1);                              // Down time before recheck
	return ir;
}

float calculateDist(const int encoderValue)
{
	float dist = encoderValue / 360.0 * CIRCUMFERENCE;
	return dist;
}

float findIR(tSensors ir_seeker)
{
	int	ir_value = getIRReading(ir_seeker);
	repeatUntil(ir_value == 2)
	{
		backward(50);
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	int encoderValue = (nMotorEncoder[leftFront] + nMotorEncoder[rightFront]) / 2;
	return calculateDist(encoderValue);
}

void travelDistance(const float distance)
{
}

void strategyA()
{
	leftTurnDegrees(90);
	travelDistance(distanceA1);
	leftTurnDegrees(90);
	travelDistance(distanceA2);
}

void strategyB()
{
	leftTurnDegrees(90);
	travelDistance(distanceB1);
	rightTurnDegrees(90);
	travelDistance(distanceB2);
}

void strategyC()
{
	leftTurnDegrees(90);
	travelDistance(distanceC1);
	rightTurnDegrees(45);
	travelDistance(distanceC2);
}

void strategyD()
{
	travelDistance(distanceD1);
	leftTurnDegrees(90);
	travelDistance(distanceD2);
	leftTurnDegrees(90);
	travelDistance(distanceD3);
}

task main()
{
	float travelled = abs(findIR(IR));

	if(travelled <= pointA)
	{
		strategyA();
	}
	else if(travelled <= pointB)
	{
		strategyB();
	}

	else if(travelled <= pointC)
	{
		strategyC();
	}
	else(travelled <= pointD)
	{
		strategyD();
	}
}