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
void gyroTurn(float power, float fDegrees, eDirection direct)
{
	HTGYROstartCal(gyro);

	float	fCurrent = 0.0;
	float fRotSpeed = 0.0;

	if (direct == dLeft)
	{
		leftTurn(power);
	}
	else
	{
		rightTurn(power);
	}
	do
	{

		wait1Msec(MEASUREMENT_MS);
		string text;
		fRotSpeed = HTGYROreadRot(gyro);
		sprintf(text, "rot = %f", fRotSpeed);
		displayCenteredTextLine(4, text);
		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0);

		sprintf(text, "current = %f", fCurrent);
		displayCenteredTextLine(5, text);
	} while (abs(fCurrent) <= fDegrees);
	stopMotors();
}
#endif
