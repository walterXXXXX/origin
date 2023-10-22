#pragma once
#include <iostream>

#ifdef FIGURESLIB_EXPORTS
#define FIGURESLIB_API __declspec(dllexport)
#else
#define FIGURESLIB_API __declspec(dllimport)
#endif

class FIGURESLIB_API Figure {
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


