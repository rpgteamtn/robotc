#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     smux,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_1,    spinnerServo,         tServoStandard)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)

int SPINNEROUT = 145;
int SPINNERIN = 35;

void spinnerOut()
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNEROUT;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}

void spinnerIn()
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNERIN;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}


task main()
{
 spinnerOut();
 wait1Msec(5000);
 spinnerIn();
 wait1Msec(5000);
}
