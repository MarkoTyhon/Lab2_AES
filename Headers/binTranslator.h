#pragma once

#include <string>
#include <vector>

struct BinTranslator
{
	void numToBin(float dec_num);

	int bin_num = 0;
	std::string str_bin_num = "";
};