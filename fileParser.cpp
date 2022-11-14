#include "fileParser.h"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void FileParser::getCommands(std::string path){

	std::string comm_cod, operands;
	std::ifstream inFile;
	
	inFile.open(path);
	if (!inFile) {
		std::cout << "Unable to open file " << path << "!" << "\n";
		cmd_list.push_back(std::make_pair("NONE", "0"));
	}
	else {
		std::cout << "Executing from '" << path << "'..." << "\n";
		while (inFile >> comm_cod >> operands)
		{
			cmd_list.push_back(std::make_pair(comm_cod, operands));
			std::cout << "Added: '" << comm_cod + " " + operands << "'\n";
		}
		std::cout << "Executing completed!" << "\n";
	}
	inFile.close();
}
