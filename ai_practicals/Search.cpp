#include "Search.h"


void Search::addFlight(const std::string& from, const std::string& to, double distance)
{
	flights.emplace_back(from, to, distance, false);
}

double Search::match(const std::string& from, const std::string& anywhere)
{
	for (auto& flight : flights) {
		if (flight.getFrom() == from && flight.getTo() == anywhere) {
			return flight.getDistance();
		}
	}
	return 0;
}

double Search::find(const std::string& from, std::string& anywhere)
{
	for (auto& flight : flights) {
		if (flight.getFrom() == from && !flight.isSkip()) {
			anywhere = flight.getTo();
			flight.setSkip(true);
			return flight.getDistance();
		}
	}
	return 0;
}


double Search::printRoute()
{

	if (bt.empty()) {
		std::cout << "\nNo other route found." << std::endl;
		return 0.0;
	}
	std::stack<Flight> tempBt = bt;
	std::stack<Flight> reverseBt;
	while (!tempBt.empty()) {
		reverseBt.push(tempBt.top());
		tempBt.pop();
	}

	std::cout << "\nRoute found:\n";
	double overall_distance = 0;
	while (!reverseBt.empty()) {
		Flight flight = reverseBt.top();
		overall_distance += flight.getDistance();
		reverseBt.pop();
		std::cout << flight.getFrom() << " -> " << flight.getTo() << std::endl;
	}

	std::cout << "\nOverall distance: " << overall_distance << std::endl;
	return overall_distance;
}