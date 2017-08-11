/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Definitions of Input Validation functions
***************************************************************************************************/

#ifndef MENU_H
#define MENU_H

#include "inputValidation.h"


class Menu
{
	private:
		int		   choice;
		InputValid inputVal1;

	public:
		void displayMenu();
		void setChoice();
		int getChoice();

};
#endif