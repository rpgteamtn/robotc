//#include "Common.c";
/*
#ifndef "main"
void main()
{
1=1
}
#enddef*/
#include "rpgCommon.c"

int questionInt(const string squestionText, const string sleftText, const string srightText, const int MIN, const int MAX)
{
	int ivalue = 0;
	string svalue;
	displayCenteredTextLine(1, squestionText);//Displays second question
	displayCenteredTextLine(3, sleftText); // Displays instructions
	displayCenteredTextLine(4, srightText); // Displays instructions

	repeatUntil(nNxtButtonPressed == nxtOrange)
	{

	waitTillNoButton();

		if(nNxtButtonPressed == nxtRight)
		{
			if(ivalue < MAX)
			{
				ivalue++;
			}
			else
			{
				displayCenteredTextLine(7, "error: reached max num");
			}
		}
		if(nNxtButtonPressed == nxtLeft)
		{
			if(ivalue > MIN)
			{
				ivalue--;
			}
			else
			{
				displayCenteredTextLine(7, "error: reached min num");
			}
		}
		if(nxtOrange == nNxtButtonPressed)
		{
			break;
		}
		sprintf(svalue,"value = %i", ivalue,);

		displayCenteredTextLine(6, svalue);
		repeatUntil(nNxtButtonPressed == noButton)
		{}
	}

	return ivalue;
}
// Function: question bool
// Parameters:
//	squestionText: string for the question you are asking
//	sleftText: what answer the left button would give
//	srightText: what answer the right button would give
// this funcation lets you ask a question that returns as bool
//Outputs: boolan answer
bool questionBool(const string squestionText, const string sleftText, const string srightText)
{
	bool bvalue = false;
	displayCenteredTextLine(1, squestionText);//Displays question
	displayCenteredTextLine(4, sleftText); // Displays instructions
	displayCenteredTextLine(3, srightText); // Displays instructions

	repeatUntil(nNxtButtonPressed == nxtOrange)
	{

		while(nNxtButtonPressed == noButton)
		{	}

		if(nNxtButtonPressed == nxtRight)
		{
			bvalue = true;

		}
		if(nNxtButtonPressed == nxtLeft)
		{
			bvalue = false;
		}
		if(nxtOrange == nNxtButtonPressed)
		{
			break;
		}
		displayCenteredTextLine(6, bvalue?"true":"false");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
	}
	return bvalue;
}

bool lastQuestion()
{
	bool bvalue = false;
	displayCenteredTextLine(0, "Are these values correct?");//Displays question
	displayCenteredTextLine(1, "right = yes"); // Displays instructions
	displayCenteredTextLine(2, "left = no"); // Displays instructions

	repeatUntil(nNxtButtonPressed == nxtOrange)
	{

		while(nNxtButtonPressed == noButton)
		{	}

		if(nNxtButtonPressed == nxtRight)
		{
			bvalue = true;

		}
		if(nNxtButtonPressed == nxtLeft)
		{
			bvalue = false;
		}
		if(nxtOrange == nNxtButtonPressed)
		{
			break;
		}
		displayCenteredTextLine(6, bvalue?"true":"false");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
	}
	return bvalue;
}
