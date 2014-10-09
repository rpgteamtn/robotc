#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)

#include "autoIR.c"

#define encodeA
#define encodeB
#define encodeC
#define encodeD

#define distA1
#define distA2
#define distA3
#define distB1
#define distB2
#define distC1
#define distC2
#define distD1
#define distD2

void turnRight()
{
	motor[rightFront] = 100;
	motor[leftFront] = 0;
}

void turnLeft()
{
	motor[leftFront] = 100;
	motor[rightFront] = 0;
}

task main()
{
	if (

}
