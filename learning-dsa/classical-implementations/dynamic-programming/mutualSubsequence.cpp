#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

char F[MAXN][MAXN];

const char x[MAXN] = "acacacababacaacbabababa"
const char y[MAXN] = "acacacbdbdbbbbabbba"

unsigned LCS_Length()
{
  unsigned i, j, m, n;
  m = strlen(x);
  n = strlen(y);

  for(i = 1; i <= m; i++)
    F[i][0] = 0;
  for(j = 1; j <= n; j++)
    F[0][j] = 0;

  for(i = 1; i <= m; i++)
    for(j = 1; j <= n; j++)
      if(x[i - 1] == y[j - 1])
        F[i][j] = F[i - 1][j - 1] +1;
      else
        F[i][j] = max(F[i - 1][j], F[i][j - 1]);

  return F[m][n];
}
int main()
{

  LCS_Length();
}
