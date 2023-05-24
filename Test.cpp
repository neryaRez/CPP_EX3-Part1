#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_SUITE("Point Class") {

    Point p1{1, 1};
    Point n1{-1, 1};
    Point n2{1, -9};
    Point n3{0,0};
    Point n4(3,4);

    TEST_CASE("Point Methods:") {

        CHECK_EQ(p1.getX(), 1);
        CHECK_EQ(n2.getY(), -9);

        CHECK_EQ(p1.distance(n3), n3.distance(p1));
        CHECK_EQ(n1.distance(n2), n2.distance(n1));
        CHECK_EQ(n4.distance(n3), 5);
        CHECK_EQ(p1.distance(n2), 10);
        CHECK_EQ(p1.distance(p1), 0);

        CHECK_EQ(p1.distance(n3), sqrt(2));

        // There is no such a thing as negative distance
        CHECK_THROWS_AS(Point::moveTowards(p1, n4, -1),std::invalid_argument);
        
        Point p0(sqrt(2),sqrt(2));
        Point p2 = Point::moveTowards(n3,n4,2);
        Point q = Point::moveTowards(n3,Point(8,8),sqrt(50));

        CHECK_EQ(q.getX(), doctest::Approx(5).epsilon(0.001));
        CHECK_EQ(q.getX(), q.getY());
        CHECK_EQ(p0.distance(n3), p2.distance(n3));
    }

}

    TEST_SUITE("Ninja Class:"){

            YoungNinja Yoshi("Yoshi", Point(0,0));
            YoungNinja Korasaki("Korasaki", Point(15,0));
            YoungNinja Sasuke("Sasuke", Point(-15,0));

            TrainedNinja Kishimoto("Kishi", Point(2,2));
            OldNinja Orokusaki("Orokusaki", Point(15,2));
            OldNinja Ichigo("Ichigo", Point(24,2));

        TEST_CASE("Getters Functions"){

            CHECK(Yoshi.isAlive());
            CHECK_FALSE(Yoshi.isLeader());
            CHECK_FALSE(Sasuke.is_Partof());

            CHECK_EQ('N', Korasaki.getType());
            CHECK_EQ("Korasaki", Korasaki.getName());
            CHECK_EQ(Orokusaki.getLocation(), Point(15,2));

            CHECK_EQ(150, Ichigo.get_lives());
            CHECK_EQ(120, Kishimoto.get_lives());
            CHECK_EQ(100, Sasuke.get_lives());

            CHECK_EQ(8,  Orokusaki.getSpeed());
            CHECK_EQ(12, Kishimoto.getSpeed());
            CHECK_EQ(14, Sasuke.getSpeed());

        }    

        TEST_CASE("Move && Attack Normal Cases:"){    

            Yoshi.move(&Korasaki);
            Sasuke.move(&Yoshi);
            Sasuke.move(&Yoshi);

            CHECK_EQ(Yoshi.getLocation(), Point(14,0));
            CHECK_EQ(Sasuke.getLocation(), Point(13,0));

            Yoshi.slash(&Korasaki);
            Sasuke.slash(&Yoshi);

            CHECK_EQ(Korasaki.get_lives(), 60);
            CHECK_EQ(Yoshi.get_lives(), 60);

            Kishimoto.move(&Orokusaki);
            Kishimoto.slash(&Orokusaki);

            CHECK_EQ(Kishimoto.getLocation(), Point(14,2));
            CHECK_EQ(Orokusaki.get_lives(), 110);

            Orokusaki.move(&Ichigo);

            CHECK_EQ(Orokusaki.getLocation(), Point(23,2));
          
        }

        TEST_CASE("Move && Attack Special Cases:"){

            CHECK_THROWS(Yoshi.slash(&Yoshi));
            CHECK_THROWS(Korasaki.slash(&Korasaki)); 

            while (Yoshi.isAlive())
            {
                Korasaki.slash(&Yoshi);
            }
            CHECK_THROWS(Korasaki.slash(&Yoshi));
            CHECK_THROWS(Yoshi.slash(&Korasaki));

            YoungNinja Jeki_chan("jeki_chan", Point(0,0));
            YoungNinja Neji("Neji", Point(50,0));

            Jeki_chan.slash(&Neji);
            CHECK(Neji.get_lives() == 100);

        }

        
    }

    TEST_SUITE("Cowboy Class"){

        Cowboy tom("tom", Point(0,0));
        Cowboy bily("bili", Point(120,120));

        TEST_CASE("Getters Functions"){

            CHECK_EQ(6, tom.getBoolets());
            CHECK_EQ(110, bily.get_lives());
            CHECK_EQ('C', tom.getType());

            CHECK_FALSE(((tom.is_Partof()) || (tom.isLeader())));

        }

        TEST_CASE("Cowboy Functions - Normal Cases:"){

            tom.shoot(&bily);
            CHECK_EQ(bily.get_lives(), 100);

            while (tom.hasboolets())
            {
                tom.shoot(&bily);
            }

            CHECK_EQ(bily.get_lives(), 50);

            tom.reload();

            CHECK(tom.getBoolets() == 6);

            while (bily.isAlive())
            {
                tom.shoot(&bily);
            }

            CHECK_FALSE(bily.isAlive());
        }

        TEST_CASE("Cowboy Functions - Special Cases:"){

            CHECK_THROWS(bily.shoot(&tom));
            CHECK_THROWS(bily.reload());

            CHECK_THROWS(tom.shoot(&tom));

        }

    }

    TEST_SUITE("Team Class"){

        Cowboy* Raimond = new Cowboy("Raimond", Point(0,0));
        Cowboy* James   = new Cowboy("James", Point(7,0));

        Ninja* Naruto  = new YoungNinja("Naruto", Point(14,0));
        Ninja* Sasuke  = new YoungNinja("Sasuke", Point(28,0));
        Ninja* Sakura  = new YoungNinja("Sakura", Point(42,0));
        Ninja* Shinobi = new YoungNinja("Shinobi", Point(56,0));

        Team a1(Raimond);

        Cowboy* Josef  = new Cowboy("Josef", Point(-7,0));
        Cowboy* Arnold = new Cowboy("Arnold", Point(-14,0));
        Cowboy* David  = new Cowboy("David",  Point(-42,0));

        Ninja* Tanjiro = new YoungNinja("Tanjiro", Point(-14,0));
        Ninja* Nezuko =  new YoungNinja("Nezuko", Point(-28,0));
        Ninja* Gyomei =  new YoungNinja("Gyomei",Point(-21,0));

        Team a2(Josef);

        TEST_CASE("Team Getters"){

            a1.add(James);
            a1.add(Naruto);
            a1.add(Sasuke);
            a1.add(Sakura);
            a1.add(Shinobi);

            a2.add(Arnold);
            a2.add(David);
            a2.add(Tanjiro);
            a2.add(Nezuko);
            a2.add(Gyomei);

            CHECK( Raimond == a1.get_Leader());
            CHECK_FALSE(James == a1.get_Leader());

            CHECK(a1.get_Team()[0] == Raimond);
            CHECK(a1.stillAlive() == 6);
            CHECK(a1.get_Team()[1] == James);
            CHECK(a1.get_Team().size() == 6);

            CHECK_NOTHROW(a1.check_Leader());

        }

        TEST_CASE("Team Initialization - Special Cases"){

            CHECK_THROWS(a1.add(Arnold));
            CHECK_THROWS(a2.add(Naruto));
            CHECK_THROWS(a2.add(Nezuko));


        }

        TEST_CASE("Closest Function"){

            Character* close = a1.get_Team()[a1.closest_to_Member(a1.get_Leader(), &a2)];

            CHECK(close == Josef);

            Character* close2 = a2.get_Team()[a2.closest_to_Member(a2.get_Leader(), &a2)];

            CHECK(close2 == Arnold);


        }

        TEST_CASE("Battle Royal"){
            
        }



    }


