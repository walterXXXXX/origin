#include <iostream>

#include <stdlib.h>

#include "counter.h"

int main() {

	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	std::string check;
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	std::cin >> check;
	
	int start = 1;
	if (check == "��" || check == "��" || check == "��") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> start;
	}
	
	Counter counter(start);
	
	char command = ' ';
	while (command != 'x') {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> command;
		switch (command) {
			case '+': counter.inc(); break;
			case '-': counter.dec(); break;
			case '=': std::cout << counter.getCurrentPos() << std::endl; break;
			case 'x': std::cout << "�� ��������"; return 0;
		}
	}



}