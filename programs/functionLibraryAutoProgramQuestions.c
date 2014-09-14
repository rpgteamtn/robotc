#define nxtorange 3
#define nxtleft 2
#define nxtright 1
#define nxtgrey 0

bool RPGtime = NULL;

bool Question1()
{
	nxtDisplayCenteredTextLine(1, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(2, " right = yes."); // Displays instructions
	nxtDisplayCenteredTextLine(4, "go back?");//Displays first question

	while(RPGtime == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(4);//clears the question
			RPGtime = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(4);//clears the question
			RPGtime = false;
			return false;
		}
	}
	return true;
}

int Question2()
{
	int answer
	nxtDisplayCenteredTextLine(1, "left = add"); // Displays instructions
	nxtDisplayCenteredTextLine(2, "right = subtract"); // Displays instructions
	nxtDisplayCenteredTextLine(3, "press grey when done"); // Displays instructions
	nxtDisplayCenteredTextLine(5, "taps needed to go");//Displays first question
	nxtDisplayCenteredTextLine(6, answer)

	while(sensorvalue[nxtgrey] = -1)
	{
		if(nNxtButtonpressed == nxtright)// checks if the right btn is pushed
		{
			answer = answer + 1
			nxtDisplayClearTextLine(6)
			nxtDisplayCenteredTextLine(6, answer)
		}

		if(nNxtButtonPressed == 2)// checks if the left btn is pushed
		{
			answer = answer - 1
			nxtDisplayClearTextLine(6)
			nxtDisplayCenteredTextLine(6, answer)
		}

	}

	return answer
}

string inttostring(int num)
{

}
