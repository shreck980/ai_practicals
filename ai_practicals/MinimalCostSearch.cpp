#include "MinimalCostSearch.h"

double MinimalCostSearch::find(const std::string& from, std::string& anywhere)
{
	double dist = 32000;
	int pos = 0;

	for (int i = 0; i < flights.size(); i++) {
		if (flights[i].getFrom() == from && !flights[i].isSkip()) {
			if (flights[i].getDistance() < dist) {
				pos = i;
				dist = flights[i].getDistance();
			}


		}
	}

	if (pos) {
		anywhere = flights[pos].getTo();
		flights[pos].setSkip( true);
		return flights[pos].getDistance();
	}
	return 0;
}

bool MinimalCostSearch::isFlight(const std::string& from, const std::string& to)
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
