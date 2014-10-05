// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none

void setMotors(const int lfPower, const int lbPower, const int rfPower, const int rbPower)

{
	motor[leftFront] = lfPower;
	motor[leftBack] = lbPower;
	motor[rightFront] = rfPower;
	motor[rightBack] = rbPower;
}

void leftTurn(const int power);
{
	setMotors(-power, -power, power, power);
}

void rightTurn(const int power);
{
	setMotors(power, power, -power, -power);
}

void forward(const int power);
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
