#include "figure.h"

Figure::Figure() {
	sidesNumber = 0;
	name = "Фигура";
}

int Figure::getSidesNumber() { return sidesNumber; }

std::string Figure::getName() { return name; }

int Figure::getLenght_a() { return 0; }
int Figure::getLenght_b() { return 0; }
int Figure::getLenght_c() { return 0; }
int Figure::getLenght_d() { return 0; }

int Figure::getAngle_LA() { return 0; }
int Figure::getAngle_LB() { return 0; }
int Figure::getAngle_LC() { return 0; }
int Figure::getAngle_LD() { return 0; }