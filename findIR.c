#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl, encoder)

#include "twoWheelMovement.c"

task main()
{
	int	ir_value = getIRReading(ir_seeker);
	repeatUntil(ir_value == 2)
	{
		backward(50)
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker)
	}
	stopMotors();
}
