#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>


using namespace std;

//#ifdef _DEBUG
//bool debugMode = true; //Debug
//#endif // _DEBUG

class UserInterface {
public:
	enum Colors {
		GREY = 8,
		RED = 20,
		GREEN = 10,
		WHITE = 7,
	};

	int ColorText(int color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		return color;
	}
};

class UserController {

};

struct Drink {
	int itemID = 0;
	int itemPrice = 0;
	string itemName = "";
	friend ostream& operator<<(ostream& output, const Drink& item) {
		return output << item.itemName << endl << "$" << item.itemPrice << endl;
	}
};
class Vendor {

	const char* userCurrency = "$";

	double bankFunds = 30;
	double userFunds = 10;



	vector<Drink> Menu;
public:

	void AddDrink(int itemID, int itemPrice, string itemName);

	void DrinkMenu() {
		for (size_t i = 0; i < Menu.size(); i++) //parse function
		{
#ifdef _DEBUG
			cout << "debugging";
#endif
			cout << Menu[i] << endl;
			//loop automate, best way of handling inputs, need header files?
		}
	}

};
























