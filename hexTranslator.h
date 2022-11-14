#pragma once

#include<string>
#include <vector>

struct HexTranslator {
	void numToHex(std::string bin_num);
	void toNHex();
	void toHex();
	

	std::string bin_num;
	std::string str_hex_num;
}; 