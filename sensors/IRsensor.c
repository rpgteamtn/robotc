#include "hitechnic-irseeker-v2.h"
#include "rpgCommon.c"

int getIRReading()
{
	tHTIRS2 irSeeker;
	initSensor(&irSeeker, msensor_S4_4);
	readSensor(&irSeeker);
	int ir = irSeeker.acDirection;
	return ir;
}
