#pragma systemFile

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
	tHTGYRO gyroSensor;
	initSensor(&gyroSensor, msensor_S1_3);

	sensorCalibrate(&gyroSensor);

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
		readSensor(&gyroSensor);
		fRotSpeed = gyroSensor.rotation;

		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0);
		displayCenteredTextLine(1, "RotSpeed = %f", fRotSpeed);
		displayCenteredTextLine(2, "GyroValue = %f", fCurrent);
	} while (abs(fCurrent) < fDegrees);
	stopMotors();
}
