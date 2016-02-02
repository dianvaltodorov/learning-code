#include <iostream>

using namespace std;
int main()
{
  int x;
  cin >> x;
  cin.clear();
  cout << cin.sync() << endl;
  cin.get();
  cin >> x;
  cout << x << endl;
  return 0;
}
