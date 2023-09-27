#include <iostream>
#include <fstream>
#include <string>

struct Adress {
// Адрес не имеет поведения, будем использовать для него struct
	std::string city;
	std::string street;
	std::string home;
	std::string flat;
};

class AdressList {
	// Класс считывает из файла входных данных адреса и хранит их в динамическом массиве
	// Метод outAdressListToFile("fileName") выводит адреса в файл выходных данных
	// Деструктор освобождает память от дин. массива

public:

	AdressList(std::string fileName) {
		if (!getAdressesFromFile(fileName)) {
			addrArray = nullptr; // если не удалось считать адреса из файла, назначаем нулевой указатель
			N = 0;
		}
	}

	~AdressList() {
		if (addrArray != nullptr) delete[] addrArray;
	}

	bool getAdressesFromFile(std::string fileName) {

		// пробуем открыть файл
		std::ifstream fin(fileName);
		if (!fin.is_open()) {
			std::cout << "Ошибка! Не удалось открыть файл " << fileName << std::endl;
			return false;
		}

		// считываем количество адресов из файла
		std::string str;
		fin >> str;
		N = std::stoi(str);

		// если дин. массив со списком уже существует, сначала освободим память от него
		if (addrArray != nullptr) delete[] addrArray;
		
		// создаем новый динамический массив для хранения адресов и считываем в него данные из файла
		addrArray = new Adress[N];
		for (int i = 0; i < N; i++) {
			fin >> addrArray[i].city;
			fin >> addrArray[i].street;
			fin >> addrArray[i].home;
			fin >> addrArray[i].flat;
		}

		fin.close();
		return true;
	}

	void outAdressListToFile(std::string fileName) {

		if (addrArray == nullptr || N <= 0) { std::cout << "Ошибка! Список адресов пуст" << std::endl; return; }

		std::ofstream fout(fileName); // открываем файл выходных данных
		if (!fout.is_open()) {
			std::cout << "Ошибка открытия файла выходных данных '" << fileName << "'" << std::endl;
			return;
		}

		fout << N << std::endl;
		for (int i = N - 1; i >= 0; i--) fout << getOutputString(i) << std::endl;

		fout.close();
	}

private:

	Adress* addrArray; // указатель на динамический массив со списком адресов
	int N; // количество адресов в списке

	std::string getOutputString(int i) {
		// собирает в одну страку данные адреса под номером i
		if (i < 0 || i > N - 1) return ""; // если номер вне диапазона, возвращаем пустую строку
		return addrArray[i].city + ", " + addrArray[i].street + ", " +
			   addrArray[i].home + ", " + addrArray[i].flat + "";
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	AdressList adressList("in.txt");
	adressList.outAdressListToFile("out.txt");
}