#include <stdio.h>
#include <string.h>
#include <vector>

#define MAXN 1024
#define NO_PARENT -1

using namespace std;

vector<int> used;
vector < vector < int > > g;
int n;
bool ok;
void dfs(int v)
{
  if(ok) return;
  used[v] = 1;
  for(int i = 0; i < g[v].size(); i++)
  {
    int u = g[v][i];
    if(used[u])
      ok = true;
    else
      dfs(u);
  }
}

void solve()
{
  ok = false;
  scanf("%d", &n);
  g.clear();
  g.resize(n);
  used.assign(n, 0);
  for(int i = 0; i < n; i++)
  {
    int Mi;
    scanf("%d", &Mi);
    for(int j = 1; j <= Mi; j++)
    {
      int x;
      scanf("%d", &x);
          g[i].push_back(x - 1);
    }
  }
  for(int i = 0; i < n; i++)
    if(!used[i])
      dfs(i);

}

int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    solve();
    if(ok) printf("Case #%d: Yes\n", i);
    else  printf("Case #%d: No\n", i);
  }
}
