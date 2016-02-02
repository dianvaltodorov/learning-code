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

using namespace std;
vector < vector < pair < int, int> > > g;
int n, m, s;

/*

5 6
1
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/

void printGraph()
{
  for(int i = 0; i < g.size(); i++)
  {
    for(int j = 0; j < g[i].size(); j++)
      printf("(%d, %d, %d) ", i + 1, g[i][j].first + 1, g[i][j].second);
    printf("\n");
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  scanf("%d", &s);
  int x, y, w;
  g.resize(n);
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &x, &y, &w);
    g[x - 1].push_back(make_pair(y - 1, w));
    g[y - 1].push_back(make_pair(x - 1, w));
  }

  printGraph();

  vector<int> d(n, INT_MAX), p(n);
  d[s - 1] = 0;
  priority_queue< pair <int, int> > q;
  q.push(make_pair(0, s - 1));


  while(!q.empty())
  {
    int v = q.top().second;
    int currD = -1 * q.top().first;
    q.pop();

    if(currD > d[v]) continue;

    for(int i = 0; i < g[v].size(); i++)
    {
      int u = g[v][i].first;
      int len = g[v][i].second;
      if(d[u] > currD + len)
      {
        d[u] = currD + len;
        p[u] = v;
        q.push(make_pair(-d[u], u));
      }
    }
  }

  // printGraph();
  for(int i = 0; i < n; i++)
  {
    printf("distance between %d %d is: %d\n", s, i + 1, d[i]);
  }
  printf("\n");
  return 0;
}
