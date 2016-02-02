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
int t, n, m, x, y, b, e;
double w, dist[MAXN];
vector < vector < pair < int , double > > > ne;
int used[MAXN];
int parent[MAXN];

void input()
{
  memset(used, 0 , sizeof(used));
  memset(parent, 0 , sizeof(parent));
  memset(dist, 0 , sizeof(dist));
  for(int i = 0;  i < n; i++)
    parent[i] = NO_PARENT;
    
  scanf("%d %d", &n, &m);
  scanf("%d %d", &b, &e);
  ne.clear();
  ne.resize(n);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d %lf", &x, &y, &w);
    ne[x - 1].push_back(make_pair(y - 1, w));
  }
}

void dfs(int i)
{
  used[i] = 1;
  for(int k = 0; k < ne[k].size(); k++)
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

void solve()
{
  dfs(b - 1);
  printDist();
  printParent();
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
