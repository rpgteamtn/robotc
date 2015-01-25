#include "hitechnic-irseeker-v2.h"
#include "rpgCommon.c"

int getIRReading()
{
	tHTIRS2 irSeeker; //define the IR sensor as a tHTIRS2 sensor named irSeeker
	initSensor(&irSeeker, msensor_S4_4); //Initialize the sensor, point to its address (msenor_S4_4)
	readSensor(&irSeeker); //Get its values
	int ir = irSeeker.acDirection; //variable "ir" is the AC value from the IR sensor
	return ir; //This is the result
}
