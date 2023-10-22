#include "quadrangle.h"

Quadrangle::Quadrangle(int a, int b, int c, int d, int LA, int LB, int LC, int LD) : Triangle(a, b, c, LA, LB, LC) {
	sidesNumber = 4;
	name = "Четырехугольник";
	this->d = d; this->LD = LD;
}

int Quadrangle::getLenght_d() { return d; }
int Quadrangle::getAngle_LD() { return LD; }