# include "binTranslator.h"

#include <string>
#include <vector>
#include <iostream>

#include "propertis.h"




void BinTranslator::numToBin(int dec_num) {
	bool negativ = false;
	bin_num = 0;
	if (dec_num < 0) {
		negativ = true;
		dec_num = abs(dec_num);
	}
	if (dec_num <= MAX_NUMBER) {
		toBin(dec_num);
		toNBin();
		if (negativ) toBinNegativ();

	}
}


void BinTranslator::toNBin() {
	std::string local_str_bin;
	int bin_len;

	local_str_bin = std::to_string(bin_num);
	bin_len = local_str_bin.length();

	str_bin_num = std::string(BIT - bin_len, '0') + local_str_bin;
}


void BinTranslator::toBin(int dec_num) {
	for (int i = BIT - 1; i >= 0; i--) {
		if ((dec_num >> i) & 1) {
			bin_num += (int)(1 * pow(10, i));
		}
	}
}


void BinTranslator::inversion() {
	for (int i = 0; i < BIT; i++) {
		if (str_bin_num.at(i) == '0')
			str_bin_num.replace(i, 1, "1");
		else
			str_bin_num.replace(i, 1, "0");
	}
}

void BinTranslator::add_one() {
	for (int i = BIT - 1; i >= 0; i--) {
		if (str_bin_num.at(i) == '0') {
			str_bin_num.replace(i, 1, "1");
			break;
		}
		else{
			str_bin_num.replace(i, 1, "0");
		}
	}
}


void BinTranslator::toBinNegativ() {
	inversion();
	add_one();
}
