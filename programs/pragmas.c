//This is the 4-wheel mecanum pragmas
#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     rightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     rightBack,      tmotorTetrix, openLoop)


//This is the 2-wheel pragmas
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)