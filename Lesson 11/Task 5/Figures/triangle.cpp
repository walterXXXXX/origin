#include "triangle.h"

Triangle::Triangle(int a, int b, int c, int LA, int LB, int LC) {
	sidesNumber = 3;
	name = "Треугольник";
	this->a = a; this->b = b; this->c = c;
	this->LA = LA; this->LB = LB; this->LC = LC;
}

int Triangle::getLenght_a() { return a; }
int Triangle::getLenght_b() { return b; }
int Triangle::getLenght_c() { return c; }
int Triangle::getAngle_LA() { return LA; }
int Triangle::getAngle_LB() { return LB; }
int Triangle::getAngle_LC() { return LC; }