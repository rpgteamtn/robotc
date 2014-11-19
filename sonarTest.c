#pragma config(Sensor, S1,     sonar,          sensorSONAR)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     sTouch,         sensorTouch)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorLeft,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//hi
//hello random person

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "../sensors/gyroSensor.c"

#define RUNVAL 50
typedef enum {dRight, dLeft } eDirection;

bool bRun;

// Task: MonitorTouch
// Parameters: NONE
// Outputs: NONE
// description: ???
task MonitorTouch()
{
	if(SensorValue(sTouch) != 0)
	{
		bRun = false;
	}
}

// function: initializeRobot
// Parameters: NONE
// Outputs: NONE
// description: initializes Robot

void initializeRobot()
{
	nxtDisplayString(1, "initializeRobot");
	disableDiagnosticsDisplay();
	SensorMode[sonar] = modeRaw;
	HTGYROstartCal(gyro);

	bRun = true;
	StartTask(MonitorTouch);
	return;
}

// function: robotStop
// Parameters: NONE
// Outputs: NONE
// description: stops the robot

void robotStop()
{
	nxtDisplayString(1,"robotStop");
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
	wait1Msec(250);
}

// function: turnDegrees
// Parameters: NONE
// Outputs:
//	number: a ransom number
// description: gives a number for a turn degrees

float turnDegrees()
{
	return random(6) * 45.0;
}

// function: initializeRobot
// Parameters:
//	direction: either left or rignt
// Outputs: NONE
// description: turns the robot in the given direction

void robotTurn(eDirection eDir)
{
	nxtDisplayString(1,"robotTurn");

	if(random[2] == 1) {
		// turn right
		nxtDisplayString(2,"Right");
		motor[motorLeft] = -RUNVAL;
		motor[motorRight] = RUNVAL;
	}
	else {
		// turn left
		nxtDisplayString(2,"Left");
		motor[motorLeft] = RUNVAL;
		motor[motorRight] = -RUNVAL;
	}

	gyroTurn(turnDegrees());
	robotStop();
	return;
}

// Main Task
task main()
{
	int iDistance = 30;	// centimeters
	int iSonar;
  initializeRobot();

  //waitForStart(); //Wait for the beginning of autonomous phase.
  while(SensorValue(sTouch) == 0) {
  	nxtDisplayString(1,"Main_Loop");
  	motor[motorLeft] = RUNVAL;
  	motor[motorRight] = RUNVAL;

  	wait1Msec(10);
  	iSonar = SensorValue[sonar];
  	nxtDisplayString(2,"Sonar Value: %d", iSonar);
  	if( iSonar < iDistance ) { // Object is too close
  		robotStop();
  		PlaySound(soundBeepBeep);
			robotTurn(dRight);
  	}
  }

  robotStop();
  StopTask(MonitorTouch);
}
