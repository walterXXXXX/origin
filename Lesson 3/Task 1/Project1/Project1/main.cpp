#include <iostream>

class Calculator {
public:
	Calculator() {
		num1 = 1; num2 = 1;
	}
	double add() { 
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}
	double subtract_1_2() {
		return num1 - num2;
	}
	double subtract_2_1() {
		return num2 - num1;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}
	bool set_num1(double num1) {
		if (num1) this->num1 = num1;
		else std::cout << "Неверный ввод!" << std::endl;
		return num1;
	}
	bool set_num2(double num2) {
		if (num2) this->num2 = num2;
		else std::cout << "Неверный ввод!" << std::endl;
		return num2;
	}

private:
	double num1, num2;

};

int main() {
	
	setlocale(LC_ALL, "");
	
	Calculator calc;

	while (true) {
		
		double num1 = 0, num2 = 0;
		do {
			std::cout << "Введите num1: ";
			std::cin >> num1;
		} while (!calc.set_num1(num1));
		do {
			std::cout << "Введите num2: ";
			std::cin >> num2;
		} while (!calc.set_num2(num2));

		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
	}
}