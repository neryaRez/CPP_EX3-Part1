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
#include "sources/OldNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"
using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));

    Point c = Point::moveTowards(a,b,0);

    cout <<((a.getX() == c.getX()) && (a.getY() == c.getY()))<<endl;
    cout <<"a.x ==" <<c.getX()<<", a.y== "<<c.getY()<<" "<<endl;

    a.print();
    b.print();

   // Ninja s("Yogi", a);
   // s.print();

   Point p1(0,0), p2(2,0);

   YoungNinja Yogi("Yogi", p1);
   Yogi.print();

   OldNinja Sensei_Wu("Sensei Wu",p2);

   Yogi.move(&Sensei_Wu);

   cout <<Yogi.print();
   cout<<endl;

   Point p3(0,0), p4(10,10);

   YoungNinja Yoshi("Yoshi", p3);
   OldNinja Madara("Madara", p4);
   cout <<Yoshi.print();
   cout <<endl;

   
   Yoshi.move(&Madara);

   cout <<Yoshi.print();

   Yoshi.slash(&Madara);

   Madara.print();

   Point p_1(0,0), p_2(0,3), p_3(2, 0), p_4(-2, 0), p5(0,-1);

   Character* Naruto = new YoungNinja("Naruto", p_1);
   Character* Sasuke = new TrainedNinja("Sasuke", p_2);
   Character* Obito = new OldNinja("Obito", p_3);
   Character* Bil = new Cowboy("Bil", p_4);
   Character* raimond = new Cowboy("Raimond", p5);

   Team tim(Naruto);
   cout <<"1\n";
   tim.add(Sasuke);
   tim.add(Obito);
   tim.add(Bil);
   tim.add(raimond);

   tim.print();

   cout <<"the closeest member is:\n";
   size_t close = tim.closest_toLeader(tim.get_Team());
   cout <<"close == "<<close<<endl;
   cout <<tim.get_Team()[close]->print();
   cout <<"\n";

   cout <<"the leader is: \n";
   cout <<tim.get_Leader()->print()<<endl;

   cout <<tim.get_Leader()->isLeader()<<endl;
   cout<<tim.get_Team()[2]->isLeader()<<endl; 

   


    cout <<"now silence\n";

   //  tim.call_print2();






  //  // Character ch("moshe", a);
  //  // cout <<"this is the location of ch: \n";
  //  // ch.getLocation().print();

  //  // ch.print();

    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 


    Point point(64,57);
    Character* Y1 = new YoungNinja("Yogi", Point(64,57));
    team_A.add(Y1);


     team_A.add(new YoungNinja("Yogi", Point(64,57)));

  //   // Team b(tom); should throw tom is already in team a

  //    Team team_B(sushi);
  //    team_B.add(new TrainedNinja("Hikari", Point(12,81)));


  //    while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
  //       team_A.attack(&team_B);
  //       team_B.attack(&team_A);
  //       team_A.print();
  //       team_B.print();
  //    }

  //    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
  //    else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
