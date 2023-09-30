#include <iostream>

class Figure {
public:
	Figure() {
		sidesNumber = 0;
		name = "Фигура";
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
		name = "Треугольник";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle() {
		sidesNumber = 4;
		name = "Четырехугольник";
	}
};

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << "Количество сторон:" << std::endl;
	std::cout << figure.getName() << ": " << figure.getSidesNumber() << std::endl;
	std::cout << triangle.getName() << ": " << triangle.getSidesNumber() << std::endl;
	std::cout << quadrangle.getName() << ": " << quadrangle.getSidesNumber() << std::endl;

}