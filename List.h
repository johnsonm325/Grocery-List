/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Header file for the List class
***************************************************************************************************/

#ifndef LIST_H
#define LIST_H

#include "Item.h"

class List
{
private:
	InputValid	inputVal2;			// Object for input validation class
	Menu	groceryMenu;			// Object for menu class
	Item	item1;					// Object for item class
	Item	*shopList;				// Pointer to item class for array
	Item	*expandedList;			// Pointer to item class for expanded array
	Item	*shortList;
	Item	*rItem;
	string	nameOfItem,				// Input variable for item name
			itemUnit,				// Input variable for item unit
			searchedProduct;		// Input variable for the item user wants to remove from list
	int		quant,					// Input variable for item quantity
			arrayCounter = 0,		// Variable that keeps track of next input into list array
			objsInArray = 4,		// Variable that keeps track of how many objects are in the array
			tempInt;				// A variable that holds temporary integers
	double	pricePerUnit = 0.0,		// Input variable for item price per unit
			extendedPrice = 0.0,	// Variable that holds item price * quantity
			totalPrice;				// Variable that hold the total price of all items on list

public:
	List();
	~List();
	friend bool operator== (Item, Item);
	void menu();
	void addItem();
	void replaceItem(string, string, int, double);
	void expandArray();
	void removeItem();
	void printList();
	void calculatePrice(double);
};
#endif