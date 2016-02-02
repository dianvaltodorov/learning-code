#include<stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
int const MAXN = 1000000;
int const MAXM = 1000000;
int a[MAXN] = {1, 2, 1, 4, 190};
int s[MAXM] = {2, 1, 6, 195};
int n = 5;
int m = 4;

int main(){

  for(int i = 0; i <= n - 1; i++)
    printf("%d ", a[i]);
  printf("\n");

  sort(a, a + 5);
  printf("upper_bound(%d) = %d", 1, *upper_bound(a, a + 5, 3));
  for(int i = 0; i <= n; i++)
  {
    int sum = s[i];
    for(int j = 0; j <= n; j++)
    {

    }
  }
}
