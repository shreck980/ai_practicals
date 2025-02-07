#include "Search.h"

#pragma once
class DeleteNodeSearch : public Search
{
public:
	bool isFlight(const std::string& from, const std::string& to) override;
	void search(const std::string& from, const std::string& to);
	void clearMarkers();
	void retract(const std::string& from, const std::string& to);
	void resetStack();
};



