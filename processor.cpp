#include "processor.h"

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <stdlib.h>

#include "propertis.h"
#include "binTranslator.h"


void Processor::mainProc(std::vector<std::pair <std::string, std::string>> cmd_list) {
	int tact = 0;
	for (std::pair <std::string, std::string> command : cmd_list) {
		clean_array();
		getCommand(command);
		tact = 0;
		while (tact < 2) {
			tact += 1;
			if (tact % 2)
				tact1();
			else
				tact2();
		}
	}
}

void Processor::opXOR() {
	std::string el1 = getValue(1);

	std::string el2 = getValue(2);

	std::string res = "";

	for (int i = 0; i < BIT; i++) {
		if (el1.at(i) == el2.at(i))
			res += "0";
		else
			res += "1";
	}
	addRes(res);

}

void Processor::opLOAD() {
	std::string val = getValue(2);

	if (curr_command[1].find("[") == std::string::npos)
		mem.addToMem(val);
	else
		mem.addToMem(std::stoi(curr_command[1].substr(curr_command[1].length() - 2, 1).c_str()), val);

}

std::string Processor::getValue(int indx) {
	if (curr_command[indx].find("stack") != std::string::npos) {
		if (curr_command[indx].find("[") == std::string::npos){
			return stack1.top();
		}
		else {
			return gtNVlFrStck(std::stoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()));
		}
	}
	else if (curr_command[indx].find("mem") != std::string::npos) {
		return mem.getFromMem(std::stoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()));
	}
	else {
		int int_value = std::stoi(curr_command[indx].c_str());
		bin.numToBin(int_value);
		return bin.str_bin_num;
	}
}

void Processor::opMOV() {
	int int_value = std::stoi(curr_command[2].c_str());
	bin.numToBin(int_value);
	stack1.push(bin.str_bin_num);

}

void Processor::getCommand(std::pair <std::string, std::string> command) {
	std::size_t index;
	std::pair<std::string, std::string> operands;
	curr_command[0] = command.first;
	if ((index = command.second.find(",")) != std::string::npos)
		operands = split(command.second, 1, index);
	
	if (index != std::string::npos) {
		curr_command[1] = operands.first;
		curr_command[2] = operands.second;
	}
}

std::pair<std::string, std::string> Processor::split(std::string str, int dlmtr_ln, size_t index) {
	std::pair<std::string, std::string> res;
		res.first = str.substr(0, (int)index);
		res.second = str.substr(index+dlmtr_ln, size(str)- (int)index + dlmtr_ln);
	return res;
}


void Processor::clean_array() {
	for (int i = 0; i < 3; i++) {
		curr_command[i] = "";
	}
}

void Processor::tact1() {
	TC = 1;
	IR = curr_command[0] + " " + curr_command[1]+ "," + curr_command[2];
	++PC;

	if (curr_command[2].find("-") == std::string::npos)
		PS = 0;
	else
		PS = 1;
	
	showProces();
}

void Processor::tact2() {
	TC = 2;
	doCommand();
	showProces();
}

void Processor::doCommand() {
	if (curr_command[0] == "mov") { //redone
		opMOV();
	}
	else if (curr_command[0] == "load") {
		opLOAD();
	}
	else if (curr_command[0] == "xor") {
		opXOR();
	}
}
	

std::string Processor::gtNVlFrStck(int indx) {
	std::stack<std::string> loc_stack;
	loc_stack = stack1;
	std::cout << loc_stack.size();
	while (loc_stack.size() != indx + 1) {
		loc_stack.pop();
	}
	return loc_stack.top();
}

void Processor::gtAllVlFrStck() {
	std::stack<std::string> loc_stack;
	loc_stack = stack1;
	std::string buf;
	int ccount = -1;
	while(!loc_stack.empty()) {
		buf = loc_stack.top();
		for (int i = 0; i < BIT / 8; i++) {
			std::cout << buf.substr(i * 8, 8);
			if (i != BIT/8-1) std::cout << ".";
		}
		std::cout << "\t";
		loc_stack.pop();
		if (ccount % 3 == 1) std::cout << "\n";
		++ccount;
	}
	std::cout << "\n\n";
}

void Processor::stackReplace(int indx, std::string val) {
	std::stack<std::string> loc_stack;
	while (stack1.size() < indx) {
		loc_stack.push(stack1.top());
		stack1.pop();
	}
	stack1.pop();

	stack1.push(val);
	for (int i = 0; i < loc_stack.size(); i++) {
		stack1.push(loc_stack.top());
		loc_stack.pop();
	}
	
}

void Processor::stackReplace(std::string val) {
	stack1.pop();
	stack1.push(val);
}

void Processor::addRes(std::string res) {
	int indx = 1;
	if (curr_command[indx].find("stack") != std::string::npos) {

		if (curr_command[indx].find("[") == std::string::npos) {
			stackReplace(res);
		}
		else {
			stackReplace(std::stoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()), res);
		}
	}
	else if (curr_command[indx].find("mem") != std::string::npos) {
		mem.addToMem(std::stoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()),res);
	}
}

void Processor::showProces() {
	std::cout << "\n" + std::string(115, '-') + "\n\n";

	std::cout << "IR: " << IR << "\n\n";

	std::cout << "Stack1:\n"; 
	gtAllVlFrStck();

	std::cout << "RAM:\n";
	mem.showMem();

	std::cout << "PS: " << PS << "\n";

	std::cout << "PC: " << PC << "\n";

	std::cout << "TC: " << TC << "\n";

}