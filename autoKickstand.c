#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     gyro,           sensorSONAR)
#pragma config(Sensor, S4,     HTSMUX,         sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MUX1 		 msensor_S4_1
#define touch 	 msensor_S4_2
#define sonar    msensor_S4_3

#include "IRsensor.c"
#include "fourWheelMovement.c"
#include "gyroSensor.c"
#include "MovementCommon.c"
#include "sonarSensor.c"

//distances for finding the kickstand
#define pointA 90
#define pointB 120
#define pointC 150
#define pointD 50
#define maxDistance 150
#define distanceA1 95.0
#define distanceA2 200.0
#define distanceB1 230.0
#define distanceB2 18.0
#define distanceB3 13.0
#define distanceC1 /*160.0*/ 50.0
#define distanceC2 200.0
#define distanceD1 50
#define distanceD2 200
#define distanceD3 200
#define distanceE1 130
#define distanceE2 70
#define maxEncoder 5000


// Finds the IR and displays the encoders
float findIR()
{
	resetEncoders();
	int	ir_value = getIRReading();
	forward(50);
	wait1Msec(100);
	repeatUntil((ir_value == 2)||(ir_value == 3)||(abs(nMotorEncoder(leftFront))>maxEncoder))
	{
		wait1Msec(1);
		ir_value = getIRReading();
	}
	stopMotors();
	int lfEnc = (abs(nMotorEncoder[leftFront]));// + abs(nMotorEncoder[rightFront])) / 2;
	int lbEnc = (abs(nMotorEncoder[leftBack]));// + abs(nMotorEncoder[rightFront])) / 2;
	int rfEnc = (abs(nMotorEncoder[rightFront]));// + abs(nMotorEncoder[rightFront])) / 2;
	int rbEnc = (abs(nMotorEncoder[rightBack]));// + abs(nMotorEncoder[rightFront])) / 2;
	float avgEnc = (lbEnc + rbEnc) / 2.0;

	string text;
	sprintf(text, "lf enc=%i", lfEnc);
	displayCenteredTextLine(2, text);

	sprintf(text, "lb enc=%i", lbEnc);
	displayCenteredTextLine(3, text);

	sprintf(text, "rf enc=%i", rfEnc);
	displayCenteredTextLine(4, text);

	sprintf(text, "rb enc=%i", rbEnc);
	displayCenteredTextLine(5, text);

	sprintf(text, "avg enc = %f", avgEnc);
	displayCenteredTextLine(6, text);

	float distance = calculateDist(avgEnc);

	sprintf(text, "dist = %f", distance);
	displayCenteredTextLine(7, text);

	return distance;
}

void strategyA()//use if in position 1
{
	string text;
	sprintf(text, "Strategy A");
	displayCenteredTextLine(1, text);
	travelDistance(distanceA1, dBackward);
	stopMotors();
	gyroTurn(30, 77, dRight);
	travelDistance(distanceA2, dForward);
	stopMotors();
}

void strategyB()//use if in position 2
{
	string text;
	sprintf(text, "Strategy B");
	displayCenteredTextLine(1, text);
	gyroTurn(30, 45, dRight);
	travelDistance(distanceB1, dForward);
	stopMotors();
}

void strategyC()//use if in position 3
{
	/*string text;
	sprintf(text, "Strategy C");
	displayCenteredTextLine(1, text);
	gyroTurn(30, 90, dLeft);
	travelDistance(distanceC1);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceC2);*/
	string text;
	sprintf(text, "Strategy C");
	displayCenteredTextLine(1, text);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceA2, dForward);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceC1, dForward);
}

void strategyD()
{
	displayCenteredTextLine(1, "Strategy D");
	travelDistance(distanceD1, dForward);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceD2, dForward);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceD3, dForward);
}

void autoKickstand()
{
	disableDiagnosticsDisplay();
	//	waitForStartOrButton();
	resetEncoders();
	string text;
	eraseDisplay();
	float travelled = abs(findIR());
	wait1Msec(500);


	if(travelled <= pointA)
	{
		strategyA();
	}
	else if(travelled <= pointB)
	{
		strategyB();
	}
	else if(travelled <= pointC)
	{
		strategyC();
	}
	wait1Msec(20);
	travelDistance(distanceE1, dBackward);
	wait1Msec(20);
	align(10, dLeft);
	strafe(50);
	wait1Msec(500);
	/*gyroTurn(30, 90, dRight);
	approach(50);*/
}

task main()
{
	autoKickstand();
}
