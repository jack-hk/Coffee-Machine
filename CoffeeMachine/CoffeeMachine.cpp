// CoffeeMachine.cpp 

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void customChar(string msg) {
	std::cout << msg << std::endl;
	Sleep(1000);
}

void emptyChar() {
	std::cout << std::endl;
	Sleep(1000);
}

void pointsChar() {
	std::cout << "..." << std::endl;
	Sleep(1500);
}

int main()
{
	std::cout << "Welcome to CoffeeVirtual (10.2020)" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0) {
			emptyChar();
			std::cout << "Loading: Initialised" << std::endl;
		}
		else if (i == 3) {
			std::cout << "Loading: Completed" << std::endl;
		}
		if (i < 3) {
			pointsChar();
		}
	}
	std::cout << "Please make your selection:" << std::endl;

	
}


