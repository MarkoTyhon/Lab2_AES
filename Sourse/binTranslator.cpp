# include "binTranslator.h"

#include <string>
#include <vector>
#include <iostream>
#include <bitset>

#include "propertis.h"




void BinTranslator::numToBin(float dec_num) {
	str_bin_num = std::bitset<BIT>(dec_num).to_string();
}
