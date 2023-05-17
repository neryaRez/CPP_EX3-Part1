#pragma once
#include "Point.hpp"

using namespace std;

namespace ariel{

class Character
{
private:
    string name;

protected:
    Point& location;
    int hit_Points;

public:
    Character(string Name, Point& Location);
    Point& getLocation();
    string getName();

    bool isAlive();
    double distance(Character* other);
    void hit(int h);

    virtual void print() = 0;
   
};



}