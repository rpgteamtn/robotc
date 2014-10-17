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
	while(degreesToTravel < encoderValue)
	{
		forward(100);
		encoderValue = getSingleEncoderValue();
	}
	stopMotors();
	string text;
	sprintf(text, "distance = %f", calculateDist(encoderValue));
	displayCenteredTextLine(3, text);
}
