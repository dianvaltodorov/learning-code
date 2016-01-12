#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;
/*
7 8
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
vector < int > time_in, time_out;
vector < int > used;
int dfs_timer = 0;
int to;
int cycle_st, cycle_end;

void input()
{
  scanf("%d" , &n);
  scanf("%d" , &m);
  int x, y;
  g.resize(n);
  used.resize(n);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d" , &x, &y);
    x--;
    y--;
    g[x].push_back(y);
//    g[y].push_back(x);
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

bool dfs(int x) {
    int to;
    used[x] = true;
    for (int i = 0; i < g[x].size(); ++i) {
        to = g[x][i];
        if (used[to])
            return true;
        if (dfs(to))
            return true;
    }
    return false;
}

int main()
{
  input();
  printf("%d\n", dfs(1));
  printGraph();
  cin>>n;
  return 0;
}
