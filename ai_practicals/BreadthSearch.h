#include "Search.h"
#pragma once
class BreadthSearch : public Search
{
public:
	
	bool isFlight(const std::string& from, const std::string& to) override;
};

