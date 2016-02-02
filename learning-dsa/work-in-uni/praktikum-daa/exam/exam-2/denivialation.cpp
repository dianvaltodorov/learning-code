#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int mat[1<<10][1<<10];
int a[1<<10][1<<10];
int n, m;
void printA()
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}
int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &mat[i][j]);



  for(int i = 0 ; i <= n; i++) {mat[i][0] = INT_MAX;}
  for(int j = 0 ; j <= m; j++) {mat[0][j] = INT_MAX;}

  for(int i = 1; i <=n; i++)
    for(int j = 1; j <= m; j++)
    {
      a[i][j] = min (abs(mat[i][j] - mat[i-1][j]), abs(mat[i][j] -  mat[i][j-1]));
    }

  a[1][1] = 0;
  printA();
  for(int i = 1; i <=n; i++)
    for(int j = 1; j <= m; j++)
    {
      a[i][j] = max (a[i][j] + a[i-1][j], a[i][j] + a[i][j-1]);
    }
  printA();
  return 0;
}
