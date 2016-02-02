#include <iostream>
#include <iomanip>
// #define DEBUG

using namespace std;
const int i = 100;

int main()
{

  #ifdef DEBUG
    cout << "This is the test version, i=" << i << endl;
  #else
    cout << "This is the production version!" << endl;
  #endif

  cout << setw(5) << 5 << endl;
  return 0;
}
