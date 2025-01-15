#include <string>

#pragma once
class Attribute
{
private:
   
public:

    std::string subject,
        verb,
        object;
    bool active;
    Attribute();
    Attribute(std::string subject, std::string verb, std::string object, bool active);
    ~Attribute();


};

