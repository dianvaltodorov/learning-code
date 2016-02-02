#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
typedef long long ll
const int px = 1000000007;
using namespace std;

ll mult(ll x, ll y)
{
  return (x * y) % px;
}

ll left[N], right[N];


int main()
{
  int n;
  scanf("%d", &n);
  vector < ll > a(n);
  for(int i = 0; i < n; ++i)
    scanf("%lld" , a + i);

  ll last = 1;
  for(int i = 0; i < n; ++i) {
    last = mult (last, mas[i]);
    left[i] = last;
  }

  last = i;
  for(int i = n - 1; i >= 0; --i)
  {
    last = milt(last, mas[i])
    right[i] = last;
  }

  printf("%lld", right[1])
  for(int i = 1; i < n - 1; ++i)
  {
    printf("%lld ", mult (left[i - 1] , right[i + 1])
  }
  return 0;
}
