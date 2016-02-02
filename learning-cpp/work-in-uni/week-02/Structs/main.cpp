#include <iostream>
#include <string.h>

#include "Point.h"
#include "Point.h"
#include "Point.h"
#include "Point.h"
#include "Point.h"
#include "Student.h"

void readPoints(Point* arr, size_t n)
{
    Point* end = arr + n - 1;
    for(; arr <= end; ++arr)
    {
        arr->read();
    }
}

void printMaxDistance(Point* arr, size_t n)
{
    Point* end = arr + n - 1;
    double maxDistance;
    Point *mdFirst = NULL, *mdSecond  = NULL;

    for(Point* first = arr; first < end; ++first)
    {
        for(Point* second = first + 1; second <= end; ++second)
        {
            double currentDistance = distance(*first, *second);
            if(maxDistance > currentDistance)
            {
                maxDistance = currentDistance;
                mdFirst = first;
                mdSecond = second;
            }
        }
    }

    std::cout << "Maximum Distance = " << maxDistance << std::endl;
    print(*mdFirst);
    print(*mdSecond);
}


void printPairs(Point* arr, size_t n)
{
    Point* end = arr + n - 1;
    // какъв е еквивалента на linux
    Point *mdFirst = NULL, *mdSecond  = NULL;

    for(Point* first = arr; first < end; ++first)
    {
        for(Point* second = first + 1; second <= end; ++second)
        {

        }
    }
}
int main()
{
    Student s;
    // doesn't work
    // s.name = "Ivan";

    strcpy(s.name, "Ivan");
    Student st = s;
    Point points[9];
    readPoints(points, 4) ;
    //printMaxDistance(points, 4);
    //Point p = (3,4);
    Point p;

    p.x = 3;
    p.y = 4;

    Point* pp = &p;

    pp->x = 7;
    (*pp).y = 6;

    return 0;
}






