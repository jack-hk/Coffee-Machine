#include  "CoffeeMachine.h"

void Vendor::AddDrink(int itemID, int itemPrice, string itemName) {
	Drink NewDrink;
	NewDrink.itemID = itemID;
	NewDrink.itemPrice = itemPrice;
	NewDrink.itemName = itemName;
	Menu.push_back(NewDrink);
}