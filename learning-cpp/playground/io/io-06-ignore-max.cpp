#include <iostream>
#include <limits>
using namespace std;
int main()
{
  int n;
  cin >> n;

  if (cin.eof() || cin.bad()) {
      return 1;
  } else if (cin.fail()) {
      cin.clear(); // unset failbit
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
  } else {
      std::cout << n << '\n';
  }
  cin >> n;
}
