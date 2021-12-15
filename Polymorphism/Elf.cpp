#include <iostream>
#include <string>
#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string familyname):Character(ELF, name, health, attackStrength){
    this->familyname = familyname;
}

string Elf::getFamilyname(){
    return familyname;
}
void Elf::attack(Character &opponent){
    double damage = 0;
    damage = (health / MAX_HEALTH)*attackStrength;
    if (opponent.getType() == ELF){
		Elf &opp = dynamic_cast<Elf &>(opponent);	
		if (familyname == opp.getFamilyname())
		{
			cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
			cout << "They are both members of the " << familyname << " family." << endl;
		}
		else
		{
			cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
			opponent.damage(damage);
			cout << opponent.getName() << " takes " << damage << " damage." << endl;
		}
	}
	else
	{
		cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
		opponent.damage(damage);
		cout << opponent.getName() << " takes " << damage << " damage." << endl;
	}
}