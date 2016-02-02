#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
/*
7 8
3
1 2
1 4
2 6
2 7
2 5
3 5
4 7
6 7
*/
int s;
vector < vector < int > > g;
int n, m;
vector < int > p;
vector < int > used;
int dfs_timer = 0;
int to;

void init(int n)
{
  g.resize(n);
  used.resize(n);
  p.resize(n);
}

void input()
{
  scanf("%d" , &n);
  scanf("%d" , &m);
  scanf("%d" , &s);
  s--;
  int x, y;
  init(n);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d" , &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}

void dfs (int v) {
  printf("%d ", v + 1);
	used [v] = 1;
  for(int i = 0; i < g[v].size(); i++)
  {
    to = g[v][i];
    if(!used[to])
      dfs(to);
  }
}

void printGraph()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d: ", i + 1);
    for(int j = 0; j < g[i].size(); j++)
      printf("%d ", g[i][j] + 1);
    printf("\n");
  }
}

int main()
{
  input();
  dfs(s);
  printf("\n");
  return 0;
}
