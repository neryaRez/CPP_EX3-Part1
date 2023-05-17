#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

class Ninja : public Character
{
protected:
    int speed;
    Ninja(string name, Point& Location);

public:
    void move(Character* enemy);
    void slash(Character* enemy);
    void print() override;
    
};


}
