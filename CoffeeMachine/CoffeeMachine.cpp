
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class DrinksMenu {
public:
	int itemID;
	double itemPrice;
	string itemName;
};

void Broadcast(string msg) {
	cout << msg;
}

int main() {

	bool debugMode = true;

	DrinksMenu Coffee;
	Coffee.itemID = 4;
	Coffee.itemPrice = 2.99;
	Coffee.itemName = "Regular Coffee";

	DrinksMenu Tea;
	Tea.itemID = 1;
	Tea.itemPrice = 5.99;
	Tea.itemName = "Tea";

	Broadcast(Tea.itemName);

	return 0;
}