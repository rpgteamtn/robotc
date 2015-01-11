// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none

#define DIAMETER 10.0 //centimeters
#define CIRCUMFERENCE PI * DIAMETER
#define PPR 1120.0

int getSingleEncoderValue()
{
	int value = (abs(nMotorEncoder[leftFront]) + abs(nMotorEncoder[rightFront]) / 2);
	return value;
}

void setMotors(const int lfPower, const int lbPower, const int rfPower, const int rbPower)
{
	motor[leftFront] = lfPower;
	motor[leftBack] = lbPower;
	motor[rightFront] = rfPower;
	motor[rightBack] = rbPower;
}

void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
}

float cmToClicks(float centimeters)
{
	float clicks = centimeters * 280 / CIRCUMFERENCE;
	return clicks;
}

float clicksToCm(float clicks)
{
	float centimeters = clicks * CIRCUMFERENCE / 280;
	return centimeters;
}

void leftTurn(const int power)
{
	setMotors(-power, -power, power, power);
}

void rightTurn(const int power)
{
	setMotors(power, power, -power, -power);
}

void forward(const int power)
{
	setMotors(power, power, power, power);
}

void backward(const int power)
{
	setMotors(-power, -power, -power, -power);
}
// Function: stopMotors
// this function stops all the motors
// Parameters: none
//Outputs: none
void stopMotors()
{
	setMotors(0, 0, 0, 0);
}

int rescale(const int j)
{
	return j*100/128;
}

void setMotion(const int y1, const int y2)
{
	setMotors(rescale(y1), rescale(y1), rescale(y2), rescale(y2));
}

void strafe(const int forward)
{
	int reverse = -1 * forward;
	setMotors(reverse, forward, forward, reverse);
}

void lift(const int power)
{
	motor[liftRight] = power;
	motor[liftLeft] = power;
}

void spin(const int power)
{
	motor[spinner] = power;
}

void stopLiftMotors()
{
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
	//motor[spinner] = 0;
}

void resetLiftEncoders()
{
	nMotorEncoder[liftRight] = 0;
	nMotorEncoder[liftLeft] = 0;
}

int getLiftEncoder()
{
	int value = (abs(nMotorEncoder[liftLeft]) + abs(nMotorEncoder[liftRight]) / 2);
	return value;
}
