
#include "Cowboy.hpp"

using namespace std;

namespace ariel{

    Cowboy::Cowboy(string name, Point& Location): Character::Character(name, Location){
        this->hit_Points = 110;
        this->boolets = 6;
    }

    bool Cowboy::hasboolets(){
        return this->boolets > 0;
    }

    void Cowboy::shoot(Character* enemy){
        if(this->isAlive()&& this->hasboolets()){
            enemy->hit(10);
        }
    }
    void Cowboy::reload(){
        this->boolets = 6;
    }
    void Cowboy::print(){
        if (this->isAlive())
    {
        cout <<"C "<<this->getName()<<endl;
        cout <<"Life points: "<<this->hit_Points<<endl;

    }
    else
    {
        cout <<"("<<this->getName()<<")"<<endl;
    }
    this->location.print();
    cout<<endl;
    }






}