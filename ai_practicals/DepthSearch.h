#include <stack>
#include <vector>
#include <iostream>
#include "Flight.h"
#pragma once
class DepthSearch
{
private:
	std::stack<Flight> bt;
	std::vector<Flight> flights;


public:
	void addFlight(const std::string& from, const std::string& to, double distance);

	double match(const std::string& from, const std::string& anywhere);
	double find(const std::string& from, std::string& anywhere);
	bool isFlight(const std::string& from, const std::string& to);

	void printRoute();


};

