#include <iostream>
using namespace std;

/* TODO:
1. what happens here? What is stack smashing? Реално какво означава това?
**/
int main()
{
  char name[5];
  cin.getline(name, 10);
  cout << name << endl;
  cout << cin << endl;


  char address[4];
  cin.getline(address, 10);
  cout << address << endl;
  cout << cin << endl;
  return 0;
}
