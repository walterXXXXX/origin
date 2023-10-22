#include "isoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int LA, int LB) : Triangle(a, b, a, LA, LB, LA) {
	name = "Равнобедренный треугольник";
}