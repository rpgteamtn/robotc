/*approach() makes the robot come closer until it is "distance"
away from whatever you are trying to approach (the goal)*/
void approach(float distance)
{
	int point = SensorValue[sonar]; //this defines a certain point
	while (SensorValue[sonar] > distance)//until the robot reaches its goal...
	{
		/*if the robot's current value is smaller
		than it was a minute ago (it's still lined up),
		move forward*/
		if (SensorValue[sonar] <= point)

		{
			forward(50);
		}
		/*if the robot's value is larger than it was a minute ago, it's no longer
		lined up with the goal.  So, turn right until the robot is lined up again*/
		else if (SensorValue[sonar] > point)
		{
			do
			{
				rightTurn(50);
				clearTimer(T1);
			} while ((SensorValue[sonar] > point) && (time1[T1] <= 50));
				if (SensorValue[sonar] > point)
			{
				do
				{
					leftTurn(50);
				}
				while (SensorValue[sonar] > point);
			}
		}
		/*I don't know what happened, so stop*/
		else
		{
			stopMotors();
		}
		/*reset point*/
		point = SensorValue[sonar];
	}
	stopMotors();
}

void align(float distance, eDirection direct)
{
	//int minimum = SensorValue[sonar];
	while (SensorValue[sonar] > distance/* || SensorValue[sonar] > (minimum + 5)*/)//until the robot reaches its goal...
	{
		/*if the robot's current value is smaller
		than it was a minute ago (it's still lined up),
		move forward*/
		if (direct == dLeft)
		{
			strafe(-50);
		}
		/*if the robot's value is larger than it was a minute ago, it's no longer
		lined up with the goal.  So, turn right until the robot is lined up again*/
		else if (direct == dRight)
		{
			strafe(50);
		}
		/*I don't know what happened, so stop*/
		else
		{
			stopMotors();
		}
		/*reset point*/
		/*if (SensorValue[sonar] < minimum)
		{
			minimum = SensorValue[sonar];
		}*/
	}
	stopMotors();
}

/*This function just has the robot turn right until
it finds an object within the goal distance*/
void findGoal(float distance)
{
	while (SensorValue[sonar] > distance)
	{
		rightTurn(50);
	}
	stopMotors();
}
