#define pointX 1 //Points X through Z have not yet been fixed.  All values are theoretical
#define pointY 1
#define pointZ 1
#define timeX1 100
#define distanceX1 1
#define distanceX2 1
#define distanceY1 1
#define distanceY2 1
#define distanceZ1 1
#define distanceZ2 1
#define distanceZ3 1

#define maxEncoder 5000 //The farthest the robot will go before giving up



void strategyA(bool useLift)
{
	displayCenteredTextLine(6, "Strategy A");
	gyroTurn(30, 90, dLeft);
	stopMotors();
	wait1Msec(100);
	travelDistance(40, dBackward);
	wait1Msec(100);
	strafeDist(27, 100, dLeft);
	wait1Msec(100);
	goalCenter(useLift);
	strafeDist(45, 50, dLeft);
	gyroTurn(30, 10, dLeft);
	travelDistance(125, dBackward);
}

void strategyB(bool useLift)
{
	displayCenteredTextLine(6, "Strategy B");
	//strafeDist(15, 30, dRight);
	gyroTurn(30, 15, dRight);
	travelDistance(15, dBackward);
	goalCenter(useLift);
	gyroTurn(30, 10, dLeft);
	strafeDist(45, 50, dLeft);
	travelDistance(125, dBackward);
}

void strategyC(bool useLift)
{
	displayCenteredTextLine(6, "Strategy C");
	//strafeDist(50, 75, dRight);
	gyroTurn(30, 48, dRight);
	strafeDist(25, 75, dRight);
	travelDistance(21, dBackward);
	goalCenter(useLift);
	gyroTurn(30, 10, dLeft);
	strafeDist(45, 75, dLeft);
	travelDistance(125, dBackward);
}

void strategyX() //use if in position 3, from ramp
{
	displayCenteredTextLine(1, "strategy X"); //display whch strategy it chose
	strafe(50); //strafe right at half power
	wait1Msec(timeX1); //keep going for a certain amount of time
	stopMotors(); //stop
	travelDistance(distanceX1, dForward); //travel forward a certain distance
	gyroTurn(30, 80, dLeft); //turn left 80 degrees
	travelDistance(distanceX2, dForward); //travel forward a certain distance
}

void strategyY() //use if in position 2, from ramp
{
	displayCenteredTextLine(1, "strategy Y"); //display which strategy it chose
	travelDistance(distanceY1, dForward); //travel forward a certain distance
	gyroTurn(30, 45, dLeft); //turn left 45 degrees
	travelDistance(distanceY1, dForward); //travel forward a certain distance
}

void strategyZ() //use if in position 1, from ramp
{
	displayCenteredTextLine(1, "strategy Z"); //display which strategy it chose
	travelDistance(distanceZ1, dForward); //
	gyroTurn(30, 90, dLeft);
	travelDistance(distanceZ2, dForward);
	gyroTurn(30, 90, dRight);
	travelDistance(distanceZ3, dForward);
}

/*float rampOff()
{
	float distance = findIRRamp(dBackward);
	float travelDist = 170 - distance;
	travelDistance(travelDist, dForward);
	gyroTurn(30, 80, dRight);
	wait1Msec(15000);
	return distance;
}*/

void autoRamp(bool useLift)
{
	travelDistance(200, dBackward);
	gyroTurn(30, 5, dRight);
	goalRelease();

	wait1Msec(100);
	backward(15);
	wait1Msec(1250);
	stopMotors();
	int iCRate = servoChangeRate[goalCapture];	// Save change rate
	servoChangeRate[goalCapture] = 0; 					// Max Speed
	servo[goalCapture] = CATCHDOWN;					    // Set servo position
	wait1Msec(50);
	servoChangeRate[goalCapture] = iCRate;			// Reset the servo
	wait1Msec(100);
	travelDistance(5, dBackward);
	strafe(75);
	wait1Msec(500);
	stopMotors();
	gyroTurn(30, 10, dRight);
	travelDistance(75, dForward);
	gyroTurn(30, 3, dLeft);
	travelDistance(180, dForward);
	gyroTurn(30, 100, dRight);
	goalMed(useLift);
}

void autoFloor(bool useLift)
{
	int irValue = getIRReading();
	strafeDist(40, 100, dRight);
	displayCenteredTextLine(1, "IR = %i", irValue);
	if (irValue == 2)
	{
		strategyA(useLift);
	}
	else
	{
		irValue = getIRReading();
		if (irValue == 2)
		{
			strategyA(useLift);
		}

		else
		{
			gyroTurn(10, 5, dRight);
			int irValue1 = getIRReading();
			gyroTurn(10, 10, dLeft);
			int irValue2 = getIRReading();
			eraseDisplay();
			displayCenteredTextLine(2, "IR1 = %i", irValue1);
			displayCenteredTextLine(3, "IR2 = %i", irValue2);
			if (irValue1 == 2 || irValue2 == 2)
			{
				gyroTurn(10, 5, dRight);
				strategyA(useLift);
			}
			else
			{
				strafeDist(40, 75, dRight);
				gyroTurn(50, 30, dLeft);
				resetEncoders();
				while (irValue != 6)
				{
					irValue = getIRReading();
					strafe(100);
					int enc = abs(nMotorEncoder[leftBack]);
					displayCenteredTextLine(3, "distance=%i", enc);
					wait1Msec(1);
				}
				stopMotors();
				int enc = abs(nMotorEncoder[leftBack]);
				displayCenteredTextLine(1, "enc = %i", enc);
				if (enc < 1500)
				{
					strategyB(useLift);
				}
				else
				{
					strategyC(useLift);
				}
			}
		}
	}
}
