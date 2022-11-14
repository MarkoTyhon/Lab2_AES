#pragma once

#include <string>
#include <vector>
#include <stack>

#include "memory.h"
#include "fileParser.h"
#include "binTranslator.h"


struct Processor{
	void tact1();
	void tact2();

	void mainProc(std::pair <std::string, std::string> command);

	void opXOR();
	void opMOV();
	void opLOAD();

	void getCommand(std::pair <std::string, std::string> command);
	void showProces();
	void doCommand();
	void clean_array();
	void addToStack(int st_i, std::string val);
	void gtAllVlFrStck(int st_i);
	void stackReplace(int st_i, int indx, std::string val);
	void stackReplace(int st_i, std::string val);
	void addRes(std::string res);
	std::string gtNVlFrStck(int st_i, int indx);
	std::pair<std::string, std::string> split(std::string str, int dlmtr_ln, std::size_t index);
	std::string getValue(int indx);
	
	int cmd_counter = 0;
	std::stack<std::string*> stack1;
	std::stack<std::string*> stack2;
	std::string curr_command[3];
	std::string empty_arr[3] = {"", "", ""};
	Memory mem;
	FileParser parser;
	BinTranslator bin;

	int TC;
	int PS;
	std::string IR;

	

	
};