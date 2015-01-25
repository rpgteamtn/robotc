void lift(const int power) //Syncs both lift motors lift functions are 1 command
{
	motor[liftRight] = power; //Right lift motor
	motor[liftLeft] = power;  //Left lift motor
	wait1Msec(10); //Wait a moment (for lift tasks)
}

void spin(const int power) //Run the spinner
{
	motor[spinner] = power; //Spinner motor goes a power
	wait1Msec(10);
}

void stopLiftMotors() //Stop lift motors
{
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
	wait1Msec(10);
}

void resetLiftEncoders() //Sets lift encoders to 0 for precise encoder-regulated movements
{
	nMotorEncoder[liftRight] = 0;
	nMotorEncoder[liftLeft] = 0;
	wait1Msec(10);
}

int getLiftEncoder() //Get the average value of the lift encoders
{
	int value = (abs(nMotorEncoder[liftLeft]) + abs(nMotorEncoder[liftRight]) / 2);
	return value;
}


void spinnerOut() //Release the spinner (Put it down)
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNEROUT;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}

void spinnerIn() //Pull spinner "holder" in
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNERIN;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}
