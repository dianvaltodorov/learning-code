#include <iostream>
using namespace std;
int main()
{
  int x;
  char buffer1[100];
  char buffer2[100];
  cin >> buffer1;
  cin.ignore(10, ' ');
  cin >> buffer2;
  cout << buffer1 << endl; //TODO: тука какво п о дяволите става
  cout << buffer2 << endl;
}
