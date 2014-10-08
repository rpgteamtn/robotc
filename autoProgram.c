#include "functions\AutoProgramQuestions.c"

task main()
{
	setBluetoothOff();

	bool check = false;
	int timeDelay;
	bool RPGKickStand;
	bool RPGStart;


	do
	{
		timeDelay = questionInt("Amount of delay", "left = -1 sec","right = +1 sec", 0 , 30);//asks the questions and sets RPGtime as the answer either true or false
		repeatUntil(nNxtButtonPressed == noButton)
		{}
		RPGStart = questionBool("r u starting:","left = floor","right = ramp");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
		RPGKickStand = questionBool("do kickstand?","left = no","right = yes");
		repeatUntil(nNxtButtonPressed == noButton)
		{}

		string test1;// = "delay = " + timeDelay;
		string test2;// = RPGStart;
		string test3;// = "kickstand = " + RPGKickStand;

		sprintf(test1, "delay = %i", timeDelay);
		sprintf(test2, "location = %i", RPGStart);
		sprintf(test3, "Kickstand = %i", RPGKickStand);

		displayCenteredTextLine(1, "your values are:");
		displayCenteredTextLine(5,  test1);
		displayCenteredTextLine(6,  test2);
		displayCenteredTextLine(7, test3);

		check = questionBool("is this right","left = no","right = yes");
		repeatUntil(nNxtButtonPressed == noButton)
		{}

	}
	while (false == check);

	//waitForStartorButton();
}
