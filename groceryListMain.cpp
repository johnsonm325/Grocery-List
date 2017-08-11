/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Main function
***************************************************************************************************/

#include "List.h"

int main()
{
	Menu groceryMenu;
	List list1;
	do
	{

		groceryMenu.displayMenu();
		groceryMenu.setChoice();

	
		if (groceryMenu.getChoice() == 1)
		{
			list1.addItem();
		}

		else if (groceryMenu.getChoice() == 2)
		{
			list1.removeItem();
		}

		else if (groceryMenu.getChoice() == 3)
		{
			list1.printList();
		}
	} while (groceryMenu.getChoice() != 4);

	return 0;
}