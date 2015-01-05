#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Sensor, S4,     smux,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MUX1 	   msensor_S4_1
#define sonar 	 msensor_S4_2

#include "rpgCommon.c"
#include "hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "IRsensor.c"
#include "fourWheelMovement.c"
#include "gyroSensor.c"
#include "MovementCommon.c"

//distances for finding the kickstand
#define pointA 75
#define pointB 120
#define pointC 150
#define maxDistance 150
#define distanceA1 85.0
#define distanceA2 200.0
#define distanceC1 160.0
#define distanceC2 200.0
#define distanceB1 230.0
#define distanceB2 18.0
#define distanceB3 13.0
#define maxEncoder 5000


// Finds the IR and displays the encoders
/*float findIR(tMUXSensor ir_seeker)
{
	resetEncoders();
	int	ir_value = getIRReading(ir_seeker);
	forward(50);
	wait1Msec(100);
	repeatUntil((ir_value == 2)||(ir_value == 3)||(abs(nMotorEncoder(leftFront))>maxEncoder))
	{
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	int lfEnc = (abs(nMotorEncoder[leftFront]));// + abs(nMotorEncoder[rightFront])) / 2;
	int lbEnc = (abs(nMotorEncoder[leftBack]));// + abs(nMotorEncoder[rightFront])) / 2;
	int rfEnc = (abs(nMotorEncoder[rightFront]));// + abs(nMotorEncoder[rightFront])) / 2;
	int rbEnc = (abs(nMotorEncoder[rightBack]));// + abs(nMotorEncoder[rightFront])) / 2;
	float avgEnc = (lfEnc + rfEnc) / 2.0;

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
	travelDistance(distanceA1);
	stopMotors();
	gyroTurn(60, 30, dLeft);
	travelDistance(distanceA2);
	stopMotors();
}

void strategyB()//use if in position 2
{
	string text;
	sprintf(text, "Strategy B");
	displayCenteredTextLine(1, text);
	gyroTurn(30, 50, dLeft);
	travelDistance(distanceB1);
	stopMotors();
}

void strategyC()//use if in position 3
{
	string text;
	sprintf(text, "Strategy C");
	displayCenteredTextLine(1, text);
	gyroTurn(90.0, 30, dLeft);
	travelDistance(distanceC1);
	gyroTurn(90, 50, dRight);
	travelDistance(distanceC2);
}*/

void autoKickstand();
{
/*	disableDiagnosticsDisplay();
	//	waitForStartOrButton();
	resetEncoders();
	string text;
	eraseDisplay();
	float travelled = abs(findIR(IR));
	wait1Msec(500);

	if(travelled <= pointA)
	{
		displayCenteredTextLine(2, "Strategy A");
		strategyA();
	}
	else if(travelled <= pointB)
	{
		displayCenteredTextLine(2, "Strategy B");
		strategyB();
	}

	else if(travelled <= pointC)
	{
		displayCenteredTextLine(2, "Strategy C");
		strategyC();
	}*/

	leftTurn(100);
	wait1Msec(200);
	stopMotors();
}

task main()
{
	autoKickstand();
}
