#include <iostream>

class Figure {
public:
	Figure() {
		sidesNumber = 0;
		name = "������";
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

	virtual void info() {
		std::cout << this->name << ": " << std::endl;
		if (this->isCorrect()) std::cout << "����������" << std::endl;
		else std::cout << "������������" << std::endl;
		std::cout << "���������� ������: " << sidesNumber << std::endl;
	}

	virtual bool isCorrect() {
		return (sidesNumber == 0);
	}

protected:
	int sidesNumber;
	std::string name;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int LA, int LB, int LC) {
		sidesNumber = 3;
		name = "�����������";
		this->a = a; this->b = b; this->c = c;
		this->LA = LA; this->LB = LB; this->LC = LC;
	}
	int getLenght_a() override { return a; }
	int getLenght_b() override { return b; }
	int getLenght_c() override { return c; }
	int getAngle_LA() override { return LA; }
	int getAngle_LB() override { return LB; }
	int getAngle_LC() override { return LC; }

	void info() override {
		Figure::info();
		std::cout << "�������: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "����: A=" << LA << " B=" << LB << " C=" << LC << std::endl;
	}

	bool isCorrect() override {
		return (sidesNumber == 3 && (LA + LB + LC) == 180);
	}

protected:
	int a, b, c; // ����� ������
	int LA, LB, LC; // ����
};

class Quadrangle : public Triangle {
public:
	Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD) : Triangle(a, b, c, LA, LB, LC) {
		sidesNumber = 4;
		name = "���������������";
		this->d = d; this->LD = LD;
	}

	int getLenght_d() override { return d; }
	int getAngle_LD() override { return LD; }

	void info() override {
		Figure::info();
		std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "����: A=" << LA << " B=" << LB << " C=" << LC << " D=" << LD << std::endl;
	}

	bool isCorrect() override {
		return (sidesNumber == 4 && (LA + LB + LC + LD) == 360);
	}

protected:
	int d; // ����� 4� �������
	int LD; // 4� ����
};

class RectangularTriangle : public Triangle {
public:
	RectangularTriangle(int a, int b, int c, int LA, int LB) : Triangle(a, b, c, LA, LB, 90) { name = "������������� �����������"; };

	bool isCorrect() override {
		return (Triangle::isCorrect() && LC == 90);
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int LA, int LB) : Triangle(a, b, a, LA, LB, LA) { name = "�������������� �����������"; };

	bool isCorrect() override {
		return (Triangle::isCorrect() && a == c && LA == LC);
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) { name = "�������������� �����������"; };

	bool isCorrect() override {
		return (Triangle::isCorrect() && a == b && b == c && LA == 60 && LB == 60 && LC == 60);
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int LA, int LB) : Quadrangle(a, b, a, b, LA, LB, LA, LB) { name = "��������������"; }

	bool isCorrect() override {
		return (Quadrangle::isCorrect() && a == c && b == d && LA == LC && LB == LD);
	}
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { name = "�������������"; }

	bool isCorrect() override {
		return (Parallelogram::isCorrect() && LA == 90 && LB == 90 && LC == 90 && LD == 90);
	}
};

class Rhomb : public Parallelogram {
public:
	Rhomb(int a, int LA, int LB) : Parallelogram(a, a, LA, LB) { name = "����"; }

	bool isCorrect() override {
		return (Parallelogram::isCorrect() && a == b && b == c && c == d);
	}
};

class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) { name = "�������"; }

	bool isCorrect() override {
		return (Rectangle::isCorrect() && a == b && b == c && c == d);
	}
};


int main() {

	setlocale(LC_ALL, "Russian");

	Figure* figures[20];
	int c = 0;

	Figure figure; 
	figures[c++] = &figure;

	Triangle triangle(10, 20, 30, 50, 60, 70); 
	figures[c++] = &triangle;

	RectangularTriangle rectangularTriangle1(10, 20, 30, 50, 60); 
	figures[c++] = &rectangularTriangle1;

	RectangularTriangle rectangularTriangle2(10, 20, 30, 50, 40); 
	figures[c++] = &rectangularTriangle2;

	IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60); 
	figures[c++] = &isoscelesTriangle;

	EquilateralTriangle equilateralTriangle(30); 
	figures[c++] = &equilateralTriangle;

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80); 
	figures[c++] = &quadrangle;

	Rectangle rectangle(10, 20); 
	figures[c++] = &rectangle;

	Square square(20); 
	figures[c++] = &square;

	Parallelogram parallelogram(20, 30, 30, 40); 
	figures[c++] = &parallelogram;

	Rhomb rhomb(30, 30, 40); 
	figures[c++] = &rhomb;

	for (int i = 0; i < c - 1; i++) { figures[i]->info(); std::cout << std::endl; }

}