#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

using namespace std;

//  protected:
// 	HeroType type;
// 	string name;
// 	double health;
// 	double attackStrength;

class Warrior : public Character{
    private:
        string allegiance;
    
    public:
        Warrior(const string &name, double health, double attackStrength, string allegiance);
	    string getAlleg();
        void attack(Character &);
};
#endif
