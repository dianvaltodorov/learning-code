#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#include <string.h>
#define MAXN 4002

int dyn[MAXN][MAXN];
char a[MAXN];
int n;

using namespace std;
void input()
{
    scanf("%s", a);
}
void solve()
{
  n = strlen(a);
  for(int i = 0; i < n; i++)
    dyn[i][i] = 1;

  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < n - i; j++)
      if(a[j]==a[i + j]) dyn[j][i + j] = dyn[j + 1][i + j - 1] + 2;
      else dyn[j][i + j] = max(dyn[j][i + j -1],dyn[j + 1][i + j]);
  }
}

void printTable()
{
  for(int i = 0; i <n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", dyn[i][j]);
    printf("\n");
  }
}

int main()
{
  input();
  solve();
  // printTable();
  printf("%d\n", dyn[0][n-1]);
  return 0;
}
