#pragma once
#include "Ninja.hpp"

namespace ariel{

class OldNinja : public Ninja
{
private:
    
public:
    OldNinja(string name, Point& Location): Ninja::Ninja(name, Location){
        this->hit_Points = 150;
        this->speed = 8;
    } 
    
};


}