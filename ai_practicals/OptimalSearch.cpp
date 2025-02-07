#include "OptimalSearch.h"

bool OptimalSearch::isFlight(const std::string& from, const std::string& to)
{
	std::string anywhere;
	double d = match(from, to);
	if (d) {
		bt.push(Flight(from, to, d, false));
		return true;
	}

	double dist = find(from, anywhere);
	if (dist) {
		bt.push(Flight(from, anywhere, dist, false));
		return isFlight(anywhere, to);
	}
	else {
		if (!bt.empty()) {
			std::string prev_from = bt.top().getFrom();
			bt.pop();
			return isFlight(prev_from, to);
		}
		return false;
	}
}

void OptimalSearch::search(const std::string& from, const std::string& to)
{
	double old_dist = 32000;
	double dist;
	std::string from_delete, to_delete;
	do {
		isFlight(from, to);
		distanceCompatison(dist,old_dist);
		resetBtStack();
	} while (dist!=0);

	printSolution();
}

void OptimalSearch::spush(const std::string& from, const std::string& to, double dist)
{
}

void OptimalSearch::distanceCompatison(double& dist, double& old_dist)
{
	dist = printRoute();
	if (dist < old_dist && dist) {
		old_dist = dist;
		resetSolutionStack();
		while (!bt.empty()) {
			solution.push(bt.top());
			bt.pop();
		}
	}

}


void OptimalSearch::resetBtStack()
{
	while (!bt.empty()) {
		bt.pop();
	}
}
void OptimalSearch::resetSolutionStack()
{
	while (!solution.empty()) {
		solution.pop();
	}
}

void OptimalSearch::printSolution()
{

	if (solution.empty()) {
		std::cout << "\nNo solution were found." << std::endl;
		return;
	}
	
	std::stack<Flight> reverseBt;
	while (!solution.empty()) {
		reverseBt.push(solution.top());
		solution.pop();
	}

	std::cout << "\nSolution found:\n";
	double overall_distance = 0;
	while (!reverseBt.empty()) {
		Flight flight = reverseBt.top();
		overall_distance += flight.getDistance();
		reverseBt.pop();
		std::cout << flight.getFrom() << " -> " << flight.getTo() << std::endl;
	}

	std::cout << "\nOverall distance: " << overall_distance << std::endl;
	
}
