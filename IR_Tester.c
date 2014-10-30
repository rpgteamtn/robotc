#pragma config(Sensor, S3,     HTIRS2,             sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// this is code for testing anything
#include "rpgCommon.c"
#include "IRsensor.c"

task main()
{
	eraseDisplay();
	int ir;
	while(true)
	{
		ir = getIRReading(HTIRS2);
		string text = sprintf(text, "ir=%i", ir);
		displayCenteredTextLine(1, text);
	}
}
