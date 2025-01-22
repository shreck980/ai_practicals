
#include <string>
#include <vector>
#pragma once
class Letter
{

public:
	const char letterName;
	std::vector<int> letterCode;
	Letter(char letter, std::vector<int> code)
		: letterName(letter), letterCode(code) {}
	
};

