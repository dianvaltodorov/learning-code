#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define MAXN 1000000
int n, m, a;
int b[MAXN];
int x[MAXN], y[MAXN];


bool isPointAbove(int x, int y, int b)
{
    return a * x + b < y;
}

int main()
{
  scanf("%d%d%d", &n, &m, &a);
  for(int i = 0; i < n; i++)
      scanf("%d%d", &x[i] , &y[i]);

  for(int i = 0; i < m; i++)
    scanf("%d", &b[i]);

  for(int i = 0; i < m; i++)
  {
    int counter = 0;
    for(int j = 0; j < n; j++)
      if(isPointAbove(x[j], y[j], b[i]))
        counter++;
    printf("%d\n", counter);
  }
}
