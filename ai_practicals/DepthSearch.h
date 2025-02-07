#include <stack>
#include <vector>
#include <iostream>
#include "Flight.h"
#include "Search.h"
#pragma once
class DepthSearch : public Search
{
public:
	bool isFlight(const std::string& from, const std::string& to) override;

};

