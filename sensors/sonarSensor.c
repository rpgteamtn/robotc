/*approach() makes the robot come closer until it is "distance"
away from whatever you are trying to approach (the goal)*/
void approach(float distance)
{
	int point = sensorValue[sonar]; //this defines a certain point
	while (sensorValue[sonar] > distance)//until the robot reaches its goal...
	{
		/*if the robot's current value is smaller
		than it was a minute ago (it's still lined up),
		move forward*/
		if (sensorValue[sonar] <= point)

		{
			forward(50);
		}
		/*if the robot's value is larger than it was a minute ago, it's no longer
		lined up with the goal.  So, turn right until the robot is lined up again*/
		else if (sensorValue[sonar] > point)
		{
			do
			{
				rightTurn(50);
			} while (sensorValue[sonar] > point)
		}
		/*I don't know what happened, so stop*/
		else
		{
			stopMotors();
		}
		/*reset point*/
		point = sensorValue[sonar];
	}
	stopMotors();
}


/*This function just has the robot turn right until
it finds an object within the goal distance*/
void findGoal(float distance)
{
	while (sensorValue[sonar] > distance)
	{
		rightTurn(50);
	}
	stopMotors();
}
