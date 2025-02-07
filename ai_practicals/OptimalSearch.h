#include "Search.h"

#pragma once
class OptimalSearch : public Search
{
private:
	std::stack<Flight> solution;
public:

	bool isFlight(const std::string& from, const std::string& to) override;

	void search(const std::string& from, const std::string& to);
	void spush(const std::string& from, const std::string& to, double dist);
	void distanceCompatison(double& dist, double& old_dist);
	void resetBtStack();
	void resetSolutionStack();
	void printSolution();
};

