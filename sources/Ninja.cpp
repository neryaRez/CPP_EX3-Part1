
#include "Ninja.hpp"

using namespace std;

namespace ariel{

Ninja::Ninja(string name, Point& Location) :Character::Character(name, Location){}

void Ninja::slash(Character* enemy){
    if(this->isAlive() && this->distance(enemy) <= 1){
        enemy->hit(40);
    }
}

void Ninja::move(Character* enemy){

    if(! this->isAlive()) return;

    if(this->distance(enemy) <= this->speed){
       this->location = Point::moveTowards(this->location, enemy->getLocation(), this->distance(enemy));
    }

    else
    {
        this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
    }
    
}
 void Ninja::print() {
    if (this->isAlive())
    {
        cout <<this->getName()<<endl;
        cout <<"Life points: "<<this->hit_Points<<endl;

    }
    else
    {
        cout <<"("<<this->getName()<<")"<<endl;
    }
    this->location.print();
 }










}

