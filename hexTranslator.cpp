#include "hexTranslator.h"

#include <ios>
#include <sstream>
#include <bitset>

#include "propertis.h"


void HexTranslator::numToHex(std::string binn) {
	bin_num = binn;
	toHex();
	toNHex();
	
}
void HexTranslator::toNHex() {
	int hex_len;
	hex_len = str_hex_num.length();

	str_hex_num = std::string(HEX_LEN - hex_len, '0') + str_hex_num;
}

void HexTranslator::toHex()
{  
	std::bitset<BIT> set(bin_num);
	std::stringstream res;
	res << std::hex << std::uppercase << set.to_ulong();
	str_hex_num = res.str();
}
