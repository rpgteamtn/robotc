//
//
//
//
//
#pragma systemFile

#ifndef GYRO_SENSOR
#define GYRO_SENSOR true

#include "gyro.c"

#define MEASUREMENT_MS 25

#ifndef gyro
#define gyro	1
#endif

// Function: gyroTurn
// Parameters:
//	iDegrees:		Number of degrees to turn
// Monitor the Gyro Sensor and return when the correct number
// of degrees is reached.
void gyroTurn(float fDegrees)
{
	float	fCurrent = 0.0;
	float fRotSpeed = 0.0;

	do {
		wait1Msec(MEASUREMENT_MS);
		fRotSpeed = HTGYROreadRot(gyro);

		fCurrent += fRotSpeed * (MEASUREMENT_MS / 1000.0);
	} while (abs(fCurrent) <= fDegrees);

}
#endif
