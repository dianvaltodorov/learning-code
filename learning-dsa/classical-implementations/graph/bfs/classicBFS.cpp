#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#define MAXN 1000
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
vector<bool> used (MAXN);
vector<int> d (MAXN);
vector<int> p (MAXN);

int n, m;

void input()
{
  scanf("%d" , &n);
  scanf("%d" , &m);
  scanf("%d" , &s);
  s--;
  int x, y;
  g.resize(n);
  p.resize(n);
  used.resize(n);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d" , &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}


void bfs()
{
  queue<int> q;
  q.push (s);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) {
  	int v = q.front();
  	q.pop();
  	for (size_t i=0; i<g[v].size(); ++i) {
  		int to = g[v][i];
  		if (!used[to]) {
  			used[to] = true;
  			q.push (to);
  			d[to] = d[v] + 1;
  			p[to] = v;
  		}
  	}
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

void printDistances()
{
  printf("The distance:\n");
  for(int i = 0; i < n; i++)
    printf("  from %d to %d is %d\n", s, i, d[i]);
}

int main()
{
  input();
  bfs();
  printDistances();
  return 0;
}
