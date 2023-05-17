
#include "Team.hpp"

namespace ariel{

    Team::Team(Character* lead){
        if(this->has_leader){
            throw runtime_error("the group already has a leader\n ");
        }
          this->add(lead);
          this->leader = lead;  
          
          has_leader = true; 
          this->leader->make_leader(); 
        
    }

    void Team::setLeader(){
        if (! this->leader->isAlive()){
            this->leader = this->my_team[this->closest_toLeader(this->my_team)];
            this->leader->make_leader();
        }
        
    }

    void Team::attack(Team* enemies){

    }

    size_t Team::closest_toLeader(vector<Character*> team){
        double min_dist = 0, temp_min;
            size_t min_index = 0;
            for (size_t i = 0; i < team.size(); i++)
            {
                temp_min = this->leader->distance(team[i]);
                if (temp_min < min_dist){
                   min_dist = temp_min;
                   min_index = i; 
                } 
            }
        return min_index;
    }

    int Team::stillAlive(){

        int lives = 0;
        for (size_t i = 0; i < this->my_team.size(); i++)
        {
            if(this->my_team[i]->isAlive()) lives++;
        }
        return lives;
        
    }

    void Team::add(Character* member){
        if(member->is_Partof()){
            throw runtime_error("this member is alrady part of a Group\n");
        }
            this->my_team.push_back(member);
            member->setPart_of();   
    }

    void Team::print(){

        cout <<"The Group Members are:\n";

        for (size_t i = 0; i < this->my_team.size(); i++)
        {
            cout << this->my_team[i]->print();
        }
        
    }

    Team::~Team(){

        
        for (size_t i = 0; i < this->my_team.size(); i++)
        {
            delete (this->my_team[i]);
        }
        
    }






}