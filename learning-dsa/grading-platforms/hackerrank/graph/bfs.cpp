#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, n, m, x, y, s;

int main()
{
  cin >> t;
  for(int k = 0; k < t; k++)
  {
    cin >> n >> m;
    vector < vector <int > > g(n);
    vector<char> used(n, 0);
    vector<int> dist(n, 0);


    queue<int> q;

    for(int i = 0; i < m; i++)
    {
      cin >> x >> y;
      g[x - 1].push_back(y - 1);
      g[y - 1].push_back(x - 1);
    }

    cin >> s;
    q.push (s - 1);
    used[s - 1] = 1;
    dist[s - 1] = 0;
    color[s - 1] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                dist[to] = dist[v] + 1;
            }
        }
    }

    for(int i = 0; i < dist.size(); i++)
    {
      if(i!=s-1)
        if(dist[i]!=0) cout << 6*dist[i] << " ";
        else cout << -1 << " ";
    }
    cout << endl;
  }
}
