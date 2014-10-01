// Function: setMotors
// this function lets you set all the motors in a single line
// Parameters:
//	rfPower: int for the power of the right front wheel
//	rbPower: int for the power of the right back wheel
//	lfPower: int for the power of the left front wheel
//  lbPower: int for the power of the left back wheel
//Outputs: none
void setMotors(const int leftFront, const int leftBack, const int rightFront, const int rightBack)
{
	motor[leftFront] = leftFront;
	motor[leftBack] = leftBack;
	motor[rightFront] = rightFront;
	motor[rightBack] = rightBack;
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

void strafe(int x1, int x2)
{
	stopMotors();
}
