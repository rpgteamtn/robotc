#include "functions\AutoProgramQuestions.c"

void back(int time)
{
	motor[motorB] = -100;
	motor[motorC] = -100;
	wait10Msec(time);
}

void forward(int time)
{
	motor[motorB] = 100;
	motor[motorC] = 100;
	wait10Msec(time);
}

task main()
{

	int timeDelay = QuestionInt("amount of delay", "left = minus 1 second","right = add 1 second");//asks the questions and sets RPGtime as the answer either true or false
	bool RPGstart = Question2();
	bool RPGkickStand = Question3();
	bool RPGmove30 = Question4();
	bool RPGmove60 = Question5();
	bool RPGmove90 = Question6();
	bool RPGscore30 = Question7();
	bool RPGscore60 = Question8();
	bool RPGscore90 = Question9();
	bool RPGscoreCenter = Question10();

	waitForStartorButton();

	if(timeDelay == true)
	{
		wait1Msec(10000)
	}
	else
	{
		if(RPGstart == true)
		{
			// add code
		}

		else
		{
			// add code
		}

		if(RPGkickStand == true)
		{
			// add code
		}

		else
		{
			// add code
		}
		if(RPGmove30 == true)
		{
			// add code
		}

		else
		{
			if(RPGmove60 == true)
			{
				// add code
			}

			else
			{
				if(RPGmove90 == true)
				{
					// add code
				}
				else
				{
					// add code
				}
			}


		}

		if(RPGscore30 == true)
		{
			// add code
		}

		else
		{
			if(RPGscore60 == true)
			{
				// add code
			}

			else
			{
				if(RPGscore90 == true)
				{
					// add code
				}

				else
				{
					if(RPGscorecenter == true)
					{
						// add code
					}

					else
					{
						// add code
					}
				}
			}
		}
	}
}
