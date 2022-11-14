#include <iostream>
#include <vector>
#include <string>

#include "fileParser.h"
#include "binTranslator.h"
#include "hexTranslator.h"
#include "memory.h"
#include "processor.h"


int main() {
	BinTranslator bin1;
	bin1.numToBin(11);

	HexTranslator hex1;
	hex1.numToHex(bin1.str_bin_num);
	std::cout << hex1.str_hex_num << "  ";

	bin1.numToBin(-11);
	hex1.numToHex(bin1.str_bin_num);
	std::cout << hex1.str_hex_num << "  ";

}
