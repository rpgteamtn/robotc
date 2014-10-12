//#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
//#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
//#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)

//#include "twoWheelMovement.c"

typedef enum {dRight, dLeft } eDirection;

float fWheelCir;
float fTurnCir;
int iWheelDeg;
float fRobotWid = 4.625;
float fWheelDiam = 2.25;

float mmTOinch(float mm)
{
	return mm*25.4;
}

void turn(int deg, eDirection direct)
{
	resetEncoders();
	//fWheelCir = mmTOinch(fWheelCir);

	if(fWheelCir == NULL)
	{
		fWheelCir = fWheelDiam*PI;
	}

	if(fTurnCir == NULL)
	{
		fTurnCir = fRobotWid*PI;
	}

	iWheelDeg = fWheelCir / fTurnCir * deg;

	if(direct == dRight)
	{
		while((abs(nMotorEncoder[leftFront]) < iWheelDeg*8)||(abs(nMotorEncoder[rightFront]) < iWheelDeg*8))
		{
			rightTurn(70);
		}
	}

	 if(direct == dLeft)
	{
		while((abs(nMotorEncoder[rightFront]) < iWheelDeg*8)||(abs(nMotorEncoder[leftFront]) < iWheelDeg*8))
		{
			leftTurn(70);
		}
	}
}
/*
task main()
{
 turn(90, dRight);
 stopMotors();
 wait1Msec(1000);
 turn(180, dLeft);
 stopMotors();
 wait1Msec(1000);
 turn(90, dRight);
 stopMotors();
}
*/
