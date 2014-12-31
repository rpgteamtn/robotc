#include "fourWheelMovement.c"

int target = 00 ;// wanted hight in CM
bool bRunning = false;// is running
bool otherTask = false;

task Lift()
{
	resetLiftEncoders();
	int encoderLift = getEncoder();

	while((bRunning == true) &&  (encoderLift != target))
	{
		lift(70);
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
