#define nxtorange 3
#define nxtleft 2
#define nxtright 1
#define nxtgrey 0

void waitForStartOrButton()
{
  while (true)
  {
    getJoystickSettings(joystick);
    if (!joystick.StopPgm)      // normal FCS start condition
    {
      break;
    }

    if (nNxtButtonPressed = nxtorange)
    { // manual bypass start condition

    	// 2 beeps and 2 seconds to get out of the way before the program starts
    	PlayImmediateTone(1000,50);
    	wait1Msec(1000);

    	PlayImmediateTone(1000,50);
    	wait1Msec(1000);

    	break;
    }
  }
  return;
}
/* -----------------------------------------------
This is ___ function
------------------------------------------------*/

