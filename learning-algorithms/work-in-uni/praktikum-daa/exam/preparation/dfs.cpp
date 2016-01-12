#include <stdio.h>
#include <vector>
using namespace std;

void dfs(int i)
{
  used[i] = 1;
  int cur;

  for(int k = 0; k < ne[i].size(); i++)
  {
    cur = ne[i][k];
    if(!used[cur])
      dfs(cur);
  }
}

int main()
{
  dfs()
}
