/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/19/2017
** Description: Header file for Item class
***************************************************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include "Menu.h"

class Item
{
private:
	string	itemName,		// Name of item
			unit;			// Unit of item
	int		quantity;		// Quantity of item
	double	unitPrice,		// Price of the unit of item
			extendedPrice;	// Price of unit of item multiplied by quantity of item

public:
	Item();
	Item(string, string, int, double);
	string getName();
	string getUnit();
	int getQuantity();
	double getPrice();
};
#endif