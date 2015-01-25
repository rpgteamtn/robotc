#pragma systemFile

#ifndef GYRO_SENSOR //just in case there's no gyro, but we're still calling the function
#define GYRO_SENSOR true

#include "hitechnic-gyro.h"
#include "rpgCommon.c"

#define MEASUREMENT_MS 25 //Number of milliseconds

void gyroTurn(float power, float fDegrees, eDirection direct)
{//Robot turns at a specific power, a certain angle, either right or left
	HTGYROstartCal(gyro); //Activate gyroscope
	wait1Msec(100); //Let it adjust

	float	fCurrent = 0.0; //Set heading to 0 degrees
	float fRotSpeed = 0.0; //Current rotational speed is 0

	if (direct == dLeft) //If told to turn left
	{
		leftTurn(power); //Set motors to turn left
	}
	else //If tol to turn right
	{
		rightTurn(power); //Set motors to turn right
	}

	do //Loop through following until conditions are met
	{
		wait1Msec(MEASUREMENT_MS); //Give a moment to recalibrate
		fRotSpeed = HTGYROreadRot(gyro); //Rotation speed is now the gyro's input

		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0); //Current heading is what is was before
		//plus the value of the rate of turn times the amount of time that rate value was taken
	} while (abs(fCurrent) < fDegrees); //Repeat until the heading is the amount told to turn
	stopMotors(); //You got there, now stop
}

#endif
