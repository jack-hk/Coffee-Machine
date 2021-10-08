
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

class Broadcast {
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
	double userPocket = startingPocket;
	double userBank = startingBank;

	void CheckAmount(int bank) {
		switch (bank) {
		case 1:
			cout << "User funds: " << userCurrency << userPocket << endl;
			break;
		case 2: 
			cout << "User funds: " << userCurrency << userPocket << endl;
		case 3:
			cout << "Bank funds: " << userCurrency << userBank << endl;
			break;
		default:
			break;
		}
	}
	double ChangeAmount() { //todo
		cout << "User funds: " << userCurrency << userBank << endl;
		return userBank;
	}
};

void StartUp();
void MainMenu();
int ExitProgram();

int main() {

	StartUp();
	return 0;
}

void StartUp() {
	Broadcast startUp;
	startUp.Divider(10, 34);
	startUp.TimedMessage("Welcome to CoffeeVirtual", 10, 0, true);
	startUp.Divider(10, 34);
	if (debugMode == true) {
		startUp.TimedMessage("Debug Enabled", 7, 0, true);
	}
	cout << endl;
	startUp.TimedMessage("Starting up", 8, 1000, false);
	startUp.Loader(3, 3000);
	startUp.TimedMessage("Completed", 8, 1000, false);
	cout << endl;

	MainMenu();
}

int ExitProgram() {
	Broadcast mainMenu;

	mainMenu.TimedMessage("Thank you for using CoffeeVirtual", 10, 0, true);
	return 0;
}

void MainMenu() {
	Broadcast mainMenu;
	User user;

	Broadcast drinksMenu;
	Drinks drinksA;

	mainMenu.TimedMessage("Choose your option", 10, 0, true);
	mainMenu.MenuSelect("Menu", "Start", "Funds", "Exit");

	cin >> mainMenu.input;
	switch (mainMenu.input) {
	case 1:
		drinksMenu.TimedMessage("Drinks Menu", 10, 0, true);
		drinksA.DrinksMenu();
		drinksMenu.Divider(10, 21);
		user.CheckAmount(2);

		mainMenu.TimedMessage("...", 8, 0, false);
		mainMenu.Loader(1, 1000);
		MainMenu();
		break;
	case 2:
		cout << "Start program";
		break;
	case 3:
		break;
	case 4:
		ExitProgram();
		break;
	default:
		mainMenu.TimedMessage("Invaild Selection!", 20, 0, false);
		mainMenu.TimedMessage("Please choose again:", 8, 5000, false);
		MainMenu();
		break;
	}
}

