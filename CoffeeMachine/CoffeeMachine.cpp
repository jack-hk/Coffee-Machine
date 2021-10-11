
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

bool debugMode = true; //Debug

//user money
const char* userCurrency = "$";
double startingPocket = 5.99;
double startingBank = 30;

double userPocket = startingPocket;
double userBank = startingBank;

const int DANGER = 20;
const int GREEN = 10;
const int GREY = 8;
const int WHITE = 7;

const int SHORT_TIMER = 1000;
const int LONG_TIMER = 3000;

void StartUp();
void MainMenu();
void ExitProgram();

void ViewBank();
void DrinksMenu();

enum checkAmountOptions {
	checkPocket,
	checkPocketBank,
	checkBank
};

class Drinks {
public:
	int itemID = 0; //make const?
	double itemPrice = 0;
	string itemName;

	friend ostream& operator<<(ostream& output, const Drinks& menu) {
		return output << menu.itemName << endl << userCurrency << menu.itemPrice << endl; //use Price()?
	}

	void DrinksMenu() {
		Drinks Tea;
		Tea.itemID = 1;
		Tea.itemPrice = 5.99;
		Tea.itemName = "English Tea";

		Drinks Coffee;
		Coffee.itemID = 2;
		Coffee.itemPrice = 2.99;
		Coffee.itemName = "Regular Coffee";

		Drinks HotChoc;
		HotChoc.itemID = 3;
		HotChoc.itemPrice = 3.99;
		HotChoc.itemName = "Hot Chocolate";

		cout << endl << Tea << endl << Coffee << endl << HotChoc << endl; //loop automate
	}
};

class Broadcast { //rename
private:
	string divider = " ~~~~ ";
	string eclipse = "...";

	bool TitleCheck(bool title) {
		if (title == true) {
			cout << divider;
			return true;
		}
		else
			return false;
	}
	int ColorText(int color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		return color;
	}

public:
	int input = 0;
	void Message(string msg) {
		cout << msg << endl;
	}
	void TimedMessage(string msg, int color, int time, bool title) {
		ColorText(color);
		Sleep(time / 2);
		TitleCheck(title);
		cout << msg;
		TitleCheck(title);
		cout << endl;
		Sleep(time / 2);
	}
	void Divider(int color, int length) {
		ColorText(color);
		cout << " ";
		for (size_t i = 0; i < length; i++)
		{
			cout << divider[1];
		}
		cout << " " << endl;
	}
	void Loader(int length, int duration) {
		for (size_t i = 0; i < length; i++)
		{
			Sleep(duration / length / 2);
			cout << eclipse << endl;
			Sleep(duration / length / 2);
		}
	}
	void Price(string msg) {
		cout << userCurrency << msg << endl; //work on international currenices (depending on user's country)
	}
	void MenuSelect(string optionA, string optionB, string optionC, string optionD) {
		size_t sizeC = optionC.size();
		size_t sizeD = optionD.size();

		cout << "1 | ";
		Message(optionA);
		cout << "2 | ";
		Message(optionB);
		if (1 < sizeC) {
			cout << "3 | ";
			Message(optionC);
		}
		if (1 < sizeD) {
			cout << "4 | ";
			Message(optionD);
		}
	}
};

class User {
public:
	void CheckAmount(int bank) {
		switch (bank) {
		case checkPocket:
			cout << "User funds: " << userCurrency << userPocket << endl;
			break;
		case checkPocketBank:
			cout << "User funds: " << userCurrency << userPocket << endl;
		case checkBank:
			cout << "Bank funds: " << userCurrency << userBank << endl;
			break;
		default:
			break;
		}
	}
	double ChangeAmount(double input) { //todo
		cin >> input;
		return userBank - input, userPocket + input;
	}
};

int main() {

	StartUp();
	return 0;
}

void StartUp() {
	Broadcast startUp;
	startUp.Divider(10, 34);
	startUp.TimedMessage("Welcome to CoffeeVirtual", GREEN, NULL, true);
	startUp.Divider(10, 34);
	if (debugMode == true) {
		startUp.TimedMessage("Debug Enabled", WHITE, NULL, true);
	}
	else {
		cout << endl;
		startUp.TimedMessage("Starting up", GREY, SHORT_TIMER, false);
		startUp.Loader(3, LONG_TIMER);
		startUp.TimedMessage("Completed", GREY, SHORT_TIMER, false);
	}
	cout << endl;

	MainMenu();
}

void ExitProgram() {
	Broadcast mainMenu;

	mainMenu.TimedMessage("Thank you for using CoffeeVirtual", GREEN, NULL, true);
}

void ViewBank() {
	Broadcast bankMenu;
	User user;

	bankMenu.TimedMessage("Bank", GREEN, NULL, true);
	user.CheckAmount(checkPocketBank);
	bankMenu.Divider(10, 14);
	user.ChangeAmount(NULL);
	user.CheckAmount(checkPocketBank);
}

void DrinksMenu() {
	Broadcast drinksMenu;
	Drinks drinksA;

	Broadcast mainMenu;
	User user;

	drinksMenu.TimedMessage("Drinks Menu", GREEN, NULL, true);
	drinksA.DrinksMenu();
	drinksMenu.Divider(GREEN, 21);
	user.CheckAmount(checkPocketBank);

	mainMenu.TimedMessage("...", GREY, NULL, false);
	mainMenu.Loader(1, SHORT_TIMER);
}

void MainMenu() {
	Broadcast mainMenu;
	User user;

	Broadcast drinksMenu;
	Drinks drinksA;

	mainMenu.TimedMessage("Choose your option", GREEN, NULL, true);
	mainMenu.MenuSelect("Menu", "Start", "Funds", "Exit");

	cin >> mainMenu.input;
	switch (mainMenu.input) {
	case 1:
		DrinksMenu();
		MainMenu();
		break;
	case 2:
		cout << "Start program";
		break;
	case 3:
		ViewBank();
		MainMenu();
		break;
	case 4:
		ExitProgram();
		break;
	default:
		mainMenu.TimedMessage("Invaild Selection!", DANGER, NULL, false);
		mainMenu.TimedMessage("Please choose again:", GREY, LONG_TIMER, false);
		MainMenu();
		break;
	}
}

