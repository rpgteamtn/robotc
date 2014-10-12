#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)

#include "twoWheelMovement.c"

typedef enum {dRight, dLeft } eDirection;
float fWheelCir;
float fTurnCir;
int iWheelDeg;
int iTurnDeg;
float fRobotWid;
float fWheelDiam;

float mmTOinch(float mm)
{
	return mm*25.4;
}

void turn(int deg, eDirection direct)
{
	//fWheelCir = mmTOinch(fWheelCir);

	if(fWheelCir == NULL)
	{
		fWheelCir = fWheelDiam*PI;
	}

	if(fTurnCir == NULL)
	{
		fTurnCir = fRobotWid*PI;
	}

	iWheelDeg = fWheelCir / fTurnCir * iTurnDeg;

	if(direct == dRight)
	{
		while((nMotorEncoder[leftFront] < iWheelDeg)||(abs(nMotorEncoder[rightFront]) < iWheelDeg))
		{
			rightTurn(70);
		}
	}

	else if(direct == dLeft)
	{
		while((nMotorEncoder[rightFront] < iWheelDeg)||(abs(nMotorEncoder[leftFront]) < iWheelDeg))
		{
			leftTurn(70);
		}
	}
}
