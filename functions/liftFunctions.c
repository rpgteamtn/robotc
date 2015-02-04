void lift(const int power) //Syncs both lift motors lift functions are 1 command
{
	motor[liftMotor] = power; //lift motor
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
