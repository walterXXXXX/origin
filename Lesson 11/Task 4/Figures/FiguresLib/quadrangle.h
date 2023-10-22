#pragma once
#include "triangle.h"

class FIGURESLIB_API Quadrangle : public Triangle {
public:
	Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD);

	int getLenght_d() override;
	int getAngle_LD() override;

protected:
	int d; // длина 4й стороны
	int LD; // 4й угол
};

