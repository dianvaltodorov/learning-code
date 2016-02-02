#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;
int main()
{
  int x = 10;
  cout << &x << endl;
  cout << "a = " << bitset<64>(x)  << endl;
  cout << hex << 16 << endl;
}
