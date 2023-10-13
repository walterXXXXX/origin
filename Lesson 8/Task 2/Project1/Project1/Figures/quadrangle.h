#pragma once

#include "figure.h"
#include "ErrorFigureCreation.h"

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD);
	int getLenght_a() override;
	int getLenght_b() override;
	int getLenght_c() override;
	int getLenght_d() override;
	int getAngle_LA() override;
	int getAngle_LB() override;
	int getAngle_LC() override;
	int getAngle_LD() override;

protected:
	int a, b, c, d; // длины сторон
	int LA, LB, LC, LD; // углы
};

