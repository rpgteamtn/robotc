// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none

#define DIAMETER 0
#define CIRCUMFERENCE 3.14 * DIAMETER

typedef enum {dRight, dLeft } eDirection;

float fWheelCir;
float fTurnCir;
int iWheelDeg;
float fRobotWid = 18.0; //in inches, per the regulations
float fWheelDiam = 3.937; //in inches.  the exact measurement is 100mm or 1dm

float mmTOinch(float mm)
{
	return mm / 25.4;
}

int getSingleEncoderValue()
{
	int value = motor[leftFront] + motor[leftBack] + motor[rightFront] + motor[rightBack] / 4;
	return value;
}

void setMotors(const int lfPower, const int lbPower, const int rfPower, const int rbPower)

{
	motor[leftFront] = lfPower;
	motor[leftBack] = lbPower;
	motor[rightFront] = rfPower;
	motor[rightBack] = rbPower;
}

void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
}


void leftTurn(const int power)
{
	setMotors(-power, -power, power, power);
}

void rightTurn(const int power)
{
	setMotors(power, power, -power, -power);
}

void forward(const int power)
{
	setMotors(power, power, power, power);
}

void backward(const int power)
{
	setMotors(-power, -power, -power, -power);
}
// Function: stopMotors
// this function stops all the motors
// Parameters: none
//Outputs: none
void stopMotors()
{
	setMotors(0, 0, 0, 0);
}

int rescale(const int j)
{
	return j*100/128;
}

void setMotion(const int y1, const int y2)
{
	setMotors(rescale(y1), rescale(y1), rescale(y2), rescale(y2));
}

void strafe(const int forward)
{
	int reverse = -1 * forward;
	setMotors(reverse, forward, forward, reverse);
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
		while((abs(nMotorEncoder[leftFront]) < iWheelDeg*8)||(abs(nMotorEncoder[leftBack]) < iWheelDeg*8)
			||(abs(nMotorEncoder[rightFront]) < iWheelDeg*8)||(abs(nMotorEncoder[rightBack]) < iWheelDeg*8))
		{
			rightTurn(70);
		}
	}

	 if(direct == dLeft)
	{
		while((abs(nMotorEncoder[leftFront]) < iWheelDeg*8)||(abs(nMotorEncoder[leftBack]) < iWheelDeg*8)
			||(abs(nMotorEncoder[rightFront]) < iWheelDeg*8)||(abs(nMotorEncoder[rightBack]) < iWheelDeg*8))
		{
			leftTurn(70);
		}
	}
}
