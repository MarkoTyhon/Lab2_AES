#include <iostream>
#include <vector>
#include <string>

#include "fileParser.h"
#include "binTranslator.h"
#include "hexTranslator.h"
#include "memory.h"
#include "processor.h"


int main() {
	FileParser parser;
	parser.getCommands("commands.txt");

	Processor CPU;
	CPU.mainProc(parser.cmd_list);
}


