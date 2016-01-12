#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#include<string.h>

using namespace std;
const int MAXN = 1000;
int t;
int n;
vector < int > ne[MAXN];
int mi, x;
bool ok;
int used[MAXN];

void dfs(int i)
{
  if(ok) return;
  if(used[i]) {ok = true; return;}
  used[i] = 1;
  for(int j = 0 ; j < ne[i].size(); j++)
    dfs(ne[i][j]);
}


int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
      scanf("%d", &n);
      for(int j = 0; j < n; j++)
      {
        scanf("%d", &mi);
        for(int k = 1; k <= mi; k++)
        {
          scanf("%d", &x);
          ne[j].push_back(x - 1);
        }
      }

      for(int j = 0; j < n; j++)
        if(!used[j]) dfs(j);

      printf("Case #%d: %s\n", i + 1, (ok ? "Yes" : "No"));
      ok = false;
      memset(used, 0 , sizeof(used));
      memset(ne, 0 ,sizeof(ne));
    }
}
