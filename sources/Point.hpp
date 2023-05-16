#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace ariel{

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y);
    double distance(const Point& other) const;
    static Point moveTowards(const Point& p1, const Point& p2, double dist);
    void print();
    double getX();
    double getY();

};



}