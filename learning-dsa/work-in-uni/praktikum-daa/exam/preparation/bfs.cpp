#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#define MAXN 1000
#define NO_PARENT -1;
using namespace std;

int n;
int visited[MAXN];
int dist[MAXN];
int parent[MAXN];
int used[MAXN];

int main()
{
  vector < int > ne[MAXN];
  int n, m;
  int x, y;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &x, &y);
    ne[x - 1].push_back(y - 1);
    ne[y - 1].push_back(x - 1);
  }

  for(int i = 0; i < n; i++)
  {
    parent[i] = NO_PARENT;
  }
  int s;
  scanf("%d", &s);
  queue < int > q;
  q.push(s - 1);
  used[s-1] = 1;
  int cur;

  while(!q.empty())
  {
    cur = q.front();
    q.pop();
    for(int i = 0 ; i < ne[cur].size(); i++)
    {
      int nextV = ne[cur][i];
      if(!used[nextV])
      {
        q.push(nextV);
        used[nextV] = 1;
        dist[nextV] = dist[cur] + 1;
        parent[nextV] = cur;
      }
    }
  }

  for(int i = 0 ; i < n; i++)
    printf("%d ", parent[i]);

  printf("\n");

  for(int i = 0 ; i < n; i++)
      printf("%d ", dist[i]);

  printf("\n");
  return 0;

}
