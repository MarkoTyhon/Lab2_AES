#pragma once

#include<string>
#include <vector>

struct HexTranslator {
	HexTranslator();

	void numToHex(std::string bin_num);
	void toNHex();
	void toHex();
	void toHexNegativ();
	void binToDec(std::string bin_num);
	
	int hex_num = 0;
	int dec_num = 0;
	std::string str_hex_num = "";
};