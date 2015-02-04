#define COLLECT 185
#define DUMP 165
#define CATCHUP 150 //Degree measure for when goal capture is released
#define CATCHDOWN 0 //Degree measure for when goal capture is down
#define SPINNEROUT 145
#define SPINNERIN 35

void tipCatch()
{
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 0; 					// Max Speed
	servo[tipperServo] = COLLECT;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
}

void tipRelease()
{
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 10; 					// Max Speed
	servo[tipperServo] = DUMP;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
}

void goalCatch()
{
	int iCRate = servoChangeRate[goalCapture];	// Save change rate
	servoChangeRate[goalCapture] = 0; 					// Max Speed
	servo[goalCapture] = CATCHDOWN;					    // Set servo position
	wait1Msec(20);
	servoChangeRate[goalCapture] = iCRate;			// Reset the servo
}

void goalRelease()
{
	int iCRate = servoChangeRate[goalCapture];	// Save change rate
	servoChangeRate[goalCapture] = 0; 					// Max Speed
	servo[goalCapture] = CATCHUP;					      // Set servo position
	wait1Msec(20);
	servoChangeRate[goalCapture] = iCRate;			// Reset the servo
}


void spinnerRelease()
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNEROUT;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}

void spinnerCatch()
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNERIN;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}
