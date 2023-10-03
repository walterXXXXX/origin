#include <iostream>

#include "Figures/figure.h"
#include "Figures/triangle.h"
#include "Figures/quadrangle.h"
#include "Figures/rectangularTriangle.h"
#include "Figures/isoscelesTriangle.h"
#include "Figures/equilateralTriangle.h"
#include "Figures/parallelogram.h"
#include "Figures/rectangle.h"
#include "Figures/rhomb.h"
#include "Figures/square.h"


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