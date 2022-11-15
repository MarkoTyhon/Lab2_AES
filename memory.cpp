#include "memory.h"

#include <string>
#include <iostream>

#include "propertis.h"
#include "hexTranslator.h"

Memory::Memory() {
	for (int i = 0; i < RAM; i++) {
		memory[i] = std::string(BIT, '0');
		LEI = 0;
	}
}

void Memory::addToMem(std::string el) {
	memory[LEI] = el;
	++LEI;
}

void Memory::addToMem(int indx ,std::string el) {
	memory[indx] = el;
}

std::string Memory::getFromMem(int indx) {
	return memory[indx];
}

void Memory::showMem() {
	HexTranslator hex;
	int counter = 0;
	for (int j = 0; j < RAM; j++) {
		for (int i= 0; i < HEX_LEN; i++) {
			hex.numToHex(memory[j]);
			std::cout << hex.str_hex_num.at(i);
			if (((i % 2) == 1) && (i != HEX_LEN-1)) std::cout << ".";
		}
		if(j != RAM-1 )std::cout << ".";
	}
	std::cout << "\n";

	for (int i = 0; i < RAM * HEX_LEN / 2; i++) {
		if (counter < 10) std::cout << 0;
		std::cout << counter;
		if (i != RAM * HEX_LEN / 2 - 1) std::cout << ".";
		++counter;
	}
	std::cout << "\n\n";

}
