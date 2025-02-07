#include "DepthSearch.h"



bool DepthSearch::isFlight(const std::string& from, const std::string& to)
{

    std::string anywhere;
    double d = match(from, to);
    if (d) {
        bt.push(Flight(from,to,d,false));
		return true;
    }

	double dist = find(from, anywhere);
	if (dist) {
		bt.push(Flight(from, anywhere, dist,false));
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




