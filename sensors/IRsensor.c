#include "hitechnic-irseeker-v2.h"

int getIRReading(tSensors ir_seeker)
{
	wait1Msec(1);                              // Wait 1 ms
	int ir = HTIRS2readDCDir(ir_seeker);      // IR receiver -> ir variable
	wait1Msec(1);                              // Down time before recheck
	return ir;
}
