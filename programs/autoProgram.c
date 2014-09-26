#include "functions\AutoProgramQuestions.c"

task main()
{
	//setBluetoothOff();

	bool check = false;
	int timeDelay;
	bool RPGKickStand;
	bool RPGStart;


	do
	{
		 timeDelay = questionInt("amount of delay", "left = minus 1 second","right = add 1 second");//asks the questions and sets RPGtime as the answer either true or false
		 RPGStart = questionBool("where are you starting","left = floor","right = ramp");
		 RPGKickStand = questionBool("kick the kickstand","left = no","right = yes");

		 string test1;// = "delay = " + timeDelay;
		 string test2;// = RPGStart;
		 string test3;// = "kickstand = " + RPGKickStand;

		 sprintf(test1, "delay = %i", timeDelay);
		 sprintf(test2, "start location = %i", RPGStart);
		 sprintf(test3, "Kickstand = %i", RPGKickStand);

		 displayCenteredTextLine(1, "your values are:");
		 displayCenteredTextLine(2,  test1);
		 displayCenteredTextLine(3,  test2);
		 displayCenteredTextLine(4, test3);

	   check = questionBool("is this right","left = no","right = yes");
	}
	while (false == check);

	//waitForStartorButton();
}
