#include <iostream>
#include <sstream>

using namespace std;
int main()
{
  cout << "output sentence" << endl;
  int x;
  cin >> x;

  char line[13];
  getline(cin, line);

  string mystr ("1204");
  int myint;
  stringstream(mystr) >> myint;
}
