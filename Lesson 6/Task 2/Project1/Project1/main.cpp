#include <iostream>

#include <stdlib.h>

#include "counter.h"

int main() {

	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	std::string check;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> check;
	
	int start = 1;
	if (check == "да" || check == "Да" || check == "ДА") {
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> start;
	}
	
	Counter counter(start);
	
	char command = ' ';
	while (command != 'x') {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;
		switch (command) {
			case '+': counter.inc(); break;
			case '-': counter.dec(); break;
			case '=': std::cout << counter.getCurrentPos() << std::endl; break;
			case 'x': std::cout << "До свидания"; return 0;
		}
	}



}