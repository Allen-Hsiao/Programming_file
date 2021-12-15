#include <iostream>
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank):Character(WIZARD, name, health, attackStrength){
    this->rank = rank;
}

int Wizard::getrank(){
    return rank;
}

void Wizard::attack(Character &opponent){
    double damage = 0;
    if (opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = (rank*1.0/opp.getrank())*attackStrength;
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
		cout << opponent.getName() << " takes " << damage << " damage." << endl;
		opponent.damage(damage);

    }

    else{
        damage = attackStrength;
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
		cout << opponent.getName() << " takes " << damage << " damage." << endl;
		opponent.damage(damage);
    }

}