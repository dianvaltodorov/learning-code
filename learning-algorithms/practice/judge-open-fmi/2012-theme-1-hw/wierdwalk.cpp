#include <stdio.h>
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
  int n;
  scanf("%d", &n);
  int rightCol = n - 1;
  int leftCol = 0;
  int upperRow = 0;
  int lowerRow = n - 1;
  int br = 0;
  for(int f = 1; f <= n/2; f++)
  {
    for(int j = leftCol; j < rightCol; j++)
    {
      a[upperRow][j] = ++br;
      // printf("(%d, %d)", upperRow, j);
    }
    // cout << endl;
    for(int k = upperRow; k < lowerRow; k++)
    {
      a[k][rightCol]= ++br;
      // printf("(%d, %d)", k, rightCol);
    }
    // cout << endl;
    for(int l =  rightCol; l > leftCol; l--)
    {
      a[lowerRow][l] = ++br;
      // printf("(%d, %d)", lowerRow,  l);
    }
    // cout << endl;
    for(int m =  lowerRow; m > upperRow; m--)
    {
      a[m][leftCol] = ++br;
      // printf("(%d, %d)", m, leftCol);
    }
    // cout << endl;
    rightCol--;
    leftCol++;
    upperRow++;
    lowerRow--;
  }
  if(n % 2)
  {
    a[n/2][n/2] = ++br;
    //  printf("(%d, %d)\n", n/2, n/2);
  }
  int i, j;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n - 1; j++)
      printf("%5d ", a[i][j]);
    printf("%5d\n", a[i][j]);
  }
  return 0;
}
