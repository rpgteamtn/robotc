#define DIAMETER 10.0 //diameter of the wheel in centimeters
#define CIRCUMFERENCE PI * DIAMETER //wheel circumference
#define PPR 1120.0 //clicks per rotation in the drive motor encoders

int SPINNEROUT = 165; //Servo degree measure when spinner is down
int SPINNERIN = 35;   //Servo degree measure when spinner is up

int getSingleEncoderValue() //Get the average as a more reliable value
{
	int value = abs(nMotorEncoder[rightFront]);
	return value;
}

void setMotors(const int lfPower, const int lbPower, const int rfPower, const int rbPower)
{ //function to quickly set all four drive motors
	motor[leftFront] = lfPower; //left front motor set at 1st parameter
	motor[leftBack] = lbPower;  //left back motor set at 2nd parameter
	motor[rightFront] = rfPower;//right front motor set at 3rd parameter
	motor[rightBack] = rbPower; //right back motor set at 4th parameter
}

void resetEncoders() //Reset the drive motor encoders to 0 for an encoder-dependant function
{
	nMotorEncoder[rightFront] = 0;//All encoders are 0
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[leftBack] = 0;
}

float cmToClicks(float centimeters) //Convert a value in cm(from user) to clicks(for robot)
{
	float clicks = centimeters * 280 / CIRCUMFERENCE;
	return clicks;
}

float clicksToCm(float clicks) //Convert a value in clicks(from robot) to cm(for user)
{
	float centimeters = clicks * CIRCUMFERENCE / 280;
	return centimeters;
}

void leftTurn(const int power) //Set drive motors at a power so robot point-turns left
{
	setMotors(-power, -power, power, power);
}

void rightTurn(const int power) //Set drive motors at a power so robot point-turns right
{
	setMotors(power, power, -power, -power);
}

void forward(const int power) //Set all drive motors forward at a power
{
	setMotors(power, power, power, power);
}

void backward(const int power) //Set all drive motors backward at a power
{
	setMotors(-power, -power, -power, -power);
}

void stopMotors() //Set all drive motors to 0
{
	setMotors(0, 0, 0, 0);
}

int rescale(const int j)
{//Convert a joystick value (-128 to 128) to its equivalent for the motors (-100 to 100)
	return j*100/128;
}

void setMotion(const int y1, const int y2) //Drive according to joystick values
{
	setMotors(rescale(y1), rescale(y1), rescale(y2), rescale(y2));
}

void strafe(const int forward) //Strafe (+ parameter goes right, - parameter goes left)
{
	int reverse = -1 * forward; //Define "reverse" as the opposite of "forward"
	setMotors(forward, reverse, reverse, forward); //Set drive motors so that robot strafes
}

void lift(const int power) //Syncs both lift motors lift functions are 1 command
{
	motor[liftRight] = power; //Right lift motor
	motor[liftLeft] = power;  //Left lift motor
	wait1Msec(10); //Wait a moment (for lift tasks)
}

void spin(const int power) //Run the spinner
{
	motor[spinner] = power; //Spinner motor goes a power
	wait1Msec(10);
}

void stopLiftMotors() //Stop lift motors
{
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
	wait1Msec(10);
}

void resetLiftEncoders() //Sets lift encoders to 0 for precise encoder-regulated movements
{
	nMotorEncoder[liftRight] = 0;
	nMotorEncoder[liftLeft] = 0;
	wait1Msec(10);
}

int getLiftEncoder() //Get the average value of the lift encoders
{
	int value = (abs(nMotorEncoder[liftLeft]) + abs(nMotorEncoder[liftRight]) / 2);
	return value;
}


void spinnerOut() //Release the spinner (Put it down)
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNEROUT;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}

void spinnerIn() //Pull spinner "holder" in
{
			int iCRate = servoChangeRate[spinnerServo];	// Save change rate
			servoChangeRate[spinnerServo] = 0; 					// Max Speed
			servo[spinnerServo] = SPINNERIN;					// Set servo position
			wait1Msec(20);
			servoChangeRate[spinnerServo] = iCRate;
}
