#include "Attribute.h"
#include <iostream>
#include <vector>

class Generalizer
{

private:
	std::vector<Attribute> must_have;
	std::vector<Attribute> may_have;
	void deactivateMayHave(const std::string& subject, const std::string& verb, const std::string& object);

public:
	Generalizer();
	~Generalizer();

	void addMayHave(const Attribute& attr);

	void addMustHave(const Attribute& attr);

	void generalize(const std::string& subject, const std::string& verb, const std::string& object);
	void restrict(const std::string& ms, const std::string& mv, const std::string& mo);
 
    void display(std::ofstream& prtcl) const;
	void learn(std::ofstream& prtcl);
	bool getExample(std::string& subject, std::string& verb, std::string& object, std::ofstream& prtcl);

	int find_may(const std::string& subject, const std::string& verb, const std::string& object) const;

};

