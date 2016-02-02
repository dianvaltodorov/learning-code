#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#include <string.h>
#include <climits>

#define MAXN 1001

using namespace std;

char word[MAXN];
bool p[MAXN][MAXN];
int dyn[MAXN][MAXN];
int n;


void printTable()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", dyn[i][j]);
    printf("\n");
  }
}

void printPalindromeTable()
{

  for(int i = 0; i <n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", p[i][j]);
    printf("\n");
  }
}

void solve()
{
  for(int i = 0; i < n; i++)
    p[i][i] = true;

  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < n - i; j++)
    {
      if(i == 1)
      {
        p[j][j+i] = (word[j] == word[j + i]);
      }
      else
      {
        p[j][j + i] = (word[j] == word[j + i]) && p[j + 1][j + i - 1];
      }

      if(p[j][j+i]) dyn[j][i] = 0;
      else
      {
        dyn[j][j + i] = INT_MAX;
        for(int k = j; k < j + i; k++)
          dyn[j][j + i] = min(dyn[j][j+i], 1 + dyn[j][k] + dyn[k+1][j+i]);
      }
    }
  }
}
int main()
{
  scanf("%s", word);
  n = strlen(word);
  solve();
  // printPalindromeTable();
  // printTable();
  printf("%d\n", dyn[0][n-1] + 1);
  return 0;
}
