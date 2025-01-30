
#include <string>
#pragma once
class Flight
{

public:
	const std::string from;
	const std::string to;
	const double distance;
	bool skip = false;
	Flight(const std::string& from, const std::string& to, double distance, bool skip)
		: from(from), to(to), distance(distance), skip(skip)
	{
	}
};

