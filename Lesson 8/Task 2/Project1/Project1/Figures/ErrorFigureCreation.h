#pragma once
#include <stdexcept>
#include <string>

class ErrorFigureCreation : public std::domain_error {
public:
	ErrorFigureCreation(std::string errorMessage);
private:
};