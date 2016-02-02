#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXN 1000000

using namespace std;
int dyn[MAXN];
int a[MAXN];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  vector<int> dyn(n, 1);
  for(int i = 0; i < n; i++)
  {
    printf("\n");
    for(int j = 0; j < i; j++)
      if(dyn[j] < dyn[i])
      {
        printf("%d", dyn[i]);
        dyn[i] = max (dyn[i], dyn[j] + 1);
      }
  }
  for(int i = 0; i < n; i++)
    printf("%d ", dyn[i]);
  printf("\n");
  return 0;
}
