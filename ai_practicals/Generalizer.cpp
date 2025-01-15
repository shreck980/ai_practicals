#include "Generalizer.h"
#include <fstream>


Generalizer::Generalizer()
{
}

Generalizer::~Generalizer()
{
}

void Generalizer::deactivateMayHave(const std::string& subject, const std::string& verb, const std::string& object)
{
    for (auto& attr : may_have) {
        if (attr.subject == subject && attr.verb == verb && attr.object == object) {
            attr.active = false;
        }
    }
}


void Generalizer::addMayHave(const Attribute& attr)
{
	may_have.push_back(attr);
}

void Generalizer::addMustHave(const Attribute& attr)
{
	must_have.push_back(attr);
}

void Generalizer::generalize(const std::string& subject, const std::string& verb, const std::string& object)
{
    for (auto& attr : may_have) {
        if (attr.subject != subject && attr.verb == verb && attr.object == object && attr.active) {
            attr.subject += " or " + subject;
        }
    }

    for (auto& attr : may_have) {
        if (attr.subject == subject && attr.verb == verb && attr.object != object && attr.active) {
            attr.object += " or " + object;
        }
    }

    for (auto& attr : must_have) {
        if (attr.subject != subject && attr.verb == verb && attr.object == object) {
            attr.subject += " or " + subject;
            deactivateMayHave(subject, verb, object);
        }
    }

    for (auto& attr : must_have) {
        if (attr.subject == subject && attr.verb == verb && attr.object != object) {
            attr.object += " or " + object;
            deactivateMayHave(subject, verb, object);
        }
    }
}


void Generalizer::restrict(const std::string& ms, const std::string& mv, const std::string& mo){
    // Перевірити, чи починається verb із "not"
    if (mv.size() < 4 || mv.substr(0, 3) != "not") return;

    std::string verbWithoutNot = mv.substr(4);

    for (auto& attr : may_have) {
        if (attr.active &&
            attr.subject == ms &&
            attr.verb == verbWithoutNot &&
            attr.object == mo) {

            // Переміщення елемента в must_have
            addMustHave(attr);
            attr.active = false; // Деактивація елемента в may_have
            break;
        }
    }
}


void Generalizer::display(std::ofstream& prtcl) const {
    std::cout << "\nMay Have:\n";
    prtcl << "\nMay Have:\n";
    for (const auto& attr : may_have) {
        if (attr.active) {
            std::cout << attr.subject << " " << attr.verb << " " << attr.object << "\n";
            prtcl << attr.subject << " " << attr.verb << " " << attr.object << "\n";
        }
    }
    std::cout << "\nMust Have:\n";
    prtcl << "\nMust Have:\n";
    for (const auto& attr : must_have) {
        std::cout << attr.subject << " " << attr.verb << " " << attr.object << "\n";
        prtcl << attr.subject << " " << attr.verb << " " << attr.object << "\n";
    }
}

void Generalizer::learn(std::ofstream& prtcl)
{

    std::string sub, verb, obj;
    std::string msub, mverb, mobj;

    while (true) {
       
        std::cout << "\nEnter an example.";
        prtcl << "\n\nEnter an example.";  
        if (!getExample(sub, verb, obj,prtcl)) return;

       
        if (find_may(sub, verb, obj) == -1) {
           
            addMayHave(Attribute(sub, verb, obj, true));  
            generalize(sub, verb, obj);
        }

        
        std::cout << "Enter a near-miss (NL to skip).";
        prtcl << "\n\nEnter a near-miss (NL to skip).";  
        getExample(msub, mverb, mobj,prtcl);
        restrict(msub, mverb, mobj);
    }
}

bool Generalizer::getExample(std::string& subject, std::string& verb, std::string& object, std::ofstream& prtcl)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nSubject: ";
    std::getline(std::cin, subject);  

    if (subject.empty()) {
        subject = "<NL>";  
    }
    

  
    if (subject[0] =='<') {
        return false;  
    }
    prtcl << "\nSubject: " << subject;
    std::cout << "    Verb: ";
    std::getline(std::cin, verb);  

    std::cout << "    Object: ";
    std::getline(std::cin, object);  

    prtcl << "\n    Verb: " << verb << "\n    Object: " << object;

    return true;
}


int Generalizer::find_may(const std::string& subject, const std::string& verb, const std::string& object) const {
    
    for (size_t t = 0; t < may_have.size(); ++t) {
        const auto& attr = may_have[t];
        if (attr.subject == subject && attr.verb == verb && attr.object == object && attr.active) {
            return static_cast<int>(t); 
        }
    }
    return -1;  
}
