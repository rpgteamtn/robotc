//Position 1 is when the kickstand is perpendicular to the parking zone
//Position 2 is when the kickstand is facing the platform on the ramp
//Position 3 is when the kickstand is facing the parking zone

//distances for finding the kickstand
#define pointA 70
#define pointB 90
#define pointC 150
#define pointD 40
#define maxDistance 150
#define distanceA1 70.0
#define distanceA2 150.0
#define distanceB1 230.0
#define distanceC1 150.0
#define distanceD1 50
#define distanceD2 200
#define distanceD3 200
#define distanceE1 130
#define distanceE2 70
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


// Finds the IR and displays the encoders
float findIRGround(eWay direct) //Find distance travelled before reading IR signal from the ground
{
	resetEncoders(); //Set encoders to 0
	int	ir_value = getIRReading(); //Set variable "ir_value" to the current IR reading
	if (direct == dForward) { //It told to go forward
		forward(50); //go forward at half power
	}
	else if (direct == dBackward) { //If told to go backward
		backward(50); //go backward at half power
	}
	wait1Msec(100);
	repeatUntil((ir_value == 2)||(ir_value == 3)||(abs(nMotorEncoder(rightFront))>maxEncoder))
	{ //Refresh ir_value every millisecond until IR reading is in zone 2 or 3
		wait1Msec(1);
		ir_value = getIRReading();
	}
	stopMotors(); //You found the IR beacon, now stop
	int lfEnc = (abs(nMotorEncoder[leftFront])); //define variables for all drive encoder value
	int lbEnc = (abs(nMotorEncoder[leftBack]));
	int rfEnc = (abs(nMotorEncoder[rightFront]));
	int rbEnc = (abs(nMotorEncoder[rightBack]));
	float avgEnc = (lfEnc + rfEnc) / 2.0; //Define the average encoder value of the front drive motors

	displayCenteredTextLine(2, "lf enc=%i", lfEnc); //Display four drive motor encoder values
	displayCenteredTextLine(3, "lb enc=%i", lbEnc);
	displayCenteredTextLine(4, "rf enc=%i", rfEnc);
	displayCenteredTextLine(5, "rb enc=%i", rbEnc);
	displayCenteredTextLine(6, "avg enc = %f", avgEnc); //Display average encoder value for front motors

	float distance = calculateDist(rfEnc); //define distance travelled so far in centimeters

	displayCenteredTextLine(7, "dist = %f", distance); //display distance travelled

	return distance;
}

float findIRRamp(eWay direct)
{
	resetEncoders(); //Set encoders to 0
	int	ir_value = getIRReading(); //Define "ir_value" as the current IR reading
	if (direct == dForward) { //If told to go forward
		forward(50); //Go forward at half power
	}
	else if (direct == dBackward) { //If told to go backward
		backward(50); //Go backward at half power
	}
	wait1Msec(100);
	repeatUntil((ir_value == 2)||(ir_value == 1)||(abs(nMotorEncoder(rightFront))>maxEncoder))
	{ //Refresh ir_value every millisecond until IR reading is in zone 1 or 2
		wait1Msec(1);
		ir_value = getIRReading();
	}
	stopMotors(); //You found the IR beacon, now stop
	int lfEnc = (abs(nMotorEncoder[leftFront])); //define variables for each separate drive encoder
	int lbEnc = (abs(nMotorEncoder[leftBack]));
	int rfEnc = (abs(nMotorEncoder[rightFront]));
	int rbEnc = (abs(nMotorEncoder[rightBack]));
	float avgEnc = (lfEnc + rfEnc) / 2.0; //Define the average encoder value of the front motors

	displayCenteredTextLine(2, "lf enc=%i", lfEnc); //Display the individual drive encoder values
	displayCenteredTextLine(3, "lb enc=%i", lbEnc);
	displayCenteredTextLine(4, "rf enc=%i", rfEnc);
	displayCenteredTextLine(5, "rb enc=%i", rbEnc);
	displayCenteredTextLine(6, "avg enc = %f", avgEnc); //Display the average front moter encoder value

	float distance = calculateDist(rfEnc); //Define the distance travelled so far in centimeters

	displayCenteredTextLine(7, "dist = %f", distance); //Display distance travelled

	return distance;
}

void strategyA()//use if in position 1, from ground
{
	displayCenteredTextLine(1, "Strategy A"); //Display whch strategy it chose
	travelDistance(distanceA1, dBackward); //Go backward a certain distance
	strafe(50); //Strafe right at half power
	wait1Msec(1000); //Keep going for 1 second
	stopMotors(); //stop
	gyroTurn(30, 80, dLeft); //Turn left 80 degrees
	travelDistance(distanceA2, dBackward); //Travel backward a certain distance
}

void strategyB()//use if in position 2, from ground
{
	displayCenteredTextLine(1, "Strategy B"); //Display which strategy it chose
	strafe(50); //Strafe right at half power
	wait1Msec(1000); //Keep going for 1 second
	stopMotors(); //Stop
	gyroTurn(30, 35, dLeft); //Turn left 35 degrees
	travelDistance(distanceB1, dBackward); //Go backward a certain distance
}

void strategyC()//use if in position 3, from ground
{
	displayCenteredTextLine(1, "Strategy C"); //Display which strategy it chose
	strafe(50); //Strafe right at half power
	wait1Msec(2550); //Keep going for 2.7 seconds
	stopMotors(); //Stop
	gyroTurn(30, 5, dRight); //Turn right 5 degrees
	travelDistance(distanceC1, dBackward); //Travel backward a certain distance
}

void strategyD()//use if in position 3, from ground
{
	displayCenteredTextLine(1, "Strategy D"); //display which strategy it chose
	travelDistance(distanceD1, dForward); //go forward a certain distance
	gyroTurn(30, 90, dRight); //Turn right 90 degrees
	travelDistance(distanceD2, dForward); //go forward a certain distance
	gyroTurn(30, 90, dRight); //Turn right 90 degrees
	travelDistance(distanceD3, dForward); //go forward a certain distance
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

float rampOff()
{
	float distance = findIRRamp(dBackward);
	float travelDist = 170 - distance;
	travelDistance(travelDist, dForward);
	gyroTurn(30, 80, dRight);
	wait1Msec(15000);
	return distance;
}

void autoRamp()
{
/*	disableDiagnosticsDisplay();
	resetEncoders();
	float travelled = abs(rampOff());
	wait1Msec(500);

	if (travelled < pointZ)
	{
		strategyZ();
	}
	else if (travelled < pointX)
	{
		strategyX();
	}
	else if (travelled < pointY)
	{
		strategyY();
	}*/
	travelDistance(190, dForward);
}

void autoKickstand()
{
	disableDiagnosticsDisplay();
	strafe(50);
	wait1Msec(500);
	stopMotors();
	wait1Msec(100);
	resetEncoders();
	eraseDisplay();
	float travelled = abs(findIRGround(dForward));
	wait1Msec(500);

	if(travelled <= pointD)
	{
		travelDistance(distanceD1, dForward);
		strategyC();
	}

	else if(travelled <= pointA)
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


	/*wait1Msec(20);
	travelDistance(distanceE1, dBackward);
	wait1Msec(20);
	align(10, dLeft);
	strafe(50);
	wait1Msec(500);
	/*gyroTurn(30, 90, dRight);
	approach(50);*/
}

/*task main()
{
autoRamp();
}*/
