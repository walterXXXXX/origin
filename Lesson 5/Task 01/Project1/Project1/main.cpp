#include <iostream>

class Figure {
public:
	Figure() {
		sidesNumber = 0;
		name = "������";
	}
	int getSidesNumber() { return sidesNumber; }
	std::string getName() { return name; }
protected:
	int sidesNumber;
	std::string name;
};

class Triangle : public Figure {
public:
	Triangle() {
		sidesNumber = 3;
		name = "�����������";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle() {
		sidesNumber = 4;
		name = "���������������";
	}
};

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << "���������� ������:" << std::endl;
	std::cout << figure.getName() << ": " << figure.getSidesNumber() << std::endl;
	std::cout << triangle.getName() << ": " << triangle.getSidesNumber() << std::endl;
	std::cout << quadrangle.getName() << ": " << quadrangle.getSidesNumber() << std::endl;

}