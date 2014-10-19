
#include "hitechnic-irseeker-v2.h"

int getIRReading(tHTIRS2Ptr ir_seeker)
{
	wait1Msec(1);                              // Wait 1 ms
	int ir = readSensor(ir_seeker);      // IR receiver -> ir variable
	wait1Msec(1);                              // Down time before recheck
	return ir;
}
