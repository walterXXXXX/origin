#include "calculations.h"

#include <limits>

int addition(int num1, int num2) {
	return num1 + num2;
}

int subtraction(int num1, int num2) {
	return num1 - num2;
}

int multiplication(int num1, int num2) {
	return num1 * num2;
}

double division(int num1, int num2) {
	if (num2 != 0) return num1 / num2;
	else return std::numeric_limits<double>::max();
}

int power(int num1, int num2) {
	if (num2 == 0) return 1;
	int result = num1;
	for (int i = 0; i < num2-1; i++) result = result * num1;
	return result;
}