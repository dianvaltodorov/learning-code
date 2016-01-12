// можем да ги помним в pair-и или в два масива
// ако резултата е по добър обнови и двете стойности, ако не е по добър обнови
// и двете стойности.

#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>

#define MAXN 1000
#define MAXV 1000

using namespace std;
int t, n, v;
int dyn[2][MAXV];
int weight[MAXN];
int value[MAXN];

void input()
{
  scanf("%d %d", &n, &v);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &weight[i], &value[i]);
  }
}

void printDyn()
{
  for(int i = 0; i <= v; i++)
  {
    printf("%d ",dyn[0][i]);
  }
  printf("\n");
  for(int i = 0; i <= v; i++)
  {
    printf("%d ",dyn[0][i]);
  }
}s
int solve()
{
  memset(dyn, 0, sizeof(dyn));
  for(int i = 0; i <= n; ++i)
  {
       int cur = i % 2;
       int prev = 1 - cur;
       dyn[cur][0] = 0; // попълваме нулата, затова цикъла по j започва по i

       for(int j = 1; j < v; j++)
       {
         dyn[cur][j] = dyn[prev][j];
         if(weight[i - 1] <= j)
           dyn[cur][j] = max(dyn[cur][j], dyn[prev][j - weight[i - 1]] + value[i - 1]);
       }
   }
  return  dyn[n%2][v];
}
int main()
{
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
      input();
      printf("%d\n", solve());
    }
}
