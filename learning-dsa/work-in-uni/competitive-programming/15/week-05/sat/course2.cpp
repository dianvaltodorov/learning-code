#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#define MAXN 1001

using namespace std;
int t, n, x, y;
int a[1001][1001];
bool used[MAXN];
bool ok;

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &x, &y);
        a[x - 1][y - 1] = 1;
    }
}

void dfs(int i)
{
    used[i] = true;
    for(int j = 0; j < n; j++)
        if(a[i][j] && !(used[j]))
        {
            dfs(j);
        }
}

void clearUsed()
{
    ok = false;

    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
    }
}
void clearInput()
{

    ok = false;

    for(int i = 0; i < n; i++)
    {
        used[i] = false;
    }

   for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 0;
}
bool check()
{
    bool res = true;
    for(int i = 0; i < n ; i++)
    {
        res = res && used[i];
    }
    return res;
}

void printUsed(int x)
{
    printf("For %d:\n\t", x);
    for(int i = 0; i < n; i++)
    {
       printf("%d ", used[i]);
    }
    printf("\n");
}
void solve()
{
    int i;

    for(i = 0 ; i < n; i++)
    {
        clearUsed();
        dfs(i);
      // printUsed(i);
        if(check())
        {
            ok = true;
            break;
        }
    }
    if(ok) printf("%d\n", (i + 1));
    else printf("NO\n");
}
int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
      clearInput();
      input();
      scanf("%d %d", &x, &y);
      solve();
    }
    return 0;
}
