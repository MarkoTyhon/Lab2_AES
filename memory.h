#pragma once

#include <string>

#include "propertis.h"

struct Memory
{
	Memory();
	
	std::string* addToMem(std::string el);
	std::string* addToMem(int indx, std::string el);
	std::string getFromMem(int indx);
	void showMem();

	std::string memory[RAM];
	int LEI;
};

