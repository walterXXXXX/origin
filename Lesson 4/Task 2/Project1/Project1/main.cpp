#include <iostream>
#include <fstream>
#include <string>

struct Adress {
	std::string city;
	std::string street;
	std::string home;
	int flat;
};

class AdressList {
public:

	AdressList(std::string fileName) {
		// класс инициализируется файлом входных данных
		addrArray = nullptr;
		getAdressListFromFile(fileName);
	}

	~AdressList() {
		if (addrArray != nullptr) delete[] addrArray;
	}

	bool outAdressListToFile(std::string fileName) {

		std::ofstream fout(fileName);
		if (fout.is_open()) {
			fout << N << std::endl;
			for (int i = 0; i < N; i++) {
				fout << composeAdress(i) << std::endl;
			}
			fout.close();
			return true;
		}
		else {
			std::cout << "Ошибка! Не удалось открыть файл выходных данных '" << fileName << "'" << std::endl;
			return false;
		}
	}

	void sortList() {
		bool isSorted = false;
		while (!isSorted) {
			isSorted = true;
			for (int i = 0; i < N - 1; i++) {
				if (addrArray[i].city > addrArray[i + 1].city) { swap(i); isSorted = false; }
				if (addrArray[i].city == addrArray[i + 1].city)
					if (addrArray[i].street > addrArray[i + 1].street) swap(i);
			}
		}
	}

private:

	Adress* addrArray; //массив адресов
	int N; // кол-во адресов

	bool getAdressListFromFile(std::string fileName) {
		
		std::ifstream fin(fileName);

		if (fin.is_open()) {
			// считываем кол-во адресов из файла
			std::string str;
			fin >> str;
			N = std::stoi(str);
			
			//создаем дин. массив и заполняем его данными адресов
			addrArray = new Adress[N];
			for (int i = 0; i < N; i++) {
				fin >> addrArray[i].city;
				fin >> addrArray[i].street;
				fin >> addrArray[i].home;
				fin >> str;
				addrArray[i].flat = std::stoi(str);
			}

			fin.close();
			return true;
		}
		else {
			std::cout << "Ошибка! Не удалось открыть файл входных данных " << fileName << std::endl;
			return false;
		}
	}

	std::string composeAdress(int num) {
		// составляет адрес под номером num в списке в одну строку 
		return addrArray[num].city + ", " + addrArray[num].street + ", " + addrArray[num].home + ", " + std::to_string(addrArray[num].flat);
	}

	void copyAdress(Adress& dest, Adress from) {
		// копирование адресса 
		dest.city = from.city;
		dest.street = from.street;
		dest.home = from.home;
		dest.flat = from.flat;
	}

	void swap(int i) {	
		// меняет местами позиции массива адресов с номерами i и i+1
		if (i < 0 || i >= N) return;
		Adress buf;
		copyAdress(buf, addrArray[i]);
		copyAdress(addrArray[i], addrArray[i+1]);
		copyAdress(addrArray[i+1], buf);
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	AdressList adressList("in.txt");
	adressList.sortList();
	adressList.outAdressListToFile("out.txt");
}