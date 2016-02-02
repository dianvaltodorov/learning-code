#include <iostream>
using namespace std;
class Rectangle
{
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {};
  int area() {return width*height;}
};

int main()
{
  Rectangle obj(4,5);
  Rectangle *foo, *bar,
}
