
#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character* lead): Team::Team(lead){}

    void Team2::print(){

        cout <<"The Group Members are:\n";
        for (size_t i = 0; i < this->get_Team().size(); i++)
        {
            cout <<this->get_Team()[i]->print();
        }

    }

    size_t Team2::closest_toLeader( vector <Character*> team){



    }





}