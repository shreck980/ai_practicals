#include "DepthSearch.h"

void DepthSearch::addFlight(const std::string& from, const std::string& to, double distance)
{
	flights.emplace_back(from,to,distance,false);
}

double DepthSearch::match(const std::string& from, const std::string& anywhere)
{
	for (auto& flight : flights) {
		if (flight.from == from && flight.to == anywhere) {
			return flight.distance;
		}
	}
	return 0;
}

double DepthSearch::find(const std::string& from, std::string& anywhere)
{
	for (auto& flight : flights) {
		if (flight.from == from && !flight.skip) {
			anywhere = flight.to;
			flight.skip = true;
			return flight.distance;
		}
	}
	return 0;
}

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
			std::string prev_from = bt.top().from;
			bt.pop();
			return isFlight(prev_from, to);
		}
		return false;
	}

   
}

void DepthSearch::printRoute()
{
	
	if (bt.empty()) {
		std::cout << "No route found." << std::endl;
		return;
	}

	std::stack<Flight> reverseBt;
	while (!bt.empty()) {
		reverseBt.push(bt.top());
		bt.pop();
	}

	std::cout << "Route found:\n";
	while (!reverseBt.empty()) {
		Flight flight = reverseBt.top();
		reverseBt.pop();
		std::cout << flight.from << " -> " << flight.to<<std::endl;
	}
	
}


