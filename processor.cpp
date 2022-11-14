#include "processor.h"

#include <string>
#include <vector>
#include <stack>
#include <iostream>

#include "propertis.h"
#include "binTranslator.h"


void Processor::mainProc(std::pair <std::string, std::string> command) {
	clean_array();
	int tact = 0;
	getCommand(command);
	while (true) {
		tact += 1;
		if (tact % 2)
			tact1();
		else 
			tact2();
	}
}

void Processor::opXOR() {
	int int_value = std::atoi(getValue(1).c_str());
	bin.numToBin(int_value);
	std::string el1 = bin.str_bin_num;

	int_value = std::atoi(getValue(2).c_str());
	bin.numToBin(int_value);
	std::string el2 = bin.str_bin_num;;

	std::string res = "";
	

	for (int i = 0; i < BIT; i++) {
		if (el1[i] == el2[i])
			res += "0";
		else
			res += "1";
	}

	addRes(res);

}

void Processor::opLOAD() {
	int int_value = std::atoi(getValue(2).c_str());
	bin.numToBin(int_value);
	if (curr_command[1].find("[") == std::string::npos)
		mem.addToMem(bin.str_bin_num);
	else
		mem.addToMem(std::atoi(curr_command[1].substr(curr_command[1].length() - 2, 1).c_str()), bin.str_bin_num);

}

std::string Processor::getValue(int indx) {
	if (curr_command[indx].find("stack") != std::string::npos) {
		if (curr_command[indx].find("[") == std::string::npos){
			if (curr_command[2].find("1") == std::string::npos)
				return *stack2.top();
			else
				return *stack1.top();
		}
		else {
			if (curr_command[2].find("1") == std::string::npos)
				return gtNVlFrStck(2, std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()));
			else
				return gtNVlFrStck(1, std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()));
		}
	}
	else if (curr_command[2].find("mem") != std::string::npos) {
		return mem.getFromMem(std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()));
	}
	else {
		int int_value = std::atoi(curr_command[indx].c_str());
		bin.numToBin(int_value);
		return bin.str_bin_num;
	}
}

void Processor::opMOV() {
	int int_value = std::atoi(curr_command[2].c_str());
	bin.numToBin(int_value);
	if (curr_command[1].find("1") == std::string::npos)
		addToStack(2, bin.str_bin_num);
	else
		addToStack(1, bin.str_bin_num);
}

void Processor::getCommand(std::pair <std::string, std::string> command) {
	std::size_t index;
	std::pair<std::string, std::string> operands;
	curr_command[0] = command.first;
	if ((index = command.second.find("],")) != std::string::npos)
		operands = split(command.second, 2, index);
	else if ((index = command.second.find(",")) != std::string::npos)
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
	IR = curr_command[0] + curr_command[1] + curr_command[2];
	++cmd_counter;

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

void Processor::addToStack(int st_i, std::string val) {
	if (st_i == 1) 
		stack1.push(mem.addToMem(val));
	
	if (st_i == 2) 
		stack2.push(mem.addToMem(val));
	
}

std::string Processor::gtNVlFrStck(int st_i, int indx) {
	std::stack<std::string*> loc_stack;
	if (st_i == 1)
		 loc_stack = stack1;
	else
		 loc_stack = stack2;

	for (int i = 0; i < stack1.size() - st_i + 1; i++) {
		loc_stack.pop();
	}
	return *loc_stack.top();
}

void Processor::gtAllVlFrStck(int st_i) {
	std::stack<std::string*> loc_stack;
	if (st_i == 1)
		loc_stack = stack1;
	else
		loc_stack = stack2;

	for (int i = 0; i < stack1.size()-1; i++) {//////
		std::cout << *loc_stack.top() << " ";
		loc_stack.pop();
	}
}

void Processor::stackReplace(int st_i, int indx, std::string val) {
	std::stack<std::string*> loc_stack;
	if (st_i == 1)
		loc_stack = stack1;
	else
		loc_stack = stack2;

	for (int i = 0; i < stack1.size() - st_i + 1; i++) {
		loc_stack.pop();
	}
	std::string* pointer = loc_stack.top();
	*pointer = val;
}

void Processor::stackReplace(int st_i, std::string val) {
	std::stack<std::string*> loc_stack;
	if (st_i == 1)
		loc_stack = stack1;
	else
		loc_stack = stack2;
	std::string* pointer = loc_stack.top();
	*pointer = val;
}

void Processor::addRes(std::string res) {
	int indx = 1;
	if (curr_command[indx].find("stack") != std::string::npos) {

		if (curr_command[indx].find("[") == std::string::npos) {
			if (curr_command[2].find("1") == std::string::npos)
				stackReplace(2, res);
			else
				stackReplace(1, res);
		}
		else {
			if (curr_command[2].find("1") == std::string::npos)
				stackReplace(2, std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()), res);
			else
				stackReplace(1, std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()), res);
		}
	}
	else if (curr_command[2].find("mem") != std::string::npos) {
		mem.addToMem(std::atoi(curr_command[indx].substr(curr_command[indx].length() - 2, 1).c_str()), res);
	}
}

void Processor::showProces() {

}
