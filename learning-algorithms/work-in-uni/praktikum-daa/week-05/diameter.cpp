#include<iostream>
#include<vector>
#include<stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1<<9

using namespace std;

vector < vector < pair < int , int > > > ne;
int used[MAXN];
int dist[MAXN];
int n, x, y, d;

void printDist()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", dist[i]);
  }
  printf("\n");
}
void dfs(int i)
{
  used[i] = 1;
  for(int k = 0; k <= ne[i].size(); k++)
  {
    int cur = ne[i][k].first;
    int w = ne[i][k].second;
    if(!used[cur])
    {
      dist[cur] = dist[i] + w;
      dfs(cur);
    }
  }
}

int main()
{

  scanf("%d", &n);
  ne.resize(n);
  for(int i = 1; i < n; i++)
  {
    scanf("%d %d %d", &x, &y, &d);
    ne[x-1].push_back(make_pair(y-1, d));
    ne[y-1].push_back(make_pair(x-1, d));
  }
  dfs(0);
  int maximum = dist[0], midx = 0;
  for(int i = 1; i < n; i++)
    if(dist[i] > maximum)
    {
      maximum = dist[i];
      midx = i;
    }
  memset(dist, 0, sizeof(dist));
  memset(used, 0, sizeof(used));
  dfs(midx);

  maximum = dist[0];
  midx = 0;
  for(int i = 1; i < n; i++)
    if(dist[i] > maximum)
      maximum = dist[i];
  printf("%d\n", maximum);
}
