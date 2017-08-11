/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	cout << "\n Grocery List" << endl;
	cout << "1.  Add an Item" << endl;
	cout << "2.  Remove an Item" << endl;
	cout << "3.  Print grocery list" << endl;
	cout << "4.  Exit" << endl;
	cout << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	cout << "Choose an option: " << endl;
	choice = inputVal1.isPosInteger();

	while (choice > 4 || choice < 1)
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	}
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}