#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

//  protected:
// 	HeroType type;
// 	string name;
// 	double health;
// 	double attackStrength;

Character::Character(HeroType type, const string &name, double health, double attackStrength){
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const{
    return health;
}

/* Reduces health value by amount passed in. */
void Character::damage(double d){
    health -= d;
}

/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const{
    bool result = false;
    if (getHealth() > 0){
        result = true;
    }
    return result;
}