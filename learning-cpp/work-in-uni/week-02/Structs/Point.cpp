#include "Point.h"
#include <iostream>
#include <math.h>

//call-by-name
void Point::read()
{
    std::cin >> x >> y;
}

//print
void print(const Point& p)
{
    std::cout << "(" << p.x << "," << p.y << ")"<< std::endl;
}

//distance between two points
double distance(const Point& p1, const Point& p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) - (p1.y - p2.y)*(p1.y - p2.y));
}
