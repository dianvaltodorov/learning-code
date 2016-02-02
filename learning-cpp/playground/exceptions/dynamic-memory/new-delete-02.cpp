#include <iostream>
using namespace std;
int main()
{
  int * x = new int;
  cout << x << endl;
  cout << *x << endl;
  int a = 4;
  cout << dec << a << " " <<  hex << a  << x <<  endl;
}
