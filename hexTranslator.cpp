#include "hexTranslator.h"

#include <ios>
#include <sstream>

#include "propertis.h"


HexTranslator::HexTranslator() {
	hex_num = 0;
	int dec_num = 0;
	str_hex_num = "";
}

void HexTranslator::numToHex(std::string bin_num) {
	binToDec(bin_num);
	if (dec_num > MAX_NUMBER) toHexNegativ();
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
	std::stringstream ss;
	ss << std::hex << dec_num; // int decimal_value
	std::string res(ss.str());

	str_hex_num = res;
}

void HexTranslator::binToDec(std::string bin_num) {
	int int_bin = std::atoi(bin_num.c_str());
}

void HexTranslator::toHexNegativ() {
	dec_num -= pow(2, BIT) - 1;
	dec_num = 0xffffffff - abs(dec_num) + 1;
}