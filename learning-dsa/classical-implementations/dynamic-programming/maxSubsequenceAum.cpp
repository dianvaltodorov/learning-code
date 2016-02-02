#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXN 1000000

using namespace std;
int dyn[MAXN];
int a[MAXN];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int max = 0, temp;
  for(int i = 0; i < n; i++)
  {
    temp = temp + a[i];

    if(temp < 0)
      temp = 0;

    if(max < temp)
      max = temp;
  }
  printf("%d\n", max);
  return 0;
}
