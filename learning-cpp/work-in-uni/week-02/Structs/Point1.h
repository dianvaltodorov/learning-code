struct Point
{
    double x,y;
};

//call-by-value we work with a copy of the Point, when the function is over the cipy will be over;
//void read(Point);

//call-by-name
void read(Point&);

//print
void print(const Point&);

//distance between two points
double distance(const Point&, const Point&);

