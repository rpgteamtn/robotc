void approach(float distance)
{
	point = sensorValue[sonar];
	while (sensorValue[sonar] > distance)
	{
		if (sensorValue[sonar] <= point)
		{
			forward(50);
		}
		else if (sensorValue[sonar] > point)
		{
			do
			{
				rightTurn(50);
			} while (sensorValue[sonar] > point
		}
		else
		{
			stopMotors();
		}
		point = sensorValue[sonar];
	}
	stopMotors();
}

void findGoal(float distance)
{
	while (sensorValue[sonar] > distance)
	{
		rightTurn(50);
	}
	stopMotors();
}
