#include <iostream>
using namespace std;

int main()
{
  int x;
  cout << "Enter x" << endl;
  cin >> x;
  while (!cin)
  {
      cin.clear(); // Sets a new value for the stream's internal error state flags.
      cin.sync(); // Sets ter
      cin.get();
      cout << "You must enter a number!\nEnter again: ";
      cin >> x;
  }
  cout << x << endl;
  cout << cin << endl;
}
