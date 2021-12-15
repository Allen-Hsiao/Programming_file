#ifndef ELF_H
#define ELF_H
#include <string>

#include "Character.h"

using namespace std;

//  protected:
// 	HeroType type;
// 	string name;
// 	double health;
// 	double attackStrength;
class Elf : public Character{
    private:
        string familyname;
    public:
        Elf(const string &name, double health, double attackStrength, string famName);
	    string getFamilyname();
	    void attack(Character &opponent);
};
#endif   