#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#include <string.h>
#define MAXN 400


using namespace std;

int n, m;
vector < vector<int> > g;

int prim(int s)
{
  int MST = 0;
  vector<bool> used (n);
  vector<int> min_e (n, INT_MAX), sel_e (n, -1);
  min_e[s] = 0;

  for (int i=0; i<n; ++i) {
    int v = -1;
    for (int j=0; j<n; ++j)
      if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
        v = j;

    if (min_e[v] == INT_MAX) {
      return -1;
    }

    used[v] = true;
    MST += min_e[v];

    for (int to=0; to<n; ++to)
      if(!used[to] && g[v][to])
      {
        if (g[v][to] < min_e[to]) {
          min_e[to] = g[v][to];
          sel_e[to] = v;
        }
      }
  }
  return MST;
}
int main()
{
  scanf("%d%d", &n, &m);
  g.resize(n, vector < int > (n));

  for(int i = 0; i < m; i++)
  {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    g[x - 1][y - 1] = w;
    g[y - 1][x - 1] = w;
    printf("%d\n", prim(x-1));
  }
  return 0;
}
