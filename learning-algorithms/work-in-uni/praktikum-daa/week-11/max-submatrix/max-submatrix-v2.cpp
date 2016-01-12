#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[1<<9][1<<9];
long long partial[1<<9][1<<9];
long long g[1<<9][1<<9];
int main()
{
  int n;
  for(int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%lld", &a[i][j]);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      partial[i][j] = partial[i][j] + partial[i - 1][j];

  long long best = -100000;

  for(int x0 = 1; x0 <= n; ++x0)
    for(int y0 = 1; y0 <= n; ++y0)
      for(int x1 = 1; x1 <= n; ++x1)
        for(int y1 = 1; y1 <= n; ++y1)
        {
          long long g = partial[x1][y1] + partial[x1][y0] - partial[x0][y0];
          best = max(best, g);
        }

  printf("%lld\n", best);
}
