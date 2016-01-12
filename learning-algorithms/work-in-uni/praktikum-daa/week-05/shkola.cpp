#include<iostream>
#include<vector>
#include<stdio.h>
#define MAXN 1<<9

int n, m, x, y;
using namespace std;
vector < vector < int > > ne;
int used[MAXN];

void dfs(int i)
{
  used[i] = 1;
  for(int k = 0; k < ne[i].size(); k++)
  {
    int cur = ne[i][k];
    if(!used[cur])
    {
      dfs(cur);
    }
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  ne.resize(n);
  for(int i = 1; i <= m; i++)
  {
    scanf("%d %d", &x, &y);
    ne[x - 1].push_back(y - 1);
  }
  int br = 0;
  for(int i = 0; i < ne.size(); i++)
  {
    if(!used[i])
    {
      dfs(i);
      br++;
    }
  }
  printf("%d\n", br);
}
