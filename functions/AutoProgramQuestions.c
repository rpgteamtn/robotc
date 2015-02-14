#include "rpgCommon.c"

int questionInt(const string squestionText, const string sleftText, const string srightText,
const int MIN, const int MAX)
{ //For a question with an integer answer, function parameters include question, left button effect,
	//right button effect, minimum value, and maximum value
	int ivalue = 0; //set answer originally to 0
	displayCenteredTextLine(1, squestionText);//Displays question
	displayCenteredTextLine(3, sleftText); // Displays instructions for left button
	displayCenteredTextLine(4, srightText); // Displays instructions for right button

	repeatUntil(nNxtButtonPressed == nxtOrange) //Let user keep changing value until he/she presses orange button
	{
		while(nNxtButtonPressed == noButton) //Wait until no button is pressed
		{ }
		if(nNxtButtonPressed == nxtRight) //if the button pressed is the right arrow
		{
			if(ivalue < MAX) //as long as current value is less than the maximum
			{
				ivalue++; //increase value by 1
			}
			else //if current value is at maximum
			{
				displayCenteredTextLine(7, "error: reached max num"); //let user know
			}
		}
		if(nNxtButtonPressed == nxtLeft) //if the button pressed is the left arrow
		{
			if(ivalue > MIN) //as long as current value is greater than minimum
			{
				ivalue--; //decrease by 1
			}
			else //if curretn value is at minimum
			{
				displayCenteredTextLine(7, "error: reached min num"); //let user know
			}
		}
		if(nxtOrange == nNxtButtonPressed) //if button pressed is orange button
		{
			break; //break out of the loop
		}
		displayCenteredTextLine(6, "value = %i", ivalue); //Tell user what value is
		repeatUntil(nNxtButtonPressed == noButton) //When user lets go, end function
		{}
	}
	eraseDisplay();

	return ivalue;
}

bool questionBool(const string squestionText, const string sleftText, const string srightText)
{ //For a question with a boolean answer, function parameters include the question, left button effect,
	//and right button effect
	bool bvalue = false; //set value to false
	displayCenteredTextLine(1, squestionText);//Displays question
	displayCenteredTextLine(4, sleftText); // Displays instructions for left button
	displayCenteredTextLine(3, srightText); // Displays instructions for right button

	repeatUntil(nNxtButtonPressed == nxtOrange) //repeat until orange button is pressed
	{

		while(nNxtButtonPressed == noButton) //Whenever no buttons are pressed, do nothing
		{	}

		if(nNxtButtonPressed == nxtRight) //if right button is pressed
		{
			bvalue = true; //set boolean value to true
		}
		if(nNxtButtonPressed == nxtLeft) //if left button is pressed
		{
			bvalue = false; //set boolean value to false
		}
		if(nxtOrange == nNxtButtonPressed) //if orange button is pressed
		{
			break; //break out of the loop
		}
	displayCenteredTextLine(6, bvalue?"true":"false"); //Let user know result
	}
	repeatUntil(nNxtButtonPressed == noButton) //When no button is pressed, end function
	{}
	eraseDisplay();

	return bvalue;
}

bool lastQuestion() //The last question: verifies your answers
{
	bool bvalue = false; //set boolean value to false
	displayCenteredTextLine(0, "Are these values correct?");//Displays question
	displayCenteredTextLine(1, "right = yes"); // Displays instructions for right button
	displayCenteredTextLine(2, "left = no"); // Displays instructions for left button

	repeatUntil(nNxtButtonPressed == nxtOrange) //repeat until orange button is pressed
	{

		while(nNxtButtonPressed == noButton) //When no button is pressed, do nothing
		{	}

		if(nNxtButtonPressed == nxtRight) //If right button is pressed, set value to true
		{
			bvalue = true;
		}
		if(nNxtButtonPressed == nxtLeft) //If left button is pressed, set value to false
		{
			bvalue = false;
		}
		if(nxtOrange == nNxtButtonPressed) //If orange button is pressed, break out of the loop
		{
			break;
		}
	displayCenteredTextLine(6, bvalue?"true":"false"); //Let user know the result
		repeatUntil(nNxtButtonPressed == noButton) //When user let go, end the function
		{}

		eraseDisplay();
	}
	return bvalue;
}
