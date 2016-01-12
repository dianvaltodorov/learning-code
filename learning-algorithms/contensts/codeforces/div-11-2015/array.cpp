#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
int n;
int a[1000000];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  long long sum = abs(a[0]);
  for(int i = 1; i < n; i++)
  {
    sum += abs(a[i] - a[i-1]);
  }
  printf("%I64d\n", sum);
  return 0;
}
