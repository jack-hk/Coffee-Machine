
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
	void ColorText(int color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

public:
	void Message(string msg) {
		cout << msg << endl;
	}
	void Divider(int color) {
		ColorText(color);
		cout << eclipse << endl;
	}
	void TimedMessage(string msg, int color, int time, bool title) {
		ColorText(color);
		TitleCheck(title);
		cout << msg;
		TitleCheck(title);
		cout << endl;
		Sleep(time);
	}
	void Price(string msg) {		//sample
		cout << "$" << msg << endl;
	}
};

void MainMenu() {
	Broadcast MainMenu;
	MainMenu.TimedMessage("Hello World", 10, 3000, true);
	MainMenu.TimedMessage("Hello World", 5, 3000, false);
	MainMenu.Divider(8);
	MainMenu.Price("5.99");
}

int main() {
	MainMenu();
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

	return 0;
}
