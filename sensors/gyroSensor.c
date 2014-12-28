#pragma systemFile

#ifndef GYRO_SENSOR
#define GYRO_SENSOR true

#include "hitechnic-gyro.h"

#define MEASUREMENT_MS 25

/*#ifndef gyro
#define gyro	1
#endif*/

// Function: gyroTurn
// Parameters:
//	iDegrees:		Number of degrees to turn
// Monitor the Gyro Sensor and return when the correct number
// of degrees is reached.
void gyroLeftTurn(float fDegrees, int speed)
{
//	wait1Msec(1000);
	HTGYROstartCal(gyro);
	wait1Msec(100);

	float	fCurrent = 0.0;
	float fRotSpeed = 0.0;

	leftTurn(speed);

	do
	{
		wait1Msec(MEASUREMENT_MS);
		fRotSpeed = HTGYROreadRot(gyro);

		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0);
	} while (abs(fCurrent) < fDegrees);
}

void gyroRightTurn(float fDegrees, int speed)
{
	HTGYROstartCal(gyro);
	wait1Msec(100);

	float	fCurrent = 0.0;
	float fRotSpeed = 0.0;

	rightTurn(speed);

	do
	{
		wait1Msec(MEASUREMENT_MS);
		fRotSpeed = HTGYROreadRot(gyro);

		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0);
	} while (abs(fCurrent) < fDegrees);
}

#endif
