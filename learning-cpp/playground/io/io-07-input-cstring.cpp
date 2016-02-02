#include <iostream>
using namespace std;

/* TODO:
1. Какво става тука? Защо ми позволява да въведа 20 символа?
2. Защо ми разрешава да въведа 20 симнвола?
**/
int main()
{
  char name[10];
  cin.getline(name, 20);
  cout << name << endl;
  cout << cin << endl;
  return 0;
}
