//#include "Common.c";
/*
#ifndef "main"
void main()
{
1=1
}
#enddef*/

#define nxtOrange '3'
#define nxtLeft '2'
#define nxtRight '1'
#define nxtGrey '0'

int questionInt(const string squestionText, const string sleftText, const string srightText)
{
	int ivalue = 0;

	string sfoo;
	displayCenteredTextLine(1, squestionText);//Displays second question
	displayCenteredTextLine(3, sleftText); // Displays instructions
	displayCenteredTextLine(4, srightText); // Displays instructions

	while(nNxtButtonPressed != nxtOrange)
	{
		if(nNxtButtonPressed == nxtRight)
		{
			ivalue++;
		}
		if(nNxtButtonPressed == nxtLeft)
		{
			ivalue--;
		}
		sprintf(foo, "%i", ivalue);
		displayCenteredTextLine(6, sfoo);
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
	displayCenteredTextLine(1, squestionText);//Displays second question
	displayCenteredTextLine(4, sleftText); // Displays instructions
	displayCenteredTextLine(3, srightText); // Displays instructions

	while(nNxtButtonPressed != nxtOrange)
	{
		if(nNxtButtonPressed == nxtRight)
		{
			bvalue = true;
		}
		if(nNxtButtonPressed == nxtLeft)
		{
			bvalue = false;
		}
	displayCenteredTextLine(6, value?"true":"false");
	}
	return value;//evaluating the value of value
}
