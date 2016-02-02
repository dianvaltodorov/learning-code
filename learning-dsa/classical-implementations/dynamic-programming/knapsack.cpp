#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXN 1000
#define MAXM 1000

/*
4 7
1 1
3 4
4 5
5 7
*/

using namespace std;
int n, m;
int dyn[MAXN][MAXN];
int w[MAXN];
int c[MAXN];

void input()
{
  scanf("%d", &n);
  scanf("%d", &m);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d",&w[i]);
    scanf("%d",&c[i]);
  }
}

void solve()
{
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= m; j++)
      {
        if(j < w[i]) dyn[i][j] = dyn[i - 1][j];
        else dyn[i][j] = max (dyn[i - 1][j], c[i] + dyn[i-1][j - w[i]]);
      }
}

void printTable()
{
  for(int i = 0; i <=n; i++)
  {
    for(int j = 0; j <= m; j++)
      printf("%d ", dyn[i][j]);
    printf("\n");
  }
}


int main()
{
  input();
  solve();
  printTable();
  return 0;
}
