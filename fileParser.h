#pragma once

#include <fstream>
#include <vector>
#include <string>

struct FileParser
{
	void getCommands(std::string path);
	std::vector <std::pair <std::string, std::string>> cmd_list;
};