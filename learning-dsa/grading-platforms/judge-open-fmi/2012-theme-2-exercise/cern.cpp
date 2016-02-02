#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
string a[10000];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++)
    cout << a[i] << endl;
  return 0;
}
