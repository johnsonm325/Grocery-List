/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Item class functions
***************************************************************************************************/

#include "Item.h"

// Default constructor sets objects to empty variables
Item::Item()
{
	this->itemName = "";
	this->unit = "";
	this->quantity = 0;
	this->unitPrice = 0;
}

// Constructor creates objects based on parameters
Item::Item(string i, string u, int q, double p)
{
	itemName = i;
	unit = u;
	quantity = q;
	unitPrice = p;
}


string Item::getName()
{
	return itemName;
}


string Item::getUnit()
{
	return unit;
}


int Item::getQuantity()
{
	return quantity;
}


double Item::getPrice()
{
	return unitPrice;
}