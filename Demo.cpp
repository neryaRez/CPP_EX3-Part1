/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Ninja.hpp"
using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));

    Point c = Point::moveTowards(a,b,0);

    cout <<((a.getX() == c.getX()) && (a.getY() == c.getY()))<<endl;
    cout <<"a.x ==" <<c.getX()<<", a.y== "<<c.getY()<<" "<<endl;

    a.print();
    b.print();

   Ninja s("Yogi", a);
   s.print();

   // Character ch("moshe", a);
   // cout <<"this is the location of ch: \n";
   // ch.getLocation().print();

   // ch.print();

   //  Cowboy *tom = new Cowboy("Tom", a);
   //  OldNinja *sushi = new OldNinja("sushi", b);
   //  tom->shoot(sushi);
   //  cout << tom->print() <<endl;

   //  sushi->move(tom);
   //  sushi->slash(tom);

   //  Team team_A(tom); 
   //  team_A.add(new YoungNinja("Yogi", Point(64,57)));

   //  // Team b(tom); should throw tom is already in team a

   //   Team team_B(sushi);
   //   team_B.add(new TrainedNinja("Hikari", Point(12,81)));


   //   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
   //      team_A.attack(&team_B);
   //      team_B.attack(&team_A);
   //      team_A.print();
   //      team_B.print();
   //   }

   //   if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
   //   else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
