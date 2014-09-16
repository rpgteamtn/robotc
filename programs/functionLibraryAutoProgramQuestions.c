#define nxtorange 3
#define nxtleft 2
#define nxtright 1
#define nxtgrey 0

bool RPGstart = NULL;

bool Question1()
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
			nxtDisplayClearTextLine(3);
			nxtDisplayClearTextLine(4);
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

bool Question2()
{
	nxtDisplayCenteredTextLine(1, "do the kick stand");//Displays second question
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

bool Question3()
{
	nxtDisplayCenteredTextLine(1, "move 30cm tube?");//Displays second question
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

bool Question4()
{
	nxtDisplayCenteredTextLine(1, "move 60cm tube?");//Displays second question
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

bool Question4()
{
	nxtDisplayCenteredTextLine(1, "move 90cm tube?");//Displays second question
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

bool Question5()
{
	nxtDisplayCenteredTextLine(1, "score all in 30cm tube?");//Displays second question
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

bool Question6()
{
	nxtDisplayCenteredTextLine(1, "score all in 60cm tube?");//Displays second question
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
bool Question7()
{
	nxtDisplayCenteredTextLine(1, "score all in 90cm tube?");//Displays second question
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

bool Question8()
{
	nxtDisplayCenteredTextLine(1, "score all in center tube?");//Displays second question
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
