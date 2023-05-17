#include "Character.hpp"

// using namespace ariel;
using namespace std;

namespace ariel{

Character::Character(string Name, Point& Location): name(Name), location(Location) {}

 Point& Character::getLocation(){
    return this->location;
 }

 string Character::getName(){
    return this->name;
 }

 bool Character::isAlive(){
    return this->hit_Points > 0;
 }

 double Character::distance(Character* other){
    return this->location.distance(other->location);
 }

 void Character::hit(int h){
    this->hit_Points -= h;
 }
 








}