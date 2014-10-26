float calculateDist(const int encoderValue)
{
	float dist = encoderValue / 360.0 * CIRCUMFERENCE;
	return dist;
}

float calculateDegrees(const float dist)
{
	float degrees = dist / CIRCUMFERENCE * 360.0;
	return degrees;
}


void travelDistance(const float distance)
{
	resetEncoders();

	float degreesToTravel = calculateDegrees(distance);
	int encoderValue = getSingleEncoderValue();
/*
	string text;
	sprintf(text, "degrees = %f", degreesToTravel);
	displayCenteredTextLine(3, text);
	sprintf(text, "encoder = %i", encoderValue);
	displayCenteredTextLine(4, text);
	wait1Msec(3000);
*/
	while(degreesToTravel > encoderValue)
	{
		forward(100);
		encoderValue = getSingleEncoderValue();
	}
	stopMotors();
}
