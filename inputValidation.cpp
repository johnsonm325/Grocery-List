/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Definitions of Input Validation functions
***************************************************************************************************/

#include "inputValidation.h"
#include <iostream>
#include <string>

using std::stoi;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**************************************************************************************
**
**************************************************************************************/
InputValid::InputValid()
{
	string input = "";
}


/**************************************************************************************
**
**************************************************************************************/
int InputValid::isPosInteger()
{
	int testInt;	// Variable to hold an integer converted from a string
	tries = 0;		// Variable to hold the number of times a user has tried to enter
					// a value

	do
	{
		counter = 0;	// Increments is character is not a digit or is less than 0

						// If the user has tried to enter a positive integer more than once it prompts
						// a message
		if (tries > 0)
		{
			cout << "Please enter a positive integer" << endl;
			getline(cin, input);
			while (input == "");
			{
				do
				{
					cout << "Please enter a positive integer" << endl;
					getline(cin, input);
				} while (input == "");
			}
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
			if (input == "")
			{
				do
				{
					cout << "Please enter a positive integer" << endl;
					getline(cin, input);
				} while (input == "");
			}
		}

		// Loops through the length of the string and
		for (size_t count = 0; count < input.length(); count++)
		{
			// If the character is not a digit
			if (!(isdigit(input[count])))
			{
				// It increments the count variable
				counter++;
			}
		}

		if (counter == 0)
		{
			// Stores an integer version of the string into testInt
			testInt = stoi(input);

			if (testInt < 0)
			{
				counter++;
			}
		}

		tries++;

	} while (counter > 0);

	return testInt;
}


/**************************************************************************************
**
**************************************************************************************/
string InputValid::isString()
{
	tries = 0;		// Variable to hold the number of times a user has tried to enter
					// a value

	do
	{
		counter = 0;	// Increments is character is not a digit or is less than 0

						// If the user has tried to enter a string more than once it prompts
						// a message
		if (tries > 0)
		{
			cout << "Please enter a string" << endl;
			getline(cin, input);
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
		}

		// Loops through each character of string
		for (size_t count = 0; count < input.length(); count++)
		{
			// If the character is a digit
			if (isdigit(input[count]))
			{
				// Then it increments the counter
				counter++;
			}
		}

		// If none of the characters in the string were digits
		if (counter == 0)
		{
		// Loop through string and turn each character into lowercase
		for (size_t count = 0; count < input.length(); count++)
		{
		input[count] = tolower(input[count]);
		}
		}

		// Increment tries at end of loop if it fails so the next loop
		// will ask the user to enter a string
		tries++;

	} while (counter > 0);
	return input;
}


/**************************************************************************************
**
**************************************************************************************/
double InputValid::isFloat()
{
	tries = 0;		// Variable to hold the number of times a user has tried to enter
					// a value

	do
	{
		counter = 0;	// Increments is character is a digit or is less than 0

		if (tries > 0)	// If the user has tried to enter a float more than once it prompts
						// a message
		{
			cout << "Please enter a Float" << endl;
			getline(cin, input);
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
		}

		for (size_t count = 0; count < input.length(); count++)
		{
			// If the element is not a digit
			if (!(isdigit(input[count])))
			{
				// and it is a period
				if (input[count] == '.')
				{
					counter++;
				}
				// If it's something other than a period, the counter increments
				// by 2 so it will exit the do/while loop and retry
				else
				{
					counter += 2;
				}
			}
		}

		// If the counter equals 1, then all elements were digits except 1 period
		if (counter == 1)
		{
			return stod(input);
		}
		// If it's anything other than 1, then tries will increment
		else if (counter != 1)
		{
			tries++;
		}

	} while (counter > -1);

}


/**************************************************************************************
**
**************************************************************************************/
char InputValid::isChar()
{
	tries = 0;			// Variable to hold the number of times a user has tried to enter
						// a value
	do
	{
		if (tries > 0)	// If the user has tried to enter a character more than once it prompts
						// a message
		{
			cout << "Please enter a character" << endl;
			getline(cin, input);
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
		}

		tries++;

	} while (input.length() > 1 || !isalpha(input[0]));

	return input[0];
}