
#include <string>
#include <vector>
#pragma once
class Letter
{

public:
	std::string letterName;
	std::vector<int> letterCode;
	Letter(std::string letter, std::vector<int> code)
		: letterName(letter), letterCode(code) {}
	
};

