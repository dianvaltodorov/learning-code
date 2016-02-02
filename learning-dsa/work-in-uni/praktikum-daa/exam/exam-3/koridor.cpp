#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define MAXN 1000000
int n;
unsigned long long dyn[MAXN];

void printDyn()
{
  for(int i = 0; i < n; i++)
    printf("%2d ", i);
  printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%2llu ", dyn[i]);
  }
  printf("\n");
}
int main()
{
  scanf("%d", &n);
  dyn[0] = 0;
  dyn[1] = 0;
  dyn[2] = 0;
  dyn[3] = 2;
  dyn[4] = 0;
  dyn[5] = 4;
  if(n < 5) printf("%llu\n", dyn[n]);

  else
  {
    for(int i = 6; i <= n; i++)
    {
      if(dyn[i - 3] && dyn[i - 5])
        dyn[i] =  dyn[i - 3] * dyn[i - 5];
      else if(dyn[i - 3])
        dyn[i] = dyn[i - 3] * dyn[3];
      else if(dyn[i - 5])
        dyn[i] = dyn[i - 5] * dyn[5];
    }
   printf("%llu\n", dyn[n]);
  }

  printDyn();
  return 0;
}
