/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Input Validation functions
***************************************************************************************************/

#include "List.h"


/****************************************************************************************************
**                                         List constructor
**						Constructs the list array with 4 empty item object pointers
****************************************************************************************************/
List::List()
{
	shopList = new Item[4];
}


/****************************************************************************************************
**                                         List destructor
**						Constructs the list array with 4 empty item object pointers
****************************************************************************************************/
List::~List()
{
	delete[] shopList;
	delete[] expandedList;
	delete[] shortList;
}


/****************************************************************************************************
**                                   overloaded operation function
**			This function overloads the == operator to return the item names of two objects
****************************************************************************************************/
bool operator== (Item a, Item b)
{
	return a.getName() == b.getName();
}


/****************************************************************************************************
**											addItem function
**						This function asks the user to input items into the list
****************************************************************************************************/
void List::addItem()
{
	// Checks to see if the position in the array is equal to the number of objects in the array
	// If they are equal, then the function to expand the array is called to make room for another
	// entry
	
	if (arrayCounter == objsInArray)
	{
		expandArray();
	}

	cout << "Enter the name of the item you want to add to your list:" << endl;
	nameOfItem = inputVal2.isString();
	cout << endl;
	
	cout << "Enter the item unit (can, box, pound, ounce, etc.): " << endl;
	itemUnit = inputVal2.isString();
	cout << endl;

	cout << "Enter the quantity of units you would like to get: " << endl;
	quant = inputVal2.isPosInteger();
	cout << endl;

	cout << "Enter the price of one unit of the item: " << endl;
	pricePerUnit = inputVal2.isFloat();
	cout << endl;
	
	//replaceItem(nameOfItem, itemUnit, quant, pricePerUnit);

	// This loop goes through the array
	for (int i = 0; i < objsInArray; i++)
	{
		// Overloaded operator to compare the item name of the user entered object
		// against each item object in the list
		if (nameOfItem == shopList[i].getName())
		{
			cout << "That item is already on the list." << endl;
			cout << "Do you want to update it?" << endl;
			cout << "Enter 'y' for yes and 'n' for no." << endl;
			char userInput;
			userInput = inputVal2.isChar();

			if (userInput == 'y')
			{
				// The item in the list that matches the one entered by the user is replaced
				shopList[i] = Item (nameOfItem, itemUnit, quant, pricePerUnit);
				printList();
				cout << endl;
				return;
			}

			else if (userInput == 'n')
			{
				// The function is exited
				return;
			}
		}
	}
	
	// If no item is found, the next space in the array is filled with the item entered by the user
	shopList[arrayCounter] = Item(nameOfItem, itemUnit, quant, pricePerUnit);
	// and this variable is incremented to note that it will move to the next available space in the list
	// to fill
	arrayCounter++;

	printList();
	cout << endl;
}


/****************************************************************************************************
**										expandArray function
**				Expands the array when it has reached the end of the empty list
****************************************************************************************************/
void List::expandArray()
{
	// Increments the objects in array variable in order to make space for the next item
	objsInArray++;

	// Dynamically allocates an array filled with empty item objects equal to expanded list
	expandedList = new Item[objsInArray];

	// Loops through the new expanded array and sets each element equal to the item objects
	// in the shopping list array
	for (int i = 0; i < (objsInArray - 1); i++)
	{
		expandedList[i] = shopList[i];
	}
	// Deletes the old shopping list
	delete[] shopList;
	// And sets the new shopping list equal to the expanded array
	shopList = expandedList;
}


/****************************************************************************************************
**                                    removeItem function
**					   Removes an item from the list and compresses the list
****************************************************************************************************/
void List::removeItem()
{
	cout << "Enter the name of the product you want to remove" << endl;
	searchedProduct = inputVal2.isString();

	// Looks for the item that the user wants to remove
	for (int count = 0; count < objsInArray; count++)
	{
		if (searchedProduct == shopList[count].getName())
		{
			// When it finds it, it sets a temp variable equal to the element location in the array
			tempInt = count;
		}
	}

	if (tempInt != -1)
	{
		// From the point where it finds the match...
		for (int count = tempInt; count < (objsInArray - 1); count++)
		{
			// It copies the next element in the array to the current place in the array
			// making it appear that the item was removed from the list and the list was shifted up
			shopList[count] = shopList[count + 1];
		}

		// If there are still empty objects in the array, then the array counter is decreased so it doesn't
		// print in the next space of the array
		if (arrayCounter < objsInArray)
		{
			// Dynamically allocates an array filled with empty item objects equal to number of items in array
			shortList = new Item[objsInArray];
			arrayCounter--;
		}

		// Or else it just decrements the objects in array so the list shrinks
		else
		{
			shortList = new Item[(objsInArray - 1)];
			arrayCounter--;
			objsInArray--;
		}
		
		// Loops through the new expanded array and sets each element equal to the item objects
		// in the shopping list array
		for (int i = 0; i < objsInArray; i++)
		{
			shortList[i] = shopList[i];
		}
		// Deletes the old shopping list
		delete[] shopList;

		// And sets the new shopping list equal to the expanded array
		shopList = shortList;
		printList();
	}
}



/****************************************************************************************************
**                                        printList function
**                    Prints the grocery list and running total to the screen
****************************************************************************************************/
void List::printList()
{
	totalPrice = 0;
	for (int count = 0; count < objsInArray; count++)
	{
		cout << shopList[count].getName() << endl;
		cout << shopList[count].getUnit() << endl;
		cout << shopList[count].getQuantity() << endl;
		cout << shopList[count].getPrice() << endl;
		extendedPrice = shopList[count].getQuantity() * shopList[count].getPrice();
		cout << "Extended Price: " << extendedPrice << endl;
		calculatePrice(extendedPrice);
		cout << endl;
	}
	
	cout << "Total price: " << totalPrice << endl;
}


/****************************************************************************************************
**                                    calculatePrice function
**                       Calculates the total price of all items on the list
****************************************************************************************************/
void List::calculatePrice(double p)
{
	totalPrice += p;
}
