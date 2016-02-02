#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#include <string.h>
#define MAXN 4002

using namespace std;

int main()
{
  int k, l, m;
  int n[MAXN];
  scanf("%d%d%d", &k, &l, &m);
  int maxPile = 0;
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &n[i]);
    maxPile = max(maxPile, n[i]);
  }

  vector<int> dyn (maxPile);
  dyn[0] = 0;
  dyn[1] = 0;
  for(int i = 2; i <= maxPile; ++i)
  {
      if(i == k) dyn[i] = 0;
      else if (i == l) dyn [i] = 0;
      else if (i < k && i < l)  dyn[i] = !(i % 2);
      else if (i < l)  dyn[i] = !(dyn[i - 1] || dyn[i - k]);
      else dyn[i] = !(dyn[i - 1] ||  dyn[i - k] || dyn[i - l]);
  }

  // for(int i = 0; i <= maxPile; i++)
  // {
  //   printf("%3d", i);
  // }
  // printf("\n");
  // for(int i = 0; i <= maxPile; i++)
  // {
  //   printf("  %c", (!(dyn[i]))? 'A':'B');
  // }
  // printf("\n");
  // for(int i = 0; i <= maxPile; i++)
  // {
  //   printf("%3d", dyn[i]);
  // }
  // printf("\n");
  for(int i = 0; i < m; i++)
  {
    printf("%c", (!(dyn[n[i]]))? 'A':'B');
  }
  printf("\n");
}
