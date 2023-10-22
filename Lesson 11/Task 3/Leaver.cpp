#include <iostream>
#include <Windows.h>

#include "LeaverLib.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Leaver leaver;

	std::cout << "¬ведите им€: ";
	std::string name;
	std::cin >> name;

	std::cout << leaver.leave(name);

	return 0;
}