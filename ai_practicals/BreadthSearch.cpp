#include "BreadthSearch.h"

bool BreadthSearch::isFlight(const std::string& from, const std::string& to)
{
	std::string anywhere;

	double d, dist = 0;
	while (dist = find(from, anywhere)) {
		d = match(anywhere, to);
		if (d) {
			bt.push(Flight(from, anywhere, dist, false));
			bt.push(Flight(anywhere, to, d, false));
			return true;
		}
	}

	dist = find(from, anywhere);
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
