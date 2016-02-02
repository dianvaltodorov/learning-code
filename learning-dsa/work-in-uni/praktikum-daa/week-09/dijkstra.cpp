#include<vector>
#include<queue>
using namespace std;
int main()
{
  int n;
  scanf("%d", &n);
  vector < vector < pair <int, int> > > g(n); //the graph
  //input graph
  int x, y, w;
  for(int i = 0; i < n - 1; i++)
  {
    scanf("%d %d %d", x, y, w);
    g[x].push_back(make_pair(y, w)))
  }
  int s; // starting vertex
  scanf("%d", &s);

  vector<int> d (n, INF),  p (n);
  	d[s] = 0;
  	priority_queue < pair<int,int> > q;
  	q.push (make_pair (0, s));
  	while (!q.empty()) {
  		int v = q.top().second,  cur_d = -q.top().first;
  		q.pop();
  		if (cur_d > d[v])  continue;

  		for (size_t j=0; j<g[v].size(); ++j) {
  			int to = g[v][j].first,
  				len = g[v][j].second;
  			if (d[v] + len < d[to]) {
  				d[to] = d[v] + len;
  				p[to] = v;
  				q.push (make_pair (-d[to], to));
  			}
  		}
  	}
  }



  }


  d[s] = 0;
}
