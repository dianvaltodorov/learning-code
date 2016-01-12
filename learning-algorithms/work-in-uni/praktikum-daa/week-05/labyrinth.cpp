#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 1 << 10
using namespace std;

int n, m;
char lab[MAXN][MAXN];
int startI, startJ;
int maxVertI;
int maxVertJ;
int maxDist;
int dI[4] = {1, -1, 0 ,0};
int dJ[4] = {0 ,0, 1, -1};
int mat1[MAXN][MAXN];
int mat2[MAXN][MAXN];

void setUp()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(lab[i][j] == '.')
      {
        mat1[i][j] = 1;
        mat2[i][j] = 1;
        startI = i;
        startJ = j;
      }
      else
      {
        mat1[i][j] = 0;
        mat2[i][j] = 0;
      }
}

void printMat1()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
      printf("%d", mat1[i][j]);
    printf("\n");
  }
}

void dfs1(int i, int j, int d)
{
  mat1[i][j] = 0;
  if(d > maxDist)
  {
    maxDist = d;
    maxVertI = i;
    maxVertJ = j;
  }
  int newI, newJ;
  for(int k = 0; k < 4; k++)
  {
    newI = i + dI[k];
    newJ = j + dJ[k];
    if(newI >= 0 && newI <= n && newJ >= 0 && newJ <= m && mat1[newI][newJ] == 1)
    {
      dfs1(newI, newJ, d + 1);
    }
  }
}

void dfs2(int i, int j, int d)
{
  mat2[i][j] = 0;
  if(d > maxDist)
  {
    maxDist = d;
    maxVertI = i;
    maxVertJ = j;
  }
  int newI, newJ;
  for(int k = 0; k < 4; k++)
  {
    newI = i + dI[k];
    newJ = j + dJ[k];
    if(newI >= 0 && newI <= n && newJ >= 0 && newJ <= m && mat2[newI][newJ] == 1)
    {
      dfs2(newI, newJ, d + 1);
    }
  }
}

int main()
{
  scanf("%d %d", &m, &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s", lab[i]);
  }
  setUp();
  // printMat1();
  dfs1(startI, startJ, 1);
  // printf("%d %d\n", startI, startJ);
  // printf("%d\n",  maxDist);
  maxDist = 0;
  dfs2(maxVertI, maxVertJ, 0);
  printf("%d\n",  maxDist);
  return 0;
}
