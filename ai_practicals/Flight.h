
#include <string>
#pragma once
class Flight
{
private: 
	    std::string from;
	    std::string to;
	    double distance;
	   bool skip = false;
public:
	
	
	Flight(const std::string& from, const std::string& to, double distance, bool skip)
		: from(from), to(to), distance(distance), skip(skip)
	{
	}

	Flight(const Flight& other)
		: from(other.from), to(other.to), distance(other.distance), skip(other.skip) {}
	
	std::string getFrom() const { return from; }
	std::string getTo() const { return to; }
	double getDistance() const { return distance; }
	bool isSkip() const { return skip; }

	// Setters
	void setSkip(bool newSkip) { skip = newSkip; }

	Flight& operator=(const Flight& other) {
		if (this != &other) { 
			from = other.from;
			to = other.to;
			distance = other.distance;
			skip = other.skip;
		}
		return *this;
	}
};


