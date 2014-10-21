void rightTurnDegrees(int degrees, int power)
{
	int goal = (SensorValue[gyro] + degrees);  // 'goal' is be the current gyro reading + our turning degrees
	while(SensorValue[gyro] < goal)   // while the gyro sensor reading is less than our goal:
	{
		rightTurn(power);
	}
	stopMotors();
}

void leftTurnDegrees(int degrees, int power)
{
	int goal = (SensorValue[gyro] - degrees);  // 'goal' is be the current gyro reading + our turning degreess
	while(SensorValue[gyro] > goal)   // while the gyro sensor reading is less than our goal:
	{
		leftTurn(power);
	}
	stopMotors();
}
