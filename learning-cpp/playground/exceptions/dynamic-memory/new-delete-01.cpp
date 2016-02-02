#include <iostream>
using namespace std;

int main() {
  int i, n;
  int *p ;
  cout << "How many numbers do you want to type?" << endl;
  cin >> i;
  p  = new (nothrow) int[i];
  if(p == NULL)
    cout << "Error: memory could not be allocated";
  else
  {
    for (n = 0; n < i; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have enetered" << endl;
    for (n = 0; n < i; n++) {
      std::cout << p[n] << " " << std::endl;
    }
    delete [] p;
  }
  return 0;
}
