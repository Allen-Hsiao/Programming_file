#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

using namespace std;

//  protected:
// 	HeroType type;
// 	string name;
// 	double health;
// 	double attackStrength;

class Wizard : public Character{
    private:
        int rank;
    
    public:
        Wizard(const string &name, double health, double attackStrength, int rank);
	    int getrank();
        void attack(Character &);
};
#endif