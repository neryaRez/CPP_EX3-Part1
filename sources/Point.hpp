#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

namespace ariel{

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y);
    double distance(const Point& other) const;
    static Point moveTowards(const Point& source, const Point& dest, double dist);
    void print();
    double getX();
    double getY();

};



}