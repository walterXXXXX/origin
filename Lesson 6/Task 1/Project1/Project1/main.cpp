#include <iostream>

#include "calculations.h";

int main() {
	setlocale(LC_ALL, "Russian");

	double num1, num2;
	int operation;

	while (true) {
		std::cout << "������� ������ �����: ";
		std::cin >> num1;
		std::cout << "������� ������ �����: ";
		std::cin >> num2;
		std::cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
		std::cin >> operation;

		switch (operation) {
		case 1:
			std::cout << num1 << " ���� " << num2 << " = " << addition(num1, num2) << std::endl;
			break;
		case 2:
			std::cout << num1 << " ����� " << num2 << " = " << subtraction(num1, num2) << std::endl;
			break;
		case 3:
			std::cout << num1 << " �������� �� " << num2 << " = " << multiplication(num1, num2) << std::endl;
			break;
		case 4:
			std::cout << num1 << " �������� �� " << num2 << " = " << division(num1, num2) << std::endl;
			break;
		case 5:
			std::cout << num1 << " � ������� " << num2 << " = " << power(num1, num2) << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	}


}