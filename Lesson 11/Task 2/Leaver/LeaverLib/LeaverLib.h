#pragma once
#include <iostream>

#ifdef LEAVERLIB_EXPORTS
#define LEAVERLIB_API __declspec(dllexport)
#else
#define LEAVERLIB_API __declspec(dllimport)
#endif

class Leaver {
public:
	LEAVERLIB_API std::string leave(std::string name);
};