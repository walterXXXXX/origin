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
#include "Figures/ErrorFigureCreation.h"


void print_info(Figure* f) {
	
	if (f == nullptr) { std::cout << "Тип фигуры не определен"; return; }

	std::cout << f->getName();
	std::cout << " (cтороны " << f->getLenght_a() << ", " << f->getLenght_b() << ", " << f->getLenght_c();
	if (f->getSidesNumber() == 4) { std::cout << ", " << f->getLenght_d(); }

	std::cout << "; углы: " << f->getAngle_LA() << ", " << f->getAngle_LB() << ", " << f->getAngle_LC();
	if (f->getSidesNumber() == 4) { std::cout << ", " << f->getAngle_LD(); }
	std::cout << ") создан" << std::endl;
}

int main() {

	setlocale(LC_ALL, "Russian");

	try {
		Triangle triangle(10, 20, 30, 50, 60, 70);
		print_info(&triangle);

		RectangularTriangle rectangularTriangle(10, 20, 30, 30, 60);
		print_info(&rectangularTriangle);

		IsoscelesTriangle isoscelesTriangle(10, 20, 60, 60);
		print_info(&isoscelesTriangle);

		EquilateralTriangle equilateralTriangle(30);
		print_info(&equilateralTriangle);

		Quadrangle quadrangle(10, 20, 30, 40, 150, 60, 70, 80);
		print_info(&quadrangle);

		Rectangle rectangle(10, 20);
		print_info(&rectangle);

		Square square(20);
		print_info(&square);

		Parallelogram parallelogram(20, 30, 30, 40);
		print_info(&parallelogram);

		Rhomb rhomb(30, 30, 40);
		print_info(&rhomb);
	}
	catch (const ErrorFigureCreation& err) { 
		std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
	}

}