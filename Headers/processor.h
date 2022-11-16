#pragma once

#include <string>
#include <vector>
#include <stack>

#ifdef _WIN32
#include <conio.h>
#endif
#ifdef linux
#include <curses.h>
#endif


#include "memory.h"
#include "fileParser.h"
#include "binTranslator.h"


struct Processor{
	void tact1();
	void tact2();

	void mainProc(std::vector<std::pair <std::string, std::string>> cmd_list);

	void opXOR();
	void opMOV();
	void opLOAD();

	void getCommand(std::pair <std::string, std::string> command);
	void showProces();
	void doCommand();
	void clean_array();
	void gtAllVlFrStck();
	void stackReplace(int indx, std::string val);
	void stackReplace(std::string val);
	void addRes(std::string res);
	int pressAnyKey();
	std::string gtNVlFrStck(int indx);
	std::pair<std::string, std::string> split(std::string str, int dlmtr_ln, std::size_t index);
	std::string getValue(int indx);
	
	std::stack<std::string> stack1;
	std::string curr_command[3];
	std::string empty_arr[3] = {"", "", ""};
	Memory mem;
	FileParser parser;
	BinTranslator bin;

	int TC = 0;
	int PS = 0;
	int PC = 0;
	std::string IR;

	

	
};