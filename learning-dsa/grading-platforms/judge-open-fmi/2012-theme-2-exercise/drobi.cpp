#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
typedef pair<int , int> pii;
int euclid(int u, int v)
{
    while ( v != 0)
    {
        int r = u % v;
        u = v;
        v = r;
    }
    return u == 1;
}


bool compare(pii i, pii j) { i.first * j.second < i.first * j.second; }

int main()
{
  int n;
  vector < pair < int , int > > nums;
  scanf("%d", &n);
  for(int i = 1; i <= n - 1; i++)
    for(int j = i + 1; j <= n; j++)
      if(euclid(i,j)) nums.push_back(make_pair(i, j));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      if(compare(vec[i))
    }

  return 0;
}
