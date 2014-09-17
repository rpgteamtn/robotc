#include "Common.c";

bool RPGtime = NULL;
bool RPGstart = NULL;
bool RPGmove30 = NULL;
bool RPGmove60 = NULL;
bool RPGmove90 = NULL;
bool RPGscore30 = NULL;
bool RPGscore60 = NULL;
bool RPGscore90 = NULL;
bool RPGscoreCenter = NULL;
bool RPGkickStand = NULL;
/**********************************************************
1st Question
***********************************************************/
bool Question1()
{
	nxtDisplayCenteredTextLine(1, "do you want to wait ten seconds");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGtime == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGtime = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGtime = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
2nd Question
***********************************************************/
bool Question2()
{
	nxtDisplayCenteredTextLine(4, "left = floor."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = ramp."); // Displays instructions
	nxtDisplayCenteredTextLine(1, "where are you starting");//Displays first question

	while(RPGtime == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			nxtDisplayClearTextLine(3);//clears the instructions for next set of instructions
			nxtDisplayClearTextLine(4);//clears the instructions for next set of instructions
			RPGstart = true;
			return true;//returns true
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGstart = true;
			return false;//returns false
		}
	}
	return true;
}
/**********************************************************
4th Question
***********************************************************/
bool Question4()
{
	nxtDisplayCenteredTextLine(1, "move 30cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGmove30 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove30 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove30 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
5th Question
***********************************************************/
bool Question5()
{
	nxtDisplayCenteredTextLine(1, "move 60cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGmove60 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove60 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove60 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
6th Question
***********************************************************/
bool Question6()
{
	nxtDisplayCenteredTextLine(1, "move 90cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGmove90 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove90 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGmove90 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
7th Question
***********************************************************/
bool Question7()
{
	nxtDisplayCenteredTextLine(1, "score all in 30cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGscore30 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore30 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore30 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
8th Question
***********************************************************/
bool Question8()
{
	nxtDisplayCenteredTextLine(1, "score all in 60cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGscore60 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore60 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore60 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
9th Question
***********************************************************/
bool Question9()
{
	nxtDisplayCenteredTextLine(1, "score all in 90cm tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGscore90 == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore90 = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGscore90 = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
3rd Question
***********************************************************/
bool Question3()
{
	nxtDisplayCenteredTextLine(1, "kick the kickstand");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGkickStand == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGkickStand = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGkickStand = false;
			return false;
		}
	}
	return true;
}
/**********************************************************
10th Question
***********************************************************/
bool Question10()
{
	nxtDisplayCenteredTextLine(1, "score all in center tube?");//Displays second question
	nxtDisplayCenteredTextLine(4, "left = no."); // Displays instructions
	nxtDisplayCenteredTextLine(3, " right = yes."); // Displays instructions

	while(RPGscoreCenter == NULL)
	{
		if(nNxtButtonPressed == nxtright)// checks if the right btn is pushed
		{
			// sets RPGtime to true
			nxtDisplayClearTextLine(1);//clears the question
			RPGscoreCenter = true;
			return true;
		}

		if(nNxtButtonPressed == nxtleft)// checks if the left btn is pushed
		{
			// sets RPGtime to false
			nxtDisplayClearTextLine(1);//clears the question
			RPGscoreCenter = false;
			return false;
		}
	}
	return true;
}
