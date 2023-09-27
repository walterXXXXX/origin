#include <iostream>
#include <fstream>
#include <string>

struct Adress {
// ����� �� ����� ���������, ����� ������������ ��� ���� struct
	std::string city;
	std::string street;
	std::string home;
	std::string flat;
};

class AdressList {
	// ����� ��������� �� ����� ������� ������ ������ � ������ �� � ������������ �������
	// ����� outAdressListToFile("fileName") ������� ������ � ���� �������� ������
	// ���������� ����������� ������ �� ���. �������

public:

	AdressList(std::string fileName) {
		if (!getAdressesFromFile(fileName)) {
			addrArray = nullptr; // ���� �� ������� ������� ������ �� �����, ��������� ������� ���������
			N = 0;
		}
	}

	~AdressList() {
		if (addrArray != nullptr) delete[] addrArray;
	}

	bool getAdressesFromFile(std::string fileName) {

		// ������� ������� ����
		std::ifstream fin(fileName);
		if (!fin.is_open()) {
			std::cout << "������! �� ������� ������� ���� " << fileName << std::endl;
			return false;
		}

		// ��������� ���������� ������� �� �����
		std::string str;
		fin >> str;
		N = std::stoi(str);

		// ���� ���. ������ �� ������� ��� ����������, ������� ��������� ������ �� ����
		if (addrArray != nullptr) delete[] addrArray;
		
		// ������� ����� ������������ ������ ��� �������� ������� � ��������� � ���� ������ �� �����
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

		if (addrArray == nullptr || N <= 0) { std::cout << "������! ������ ������� ����" << std::endl; return; }

		std::ofstream fout(fileName); // ��������� ���� �������� ������
		if (!fout.is_open()) {
			std::cout << "������ �������� ����� �������� ������ '" << fileName << "'" << std::endl;
			return;
		}

		fout << N << std::endl;
		for (int i = N - 1; i >= 0; i--) fout << getOutputString(i) << std::endl;

		fout.close();
	}

private:

	Adress* addrArray; // ��������� �� ������������ ������ �� ������� �������
	int N; // ���������� ������� � ������

	std::string getOutputString(int i) {
		// �������� � ���� ������ ������ ������ ��� ������� i
		if (i < 0 || i > N - 1) return ""; // ���� ����� ��� ���������, ���������� ������ ������
		return addrArray[i].city + ", " + addrArray[i].street + ", " +
			   addrArray[i].home + ", " + addrArray[i].flat + "";
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	AdressList adressList("in.txt");
	adressList.outAdressListToFile("out.txt");
}