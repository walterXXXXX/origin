#include <iostream>

class Figure {
public:
	Figure() {
		sidesNumber = 0;
		name = "Фигура";
	}
	int getSidesNumber() { return sidesNumber; }
	std::string getName() { return name; }

	virtual int getLenght_a() { return 0; }
	virtual int getLenght_b() { return 0; }
	virtual int getLenght_c() { return 0; }
	virtual int getLenght_d() { return 0; }

	virtual int getAngle_LA() { return 0; }
	virtual int getAngle_LB() { return 0; }
	virtual int getAngle_LC() { return 0; }
	virtual int getAngle_LD() { return 0; }

protected:
	int sidesNumber;
	std::string name;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int LA, int LB, int LC) {
		sidesNumber = 3;
		name = "Треугольник";
		this->a = a; this->b = b; this->c = c;
		this->LA = LA; this->LB = LB; this->LC = LC;
	}
	int getLenght_a() override { return a; }
	int getLenght_b() override { return b; }
	int getLenght_c() override { return c; }
	int getAngle_LA() override { return LA; }
	int getAngle_LB() override { return LB; }
	int getAngle_LC() override { return LC; }

protected:
	int a, b, c; // длины сторон
	int LA, LB, LC; // углы
};

class Quadrangle : public Triangle {
public:
	Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD) : Triangle(a, b, c, LA, LB, LC) {
		sidesNumber = 4;
		name = "Четырехугольник";
		this->d = d; this->LD = LD;
	}

	int getLenght_d() override { return d; }
	int getAngle_LD() override { return LD; }

protected:
	int d; // длина 4й стороны
	int LD; // 4й угол
};

class RectangularTriangle : public Triangle {
public:
	RectangularTriangle(int a, int b, int c, int LA, int LB) : Triangle(a, b, c, LA, LB, 90) { name = "Прямоугольный треугольник"; };
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int LA, int LB) : Triangle(a, b, a, LA, LB, LA) { name = "Равнобедренный треугольник"; };
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; };
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int LA, int LB) : Quadrangle(a, b, a, b, LA, LB, LA, LB) { name = "Параллелограмм"; }
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { name = "Прямоугольник"; }
};

class Rhomb : public Parallelogram {
public:
	Rhomb(int a, int LA, int LB) : Parallelogram(a, a, LA, LB) { name = "Ромб"; }
};

class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) { name = "Квадрат"; }
};

void print_info(Figure* f) {
	
	if (f->getSidesNumber() < 3 || f->getSidesNumber() > 4) {
		std::cout << "Ошибка! Тип фигуры не определен" << std::endl;
		return;
	}

	std::cout << f->getName() << ": " << std::endl;
	
	std::cout << "Стороны: a=" << f->getLenght_a() << " b=" << f->getLenght_b() << " c=" << f->getLenght_c();
	if (f->getSidesNumber() == 4) { std::cout << " d=" << f->getLenght_d(); }
	std::cout << std::endl;

	std::cout << "Углы: A=" << f->getAngle_LA() << " B=" << f->getAngle_LB() << " c=" << f->getAngle_LC();
	if (f->getSidesNumber() == 4) { std::cout << " D=" << f->getAngle_LD(); }
	std::cout << std::endl << std::endl;
}

int main() {

	setlocale(LC_ALL, "Russian");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	RectangularTriangle rectangularTriangle(10, 20, 30, 50, 60);
	IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
	EquilateralTriangle equilateralTriangle(30);

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10,20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhomb rhomb(30, 30, 40);

	print_info(&triangle);
	print_info(&rectangularTriangle);
	print_info(&isoscelesTriangle);
	print_info(&equilateralTriangle);

 	print_info(&quadrangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhomb);

}