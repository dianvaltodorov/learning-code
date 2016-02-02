#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
int t, N, M;
int m[1<<10], c[1<<10];
int F[1<<10][1<<10];

void printF()
{
  for(int i = 0; i < N; i++)
    {
      for(int j = 0; j <= M - 1; j++)
        printf("%d ", F[i][j]);
      printf("\n");
    }
}
void input()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
  {
    scanf("%d %d", &m[i], &c[i]);
  }
}

void solve()
{
  int i,j;
  for (j = 0; j <= M; j++)
    F[0][j] = 0;
  for (i = 1; i <= N; i++)
    for (j = 0; j <= M; j++)
      if (j >= m[i] && F[i-1][j] < F[i-1][j-m[i]] + c[i])
        F[i][j] = F[i-1][j-m[i]] + c[i];
      else
        F[i][j] = F[i-1][j];
  printf("%d\n", F[N-1][M - 1]);
}
int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
      input();
      solve();
      printF();
    }
}
