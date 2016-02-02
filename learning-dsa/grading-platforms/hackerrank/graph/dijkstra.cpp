#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < vector < pair < int, int > > > g;
int t;
int n;
int m;
int x, y, w;
int s;
const int INF = 1 << 20;
const int NO_PARENT = -1;
int main()
{
  cin >> t;
  while(t--)
  {
    g.clear();
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++)
    {
      cin >> x >> y >> w;
      g[x - 1].push_back(make_pair(y - 1, w));
      g[y - 1].push_back(make_pair(x - 1, w));
    }
    cin >> s;
    vector <int > p(n, NO_PARENT);
    vector < int > dist(n, INF);
    priority_queue < pair < int, int > > pq;
    pq.push(make_pair(0, s - 1));
    dist[s - 1] = 0;

    while(!pq.empty())
    {
      int currentV = pq.top().second;
      int currentD = -pq.top().first;
      pq.pop();

      if(currentD > dist[currentV]) continue;

      for(int i = 0; i < g[currentV].size(); i++)
      {
        int u = g[currentV][i].first;
        int len = g[currentV][i].second;
        if(dist[currentV] + len < dist[u])
        {
          dist[u] = dist[currentV] + len;
          pq.push(make_pair(-dist[u], u));
        }
      }
    }

    for(int i = 0; i < n; i++)
    {
      if(i  != s - 1)
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
  }
}
