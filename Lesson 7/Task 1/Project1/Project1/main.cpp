#include <iostream>

#define MODE 1

#ifndef MODE
#error Константа MODE не определена
#endif // !MODE

// #define ADD(a, b) ((a) + (b))
// возможен вариант через макрос, но в задании указано сделать именно через функцию

#if MODE == 1
int ADD(int num1, int num2) {
	return num1 + num2;
}
#endif

int main() {

	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	int num1, num2;
	std::cout << "Работаю в боевом режиме" << std::endl;
	std::cout << "Введите число 1: "; std::cin >> num1;
	std::cout << "Введите число 2: "; std::cin >> num2;
	std::cout << "Результат сложения: " << ADD(num1, num2) << std::endl;
#else 
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif

}