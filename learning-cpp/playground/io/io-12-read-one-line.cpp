#include <iostream>
using namespace std;
int main()
{
  char color[10];
  char name[10];
  cin >> color;
  cin.ignore();
  cin.getline(name, 100);
  cout << color << endl;
  cout << name << endl;
  cout << cin.good() << endl;
}
