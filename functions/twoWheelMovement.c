// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none

#define DIAMETER 5.715
#define CIRCUMFERENCE PI * DIAMETER
#define PPR 360.0

int getSingleEncoderValue()
{
	int value = (abs(nMotorEncoder[leftFront]) + abs(nMotorEncoder[rightFront])) / 2;
	return value;
}

float cmToClicks(float centimeters)
{
	float clicks = centimeters * PPR / CIRCUMFERENCE;
	return clicks;
}

float clicksToCm(float clicks)
{
	float centimeters = clicks * CIRCUMFERENCE / PPR;
	return centimeters;
}

void setMotors(int left, int right)
{
	motor[leftFront] = left;
	motor[rightFront] = right;
}

void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[leftFront] = 0;
}

void leftTurn(const int power)
{
	setMotors(-power, power);
}

void rightTurn(const int power)
{
	setMotors(power, -power);
}

void forward(const int power)
{
	setMotors(power, power);
}

void backward(const int power)
{
	setMotors(-power, -power);
}



// Function: stopMotors
// this function stops all the motors
// Parameters: none
//Outputs: none
void stopMotors()
{
	setMotors(0,0);
}

int rescale(const int j)
{
	return j*100/128;
}

void setMotion(const int y1, const int y2)
{
	setMotors(rescale(y1), rescale(y2));
}

void strafe(int x1, int x2)
{
	stopMotors();
}
