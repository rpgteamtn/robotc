// Setup a global variable to control lift tasks
bool	bTaskRunning = false;
bool	bStop = false;
int		iHeight = 0;

float calculateDist(const int encoderValue)
{
	float dist = encoderValue / PPR * CIRCUMFERENCE;
	return dist;
}

float calculateDegrees(const float dist)
{
	float degrees = dist / CIRCUMFERENCE * PPR;
	return degrees;
}

//distance in cm
void travelDistance(float distance, const eWay direct)
{
	resetEncoders();

	distance = cmToClicks(distance);

	displayCenteredTextLine(6, "dist = %f", distance);

	while(distance> abs(nMotorEncoder[leftFront]))
	{
		if (direct == dForward)
		{
			forward(50);
		}

		if (direct == dBackward)
		{
			backward(50);
		}
	}
	stopMotors();
}

// Set the lift to a predetermined height
task taskSetLiftHeight()
{
	bTaskRunning = true;
	bStop = false;

	int liftEnc = (nMotorEncoder[liftMotor]);
	int height = iHeight;

	// Go until height is set or we need to stop
	while((bStop == false) && liftEnc != height) {
		if(liftEnc > height) {
			lift(-30);
			} else if(liftEnc < height) {
			lift(30);
		}
		// Let main task run
		wait1Msec(100);
		liftEnc = (nMotorEncoder[liftMotor]);
	}
	stopLiftMotors();
	bTaskRunning = false;
}

// Stop the lift task from running
void stopLiftTask()
{
	// Task already running - stop it
	if(bTaskRunning) {
		bStop = true;
		do {
			wait1Msec(100);
		} while(bTaskRunning);
	}
}

// set the lift to a specific height
void liftHeight(const int height)//height in clicks
{
	stopLiftTask();
	iHeight = height;
	startTask(taskSetLiftHeight);
}
