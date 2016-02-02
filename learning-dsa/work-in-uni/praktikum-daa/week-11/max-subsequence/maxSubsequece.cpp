#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  scanf("%d", &n);
  vector < int > a(n);
  for(int i = 0; i < n; i++)
    scanf("%d" , &a[i]);

  vector < int > f(n);
  f[0] = a[0];
  for(int i = 0 ; i < n; i++)
    f[i] = max(a[i] , a[i] + f[i - 1]);

  printf("\n");
  for(int i = 0 ; i < n; i++)
    printf("%d\n", f[i]);

  printf("%d\n", f[n - 1]);
  return 0;
}
