#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

//  protected:
// 	HeroType type;
// 	string name;
// 	double health;
// 	double attackStrength;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance):Character(WARRIOR, name, health, attackStrength){
    this->allegiance = allegiance;
}

string Warrior::getAlleg(){
    return allegiance;
}

void Warrior::attack(Character &opponent){
    double damage = 0;
    damage = (health / MAX_HEALTH)*attackStrength;
    if (opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (allegiance == opp.getAlleg()){
			cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
			cout << "They share an allegiance with " << allegiance << "." << endl;
        }

        else{
			cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
			opponent.damage(damage);
			cout << opponent.getName() << " takes " << damage << " damage." << endl;
		}
    }
    else{
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
		opponent.damage(damage);
		cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }

}
