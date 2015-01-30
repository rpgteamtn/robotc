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
void travelDistance(const float distance, const eWay direct)
{
	resetEncoders();

	int encoderValue = getSingleEncoderValue();

	while(distance > abs(calculateDist(encoderValue)))
	{
		if (direct == dForward)
		{
			forward(50);
			encoderValue = getSingleEncoderValue();
			wait1Msec(1);
		}
		else if (direct == dBackward)
		{
			backward(50);
			encoderValue = getSingleEncoderValue();
			wait1Msec(1);
		}
	}
	stopMotors();
}

// Set the lift to a predetermined height
task taskSetLiftHeight()
{
	bTaskRunning = true;
	bStop = false;

	int lrEnc = (nMotorEncoder[liftRight]);
	int height = iHeight;

	// Go until height is set or we need to stop
	while((bStop == false) && lrEnc != height) {
		if(lrEnc > height) {
			lift(-30);
			} else if(lrEnc < height) {
			lift(30);
		}
		// Let main task run
		wait1Msec(100);
		lrEnc = (nMotorEncoder[liftRight]);
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
