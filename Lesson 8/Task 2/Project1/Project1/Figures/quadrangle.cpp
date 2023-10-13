#include "quadrangle.h"

Quadrangle::Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD) {
	if ((LA+LB+LC+LD)!=360) throw ErrorFigureCreation("у четырехугольника сумма углов не равна 360");
	sidesNumber = 4;
	name = "Четырехугольник";
	this->a = a; this->b = b; this->c = c; this->d = d;
	this->LA = LA; this->LB = LB; this->LC = LC; this->LD = LD;
}

int Quadrangle::getLenght_a() { return a; }
int Quadrangle::getAngle_LA() { return LA; }
int Quadrangle::getLenght_b() { return b; }
int Quadrangle::getAngle_LB() { return LB; }
int Quadrangle::getLenght_c() { return c; }
int Quadrangle::getAngle_LC() { return LC; }
int Quadrangle::getLenght_d() { return d; }
int Quadrangle::getAngle_LD() { return LD; }
