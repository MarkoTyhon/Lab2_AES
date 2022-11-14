#include "memory.h"

#include <string>

#include "propertis.h"

Memory::Memory() {
	for (int i = 0; i < RAM; i++) {
		memory[i] = std::string(BIT, '0');
	}
}

std::string* Memory::addToMem(std::string el) {
	memory[LEI] = el;
	return &memory[LEI];
}

std::string* Memory::addToMem(int indx ,std::string el) {
	memory[indx] = el;
	return &memory[indx];
}

std::string Memory::getFromMem(int indx) {
	return memory[indx];
}

void Memory::showMem() {

}
