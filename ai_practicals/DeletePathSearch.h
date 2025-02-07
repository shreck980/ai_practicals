#include "Search.h"

#pragma once
class DeletePathSearch : public Search
{
public:
	bool isFlight(const std::string& from, const std::string& to) override;
	
	void search(const std::string& from, const std::string& to);
};

