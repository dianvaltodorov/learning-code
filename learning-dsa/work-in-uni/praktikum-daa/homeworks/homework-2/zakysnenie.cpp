#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAXN 400

using namespace std;

int n, m;
vector < vector < pair <int, int> > > g;
vector < pair <int, int> > times;

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
/*
7 11
1 2 12
1 4 9
1 6 6
2 6 7
2 3 15
3 6 8
3 5 2
3 7 4
4 5 15
4 6 4
5 6 10
7 4
5 11
2 8
4 5
8 8
0 120
2 5
*/
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  for(int i = 0; i < m; i++)
  {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    g[x - 1].push_back(make_pair(y - 1, w));
    g[y - 1].push_back(make_pair(x - 1, w));
  }


  for(int i = 0; i < n; i++)
  {
    int green, red;
    scanf("%d%d", &green, &red);
    times.push_back(make_pair(green, red));
  }

  priority_queue <  pair < int ,int > > q;
  vector<int> d(n, INT_MAX);
  int s = 0;

  d[s] = 0;
  q.push(make_pair(d[s] , s));

  while(!q.empty())
  {
    int u = q.top().second;
    int minD = -1 * q.top().first;
    q.pop();

    if(minD > d[u] || times[u].first == 0) continue;

    // printf("\n");
    // for(int i = 0; i < n; i++)
    // {
    //   printf("distance between %d %d is: %d\n", s + 1, i + 1, d[i]);
    // }

    for(int i = 0; i < g[u].size(); i++)
    {
      int v = g[u][i].first;
      int lenE = g[u][i].second;
      int green = times[v].first;
      int red = times[v].second;
      int cycle = red + green;
      int modTime = (minD + lenE) % cycle;
      int aditional = (modTime <= green) ? 0 : (cycle - modTime) ;

      if(d[v] > lenE + minD + aditional)
      {
        d[v] = lenE + minD + aditional;
        q.push(make_pair(-d[v], v));
      }
    }
  }

  printf("%d\n", d[n-1]);
  // printf("\n");
  // for(int i = 0; i < n; i++)
  // {
  //   printf("distance between %d %d is: %d\n", s + 1, i + 1, d[i]);
  // }
  // printf("\n");
  //
  // for(int i = 0; i < n; i++)
  // {
  //   printf("%d :", i + 1);
  //   for(int j = 0; j < g[i].size(); j++)
  //     printf("%d ", g[i][j].first + 1);
  //   printf("\n");
  // }

}
