#include "doctest.h"
#include "sources/Point.hpp"

using namespace std;
using namespace ariel;

TEST_SUITE("Point class tests") {

    Point p1{1, 1};
    Point p2{2, 3};
    Point n1{-1, 1};
    Point n2{1, -9};
    Point n3{-1, -1};

    TEST_CASE("Distance method") {
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(n1.distance(n2), n2.distance(n1));
        CHECK_EQ(n3.distance(p1), p1.distance(n3));

        CHECK_EQ(n2.distance(p1), 10);
        CHECK_EQ(p2.distance(n3), 5);
        CHECK_EQ(p1.distance(p1), 0);
    }

    TEST_CASE("moveTowards method") {
        double distance = p1.distance(p2);
        double half_p = distance / 2;
        double third_p = distance / 3;

        Point p3{Point::moveTowards(p1, p2, half_p)};
        CHECK_EQ(p3.distance(p2), doctest::Approx(half_p).epsilon(0.001));

        Point p4{Point::moveTowards(p1, p2, third_p)};
        CHECK_EQ(p4.distance(p2), doctest::Approx(third_p * 2).epsilon(0.001));

        // There is no such a thing as negative distance
        CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1),std::invalid_argument);
    }

}