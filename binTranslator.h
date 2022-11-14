#pragma once

#include <string>
#include <vector>

struct BinTranslator
{
	void numToBin(int dec_num);
	void toNBin();
	void toBin(int dec_num);
	void toBinNegativ();
	void inversion();
	void add_one();

	int bin_num = 0;
	std::string str_bin_num = "";
};