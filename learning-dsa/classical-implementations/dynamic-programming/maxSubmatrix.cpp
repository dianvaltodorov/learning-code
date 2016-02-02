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
int a[MAXN][MAXN];
int n;
int m;
int temp[MAXN];


using namespace std;

void input()
{
  scanf("%d", &n);
  scanf("%d", &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
}

void kadane()
{

}

void maxSubMatrix()
{
  for(int left = 0; left < n; left++)
  {
    memset(temp, 0, sizeof(temp));
    for(int right = 0; right < m; right++)
    {
        for(i = 0; i < n; k++)
            temp[k] += a[i][k];
    }
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

void solve()
{

}

int main()
{
  input();
  solve();
  return 0;
}
