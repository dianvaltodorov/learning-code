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
vector < int > color;
vector < int > time_in, time_out;
vector < int > p;
int dfs_timer = 0;
int to;


void init(int n)
{
  time_in.resize(n);
  time_out.resize(n);
  color.resize(n);
  p.resize(n);
  g.resize(n);
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

void dfs(int v)
{
  printf("%d ", v + 1);
  time_in [v] = dfs_timer++;
  color [v] = 1;
  for(int i = 0; i < g[v].size(); i++)
  {
    to = g[v][i];
    if(color[to] == 0)
    {
      p[to] = v;
      dfs(to);
    }
  }
  color[v] = 2;
  time_out[v] = dfs_timer++;
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
