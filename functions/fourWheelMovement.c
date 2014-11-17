// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none

#define DIAMETER 10 //centimeters
#define CIRCUMFERENCE PI * DIAMETER

int getSingleEncoderValue()
{
	int value = (abs(nMotorEncoder[leftFront]) +
	             abs(nMotorEncoder[leftBack]) +
	             abs(nMotorEncoder[rightFront]) +
	             abs(nMotorEncoder[rightBack])) / 4;
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
void leftTurnDegrees(const int degrees)
{
}

void rightTurnDegrees(const int degrees)
{
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
