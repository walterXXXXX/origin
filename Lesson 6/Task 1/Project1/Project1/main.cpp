#include <iostream>

#include "calculations.h";

int main() {
	setlocale(LC_ALL, "Russian");

	double num1, num2;
	int operation;

	while (true) {
		std::cout << "Введите первое число: ";
		std::cin >> num1;
		std::cout << "Введите второе число: ";
		std::cin >> num2;
		std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
		std::cin >> operation;

		switch (operation) {
		case 1:
			std::cout << num1 << " плюс " << num2 << " = " << addition(num1, num2) << std::endl;
			break;
		case 2:
			std::cout << num1 << " минус " << num2 << " = " << subtraction(num1, num2) << std::endl;
			break;
		case 3:
			std::cout << num1 << " умножить на " << num2 << " = " << multiplication(num1, num2) << std::endl;
			break;
		case 4:
			std::cout << num1 << " поделить на " << num2 << " = " << division(num1, num2) << std::endl;
			break;
		case 5:
			std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	}


}