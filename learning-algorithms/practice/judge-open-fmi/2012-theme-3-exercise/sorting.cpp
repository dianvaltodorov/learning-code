#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXN 100016
using namespace std;
int n;
long long a[100016];

int main()
{
  scanf("%d", &n );
  for(int i = 0; i < n ; i++)
    scanf("%lld", &a[i]);

  sort(a, a + n);

  for(int i = 0; i < n - 1; i++)
    printf("%lld ", a[i]);
  printf("%lld\n", a[n - 1]);
  return 0;
}
