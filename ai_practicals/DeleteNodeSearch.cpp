#include "DeleteNodeSearch.h"

bool DeleteNodeSearch::isFlight(const std::string& from, const std::string& to)
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

void DeleteNodeSearch::search(const std::string& from, const std::string& to)
{
	double dist;
	std::string from_delete, to_delete;
	do {
		isFlight(from, to);
		dist = printRoute();
		if (!dist) break;
		clearMarkers();
		if (!bt.empty()) {
			from_delete = bt.top().getFrom();
			to_delete = bt.top().getTo();
			bt.pop();
			retract(from_delete, to_delete);
		}
		
		resetStack();
	} while (true);
}

void DeleteNodeSearch::clearMarkers()
{
	for (Flight& f : flights) {
		f.setSkip(false);
	}

}

void DeleteNodeSearch::retract(const std::string& from, const std::string& to)
{
	for (int i = 0; i < flights.size(); i++) {
		if (flights[i].getFrom() == from && flights[i].getTo() == to) {
			flights.erase(flights.begin() + i);
			return;
		}
	}
}

void DeleteNodeSearch::resetStack()
{
	while (!bt.empty()) {
		bt.pop();
	}
}
