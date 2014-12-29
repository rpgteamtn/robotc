#include "fourWheelMovement.c"

int target
bool bRun = false

void resetLiftEncoders()
{
	nMotorEncoder[rightLift] = 0;
	nMotorEncoder[leftLift] = 0;
}

int getEncoder()
{
	int value = (abs(nMotorEncoder[liftLeft]) + abs(nMotorEncoder[liftRight]) / 2);
	return value;
}

task Lift()
{
	resetLiftEncoders();
	int encoderLift = getEncoder();

	while(bRun == true &&  encoderLift =! target)
	{
		lift(70)
	}
	bRun = false;
}

void FOO(int TARGET)
{
	target = clickesToCm(TARGET)

	bRun = true
	startTask(Lift);

	if(bRun = false)
	{
		stopTask(Lift)
	}
}
