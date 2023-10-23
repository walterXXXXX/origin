#pragma once
#include <iostream>

class Figure {
public:
	Figure();

	int getSidesNumber();
	std::string getName();

	virtual int getLenght_a();
	virtual int getLenght_b();
	virtual int getLenght_c();
	virtual int getLenght_d();

	virtual int getAngle_LA();
	virtual int getAngle_LB();
	virtual int getAngle_LC();
	virtual int getAngle_LD();

protected:
	int sidesNumber;
	std::string name;
};


