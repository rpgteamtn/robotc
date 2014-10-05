#include "JoystickDriver.c"

#define nxtOrange 3
#define nxtLeft 2
#define nxtRight 1
#define nxtGrey 0
#define noButton -1

/* -----------------------------------------------
This is start function.
------------------------------------------------*/
void waitForStartOrButton()
{
	while (true)
	{
		getJoystickSettings(joystick);
		if (!joystick.StopPgm)      // normal FCS start condition
		{
			break;
		}

		if (nNxtButtonPressed == nxtOrange)
		{ // manual bypass start condition

			// 2 beeps and 2 seconds to get out of the way before the program starts
			playImmediateTone(1000,50);
			wait1Msec(1000);

			playImmediateTone(1000,50);
			wait1Msec(1000);

			break;
		}
	}
	return;
}
/* -----------------------------------------------
This is ___ function
------------------------------------------------*/

void waitTillNoButton()
{
	while(nNxtButtonPressed != noButton)
	{

	}
}

//.....................

void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
}
