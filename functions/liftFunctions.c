void lift(const int power) //Syncs both lift motors lift functions are 1 command
{
	motor[liftMotor] = -power; //lift motor
	wait1Msec(10); //Wait a moment (for lift tasks)
}

void spin(const int power) //Run the spinner
{
	motor[spinner] = -power; //Spinner motor goes a power
	wait1Msec(10);
}

void stopLiftMotors() //Stop lift motors
{
	motor[liftMotor] = 0;
	wait1Msec(10);
}

void resetLiftEncoders() //Sets lift encoders to 0 for precise encoder-regulated movements
{
	nMotorEncoder[liftMotor] = 0;
	wait1Msec(10);
}

int getLiftEncoder() //Get the average value of the lift encoders
{
	int value = nMotorEncoder[liftMotor];
	return value;
}

void liftDown()
{
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 10; 					// Max Speed
	servo[tipperServo] = COLLECT;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
	while(abs(getLiftEncoder()) > 0 && (TSreadState(LTOUCH) != 1))
	{
		lift(-100);
	}
}

void goalCenter(bool useLift)
{
	if (useLift == false)
	{
		return;
	}
	while(abs(getLiftEncoder()) < CENTERGOAL)
	{
		lift(100);
	}
	stopLiftMotors();
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 0; 					// Max Speed
	servo[tipperServo] = DUMP;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
	wait1Msec(3000);
	liftDown();
	stopLiftMotors();
}

void goalHigh(bool useLift)
{
	if (useLift == false)
	{
		return;
	}
	while(abs(getLiftEncoder()) < GOAL90)
	{
		lift(100);
	}
	stopLiftMotors();
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 0; 					// Max Speed
	servo[tipperServo] = DUMP;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
	wait1Msec(3000);
	liftDown();
	stopLiftMotors();
}

void goalMed(bool useLift)
{
	if (useLift == false)
	{
		return;
	}
	while(abs(getLiftEncoder()) < GOAL60)
	{
		lift(100);
	}
	stopLiftMotors();
	int iCRate = servoChangeRate[tipperServo];	// Save change rate
	servoChangeRate[tipperServo] = 0; 					// Max Speed
	servo[tipperServo] = DUMP;					// Set servo position
	wait1Msec(20);
	servoChangeRate[tipperServo] = iCRate;
	wait1Msec(3000);
	liftDown();
	stopLiftMotors();
}
