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

int questionInt(const string questionText, const string leftText, const string rightText)
{
	int value = 0;

	string foo;
	displayCenteredTextLine(1, questionText);//Displays second question
	displayCenteredTextLine(3, leftText); // Displays instructions
	displayCenteredTextLine(4, rightText); // Displays instructions

	while(nNxtButtonPressed != nxtOrange)
	{
		if(nNxtButtonPressed == nxtRight)
		{
			value++;
		}
		if(nNxtButtonPressed == nxtLeft)
		{
			value--;
		}
		sprintf(foo, "%i", value);
		displayCenteredTextLine(6, foo);
	}
	return value;
}

bool questionBool(const string questionText, const string leftText, const string rightText)
{
	bool value = false;
	displayCenteredTextLine(1, questionText);//Displays second question
	displayCenteredTextLine(4, leftText); // Displays instructions
	displayCenteredTextLine(3, rightText); // Displays instructions

	while(nNxtButtonPressed != nxtOrange)
	{
		if(nNxtButtonPressed == nxtRight)
		{
			value = true;
		}
		if(nNxtButtonPressed == nxtLeft)
		{
			value = false;
		}
	displayCenteredTextLine(6, value?"true":"false");
	}
	return value;//evaluating the value of value
}
