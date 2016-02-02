#include <iostream>
using namespace std;

class Rectangle
{
  int width, height;
public:
  Rectangle(int, int);
  Rectangle();
  void set_values(int, int);
  int area() {return width*height;}
};

void Rectangle::set_values(int x, int y)
{
  width = x;
  height = y;
}

Rectangle::Rectangle()
{
  width = 0;
  height = 0;
}

Rectangle::Rectangle(int a, int b)
{
  width = a;
  height = b;
}

int main()
{
  Rectangle recta, rectb;
  recta.set_values(4,5);
  rectb.set_values(5,6);
  return 0;
}
