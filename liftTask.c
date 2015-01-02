#include "fourWheelMovement.c"

int target;// wanted hight in CM
int liftPower;
bool bRunning = false;// is running
bool otherTask = false;

task Lift()
{
	int encoderLift = getEncoder();

	if(encoderLift > target)
	{
		liftPower = -70;
	}

	else if(encoderLift < target)
	{
		liftPower = 70;
	}

	else
	{
		stopTask(Lift);
	}

	while((bRunning == true) &&  (encoderLift != target))
	{
		lift(liftPower);
	}
	bRunning = false;
}

void FOO(int TARGET)// Target in CM
{
	target = cmToClicks(TARGET);

	bRunning = true;
	startTask(Lift);

	if(bRunning == false)
	{
		stopTask(Lift);
	}
}
