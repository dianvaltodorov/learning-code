#include <stdio.h>
#include <queue>
#include <stack>
#include <string.h>
#define MAXN 1 << 11
#define MAXM 1 << 11

using namespace std;
int t, n, m, q, x, y;
char city[MAXN][MAXM];

int startI, startJ;
int dist[MAXN][MAXM];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void setUp()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(city[i][j] == 'H')
      {
        dist[i][j] = 0;
        startI = i;
        startJ = j;
      }
      else
      {
        dist[i][j] = -1;
      }
}
void bfs(int x, int y)
{
  int i, j;
  pair < int , int> current;
  queue < pair < int, int > > q;
  q.push(make_pair(x, y));
  while(!q.empty())
  {
    current = q.front();
    q.pop();
    for(int k = 0; k < 4; k++)
    {
      i = current.first + dx[k];
      j = current.second + dy[k];
      if(i >= 0 && i < n && j >= 0 && j < m && dist[i][j] == -1 && city[i][j] == '.')
      {
        q.push(make_pair(i, j));
        dist[i][j] = dist[current.first][current.second] + 1;
      }
    }
  }
}
void printDist()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
      printf("%3d ", dist[i][j]);
    printf("\n");
  }
}
void solve()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%s", city[i]);
  }
  setUp();
  bfs(startI, startJ);
  // printDist();
  scanf("%d", &q);
  for(int i = 1; i <= q; i++)
  {
    scanf("%d %d", &x, &y);
    printf("%d\n", dist[x-1][y-1]);
  }
}

int main()
{
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    solve();
  }
}
