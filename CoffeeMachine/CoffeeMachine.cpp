
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool debugMode = true; //Debug

class Drinks {
public:
	int itemID = 0; //make const?
	double itemPrice = 0;
	string itemName;
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
		cout << "$" << msg << endl;
	}
};

void StartUp();
void MainMenu();

int main() {
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

	StartUp();
	return 0;
}

void StartUp() {
	Broadcast StartUp;
	StartUp.Divider(10, 34);
	StartUp.TimedMessage("Welcome to CoffeeVirtual", 10, 0, true);
	StartUp.Divider(10, 34);
	if (debugMode == true) {
		StartUp.TimedMessage("Debug Enabled", 7, 0, true);
	}
	cout << endl;
	StartUp.TimedMessage("Starting up", 8, 1000, false);
	StartUp.Loader(3, 3000);
	StartUp.TimedMessage("Completed", 8, 1000, false);
	cout << endl;

	MainMenu();
}

void MainMenu() {
	Broadcast MainMenu;
	MainMenu.TimedMessage("Choose your option.", 10, 0, true);
}
