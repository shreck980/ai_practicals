#include "Attribute.h"

Attribute::Attribute()
{
}

Attribute::Attribute(std::string subject, std::string verb, std::string object,bool active)
{
	this->active = active;
	this->subject = subject;
	this->object = object;
	this->verb = verb;
}

Attribute::~Attribute()
{
}
