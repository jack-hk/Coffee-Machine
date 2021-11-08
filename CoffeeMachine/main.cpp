#include "CoffeeMachine.h"

int main() {
	Vendor obj;
	obj.AddDrink(1, 5, "Tea");
	obj.AddDrink(2, 6, "Coffee");
	obj.DrinkMenu();
}