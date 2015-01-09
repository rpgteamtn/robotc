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


void travelDistance(const float distance)//distance in
{
	resetEncoders();

	int encoderValue = getSingleEncoderValue();
	/*
	string text;
	sprintf(text, "degrees = %f", degreesToTravel);
	displayCenteredTextLine(3, text);
	sprintf(text, "encoder = %i", encoderValue);
	displayCenteredTextLine(4, text);
	wait1Msec(3000);
	*/
	while(distance > calculateDist(encoderValue))
	{
		backward(100);
		encoderValue = getSingleEncoderValue();
		wait1Msec(1);
	}
	stopMotors();
}

void liftHeight(const int height)//height in clicks
{
	int lrEnc = (nMotorEncoder[liftRight]);

	while(lrEnc != height)
	{
		if(lrEnc > height)
		{
			lift(-30);
		}
		else if(lrEnc < height)
		{
			lift(30);
		}
	}
	stopLiftMotors();
}
