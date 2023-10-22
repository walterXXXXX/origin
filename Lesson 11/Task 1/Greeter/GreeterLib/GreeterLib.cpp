#include "GreeterLib.h"
#include <iostream>

std::string Greeter::greet(std::string name) {
	return "Здравствуйте, " + name + "!\n";
}