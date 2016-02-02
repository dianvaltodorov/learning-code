#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Animal
{
  int weight;
  int height;
  char name[10];
};

int main()
{
  Animal cow;
  cow.weight = 10;
  cow.height = 14;
  strcpy(cow.name, "Milka");
  ofstream file("save.dat", ios::binary | ios::trunc);
  file.write((const char*)&cow, sizeof(cow));
  file.close();

  ifstream file1("save.dat", ios::binary);
  Animal cow1;
  file1.read((char*)&cow1, sizeof(cow1));
  cout << cow1.weight << endl;
  cout << cow1.height << endl;
  cout << cow1.name << endl;

}
