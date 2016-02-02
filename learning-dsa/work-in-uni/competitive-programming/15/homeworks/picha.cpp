#include<iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string.h>
#define MAXN 1 << 10
#define NO_PARENT -1
using namespace std;

vector < vector < pair < int , double> > > ne;
int path[MAXN];
double total;
double w;
int t, n, m, b, e;
int x, y;
int used[MAXN];
double dist[MAXN];
int parent[MAXN];
int length;

void input()
{
  scanf("%d %d", &n, &m);
  scanf("%d %d", &b, &e);
  ne.resize(n);
  for(int i = 1; i <= m; i++)
  {
    scanf("%d %d %lf", &x, &y, &w);
    ne[x - 1].push_back(make_pair(y - 1, w));
  }
}

void printDist()
{
  for(int i = 0; i < n; i++)
    printf("%lf ", dist[i]);
  printf("\n");
}

void printParent()
{
  for(int i = 0; i < n; i++)
    printf("%d ", parent[i]);
  printf("\n");
}

void dfs(int i)
{
  printf("Yolo");
  used[i] = 1;
  for(int k = 0; k < ne[i].size(); k++)
  {
    int neighbour = ne[i][k].first;
    double weight = ne[i][k].second;
    if(!used[neighbour])
    {
      parent[neighbour] = i;
      dist[neighbour] = dist[i] + weight;
      dfs(neighbour);
    }
  }
}
void printPath(int j)
{
  int k = 0;
  while(parent[j] != NO_PARENT)
  {
    path[k++] = j;
    j = parent[j];
  }
  if(j == b - 1)
  {
    printf("%d %.3lf\n", k + 1, dist[e - 1]);
    for(int i = k; i >= 0; i--)
    {
      printf("%d ", path[i] + 1);
    }
    printf("\n");
  }
  else
  {
    printf("-1\n");
  }
}

void solve()
{
  memset(used, 0, sizeof(used));
  memset(parent, 0, sizeof(parent));
  memset(dist, 0, sizeof(dist));
  ne.clear();
  for(int i = 0;  i < n; i++)
    parent[i] = NO_PARENT;

  dfs(b - 1);
  printDist();
  printParent();
  // printPath(e - 1);
}

int main()
{
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    input();
    solve();
  }
}
