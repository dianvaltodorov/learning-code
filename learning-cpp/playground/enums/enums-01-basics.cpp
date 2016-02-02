#include <iostream>
using namespace std;
int main()
{
  enum Color { red, green, blue = 12, white, yellow = 300, purple};
  Color r = red;
  cout << r << endl;
  cout << "red = " << red << endl;
  cout << "green = " << green << endl;
  cout << "blue = " << blue << endl;
  cout << "white = " << white << endl;
  cout << "yellow = " << yellow << endl;
  cout << "purple = " << purple << endl;
  cout << "sizeof(Color) = "  << sizeof(Color) << endl;

  int x = yellow;
  cout <<"converted to int yellow " << x << endl;

  switch(r)
  {
      case red  : std::cout << "red\n";   break;
      case green: std::cout << "green\n"; break;
      case blue : std::cout << "blue\n";  break;
  }
}
