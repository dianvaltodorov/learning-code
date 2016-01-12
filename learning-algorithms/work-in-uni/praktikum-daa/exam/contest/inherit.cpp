#include <stdio.h>
#include <string.h>
#include <vector>

#define MAXN 1024
#define NO_PARENT -1

using namespace std;

int t, n, mi;
vector < int > ne[MAXN];
int used[MAXN];
bool ok;
int parent[MAXN];

void input()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &mi);
    ne[i].resize(mi);
    for(int j = 0; j < mi; j++)
    {
      scanf("%d\n", &ne[i][j]);
    }
  }
}

void printNe()
{
  for(int i = 0; i < n; i++)
  {
    printf("neighbours of %d:", i);
    for(int j = 0; j < ne[i].size(); j++)
    {
      printf("%d\n", ne[i][j]);
    }
  }
}

void dfs(int i)
{
  if(ok) return;
  used[i] = 1;
  for(int j = 0; j < ne[i].size(); j++)
  {
    int cur = ne[i][j];
    if(used[cur] == 1)
    {
      if(parent[cur] != NO_PARENT)
        parent[cur] = i;
      else
        ok = true;
    }
    else
    {
      used[cur] = 1;
      dfs(cur);
    }
  }
}
void solve()
{
  for(int i = 0 ; i < n; i++)
  {
    dfs(i);
  }
}


void clear()
{
  memset(ne, 0 ,sizeof(ne));
  ok = false;
}

int main()
{
  scanf("%d", &t);
  for(int i = 0; i < t; i++)
  {
    clear();
    input();
    printNe();
    solve();
    if(ok) printf("Case #%d: Yes\n", t);
    else printf("Case #%d: No\n", t);
  }
}
