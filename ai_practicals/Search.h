#include <stack>
#include <vector>
#include <iostream>
#include "Flight.h"
#pragma once
class Search
{

protected:
	std::stack<Flight> bt;
	std::vector<Flight> flights;


public:
	virtual ~Search() = default;
	void addFlight(const std::string& from, const std::string& to, double distance);

	double match(const std::string& from, const std::string& anywhere);
	virtual double find(const std::string& from, std::string& anywhere);
	virtual bool isFlight(const std::string& from, const std::string& to) = 0;

	double printRoute();
};

