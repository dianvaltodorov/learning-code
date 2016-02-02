#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
int main()
{
  vector < vector < pair < int , int> > > g;
  int n;
  int m;
  cin >> n >> m;
  g.resize(n);
  int x, y, w;
  for(int i = 0; i < m; i++)
  {
    cin >> x >> y >> w;
    g[x - 1].push_back(make_pair(y - 1, w));
  }
  int s;
  cin >> s;

  vector < int > dist(n, INT_MAX);
  priority_queue < pair <int, int> > q;
  q.push(make_pair(0, s));
  while(!q.empty())
  {
    int v = q.top().second;
    int currD = q.top().first;

    if(currD > d[v]) continue;

    for(size_t i = 0; i < g[v].size(); i++)
    {
      int to = g[v][i].first;
      int len = g[v][i].second;

      if(d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        q.push(make(pair(-d[to], to)))
      }

  }
  cout << endl;
}
