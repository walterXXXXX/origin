#pragma once

#include "figure.h"

class FIGURESLIB_API Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int LA, int LB, int LC);
	int getLenght_a() override;
	int getLenght_b() override;
	int getLenght_c() override;
	int getAngle_LA() override;
	int getAngle_LB() override;
	int getAngle_LC() override;

protected:
	int a, b, c; // длины сторон
	int LA, LB, LC; // углы
};
