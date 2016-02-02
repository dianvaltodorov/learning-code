#include <iostream>
using namespace std;
void double_it(int *p);

int main()
{
  int *p;
  int x = 4;
  p = &x;
  cout << p << endl;
  cout << *p << endl;
  *p = *p + 3;
  cout << *p << endl;
  cout << x << endl;
  double_it(p);
  cout << *p << endl;
  cout << x << endl;
  double_it(&x);
  cout << *p << endl;
  cout << x << endl;
}

void double_it(int *p)
{
  *p = *p * 2;
}
void swap(int *p1, int *p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
