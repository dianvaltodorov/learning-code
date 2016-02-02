#include <queue>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int const MAXN = 1000;

int visited[MAXN];
vector < int > neigh[1024];
int n, m;
int x, y;
int a, b;

int dist1[MAXN];
int dist2[MAXN];
int distBI[MAXN];
int distBJ[MAXN];

void bfs(int v, int *dist)
{
  queue < int > q;
  q.push(v);
  visited[v] = 1;
  while(!q.empty())
  {
    int z = q.front();
    q.pop();
    for(int i = 0; i < neigh[z].size(); ++i)
    {
      int neighbour = v[t][i];
      if(!visited[neighbour])
      {
        q.push(neighbour);
        dist[neighbour] = dist[z] + 1;
        visited[neighbour] = 1;
      }
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; ++i)
  {
    scanf("%d%d", &x, &y);
    neigh[x].push_back(y);
    neigh[y].push_back(x);
  }
  scanf("%d %d\n", &a, &b);

  bfs(a, dist1);
  memset(visited, 0, sizeof(visited));
  bfs(b, dist2);
  int cnt1 = 0;
  for(int i = 1; i <= ++i)
  {
    if(dist1[i] + dist2[i]  > dist1[b])
    {
      cnt1++;
    }
  }

  memset(visited, 0, sizeof(visited));
  memset(dist1, 0, sizeof(dist1));
  memset(dist2, 0, sizeof(dist2));

  bfs(a, dist1);
  memset(visited, 0, sizeof(visited));
  bfs(b, dist2);

  int cnt2 = 0;
  for(int i = 1; i <= ++i)
  {
    if(dist1[i] + dist2[i]  > dist1[b])
    {
      cnt2++;
    }
  }
  printf("%d %d", cnt1, cnt2);

}
