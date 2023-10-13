#include <iostream>
#include <exception>
#include <Windows.h>

int function(std::string str, int forbidden_lenght) {

	if (str.length() == forbidden_lenght) throw std::exception();
	return str.length();
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbiddenLenght;
	std::cout << "Введите запретную длину: ";
	std::cin >> forbiddenLenght;

	try {
		std::string word;
		while (1) {
			std::cout << "Введите слово: ";
			std::cin >> word;
			std::cout << "Длина слова \"" << word << "\" равна " << function(word, forbiddenLenght) << std::endl;
		}
	}

	catch (const std::exception& err) {
		std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
	}

}