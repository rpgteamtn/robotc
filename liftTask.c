#include "fourWheelMovement.c"

int target;// wanted hight in CM
int liftPower;
bool bRunning = false;// is running
bool otherTask = false;

task liftTask()
{
	int encoderLift = getLiftEncoder();

	if(encoderLift > target)
	{
		liftPower = -30;
	}

	else if(encoderLift < target)
	{
		liftPower = 70;
	}

	else
	{
		stopTask(liftTask);
	}

	while((bRunning == true) &&  (encoderLift != target))
	{
		lift(liftPower);
		if(touch == 1)
		{
			stopLiftMotors();
			bRunning = false;
		}
	}
	bRunning = false;
}

void FOO(int TARGET)// Target in CM
{
	target = cmToClicks(TARGET);

	bRunning = true;
	startTask(liftTask);

	if(bRunning == false)
	{
		stopTask(liftTask);
	}
}
