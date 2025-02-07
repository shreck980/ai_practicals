#include "Search.h"

#pragma once
class HillClimbingSearch : public Search
{
public:
	double find(const std::string& from, std::string& anywhere) override;
	bool isFlight(const std::string& from, const std::string& to) override;
};

