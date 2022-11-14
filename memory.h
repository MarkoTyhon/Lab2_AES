#pragma once

#include <string>

#include "propertis.h"

struct Memory
{
	Memory();
	
	void addToMem(std::string el);
	void addToMem(int indx, std::string el);
	std::string getFromMem(int indx);
	void showMem();

	std::string memory[RAM];
	int LEI;
};

