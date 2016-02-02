#include <iostream>
#include <bitset>

using namespace std;
int main()
{
  //promotion
  int a = 10;
  short b;
  std::bitset<sizeof(int) * 8> b1(0);
  cout << b1 << endl;

  std::bitset<sizeof(int) * 8> b2(1);
  cout << b2 << endl;

  std::bitset<sizeof(int) * 8> b3(2);
  cout << b3 << endl;

  std::bitset<sizeof(int) * 8> b4(3);
  cout << b4 << endl;

  std::bitset<sizeof(int) * 8> b5(4);
  cout << b5 << endl;


  std::bitset<sizeof(int) * 8> b6(5);
  cout << b6 << endl;


  std::bitset<sizeof(int) * 8> b7(6);
  cout << b7 << endl;


  std::bitset<sizeof(int) * 8> b8(7);
  cout << b8 << endl;


  int x = 129833124;
  std::bitset<sizeof(int) * 8> b9(x);
  cout << b9 << endl;

  std::bitset<sizeof(short) * 8> b10((short) x);
  cout << b10 << endl;

  cout << hex << 10 << endl;
  //dem std::bitset<8> b1;

}
