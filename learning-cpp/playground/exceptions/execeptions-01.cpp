#include <iostream>
using namespace std;
int main()
{
  try
  {
      throw 3.12;
      throw 20;
      throw 'c';
  }
  catch (int param) { cout << "int exception"; }
  catch (char param) { cout << "char exception"; }
  catch (...) { cout << "default exception"; }

  try {
    try {
        // code here
    }
    catch (int n) {
        throw;
    }
  }
  catch (...) {
    cout << "Exception occurred";
  }


  return 0;
}
