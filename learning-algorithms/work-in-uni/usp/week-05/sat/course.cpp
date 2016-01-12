#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#define MAXN 1001

using namespace std;
int t, n, x, y;
bool a[MAXN][MAXN];
bool used[MAXN];
bool ok;

void input()
{
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    while(x !=0 && y != 0)
    {
        a[x - 1][y - 1] = true;
        scanf("%d %d", &x, &y);
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
        used[i] = false;
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
            a[i][j] = false;
}
bool check()
{
    for(int i = 0; i < n ; i++)
    {
        if(!(used[i])) return false;
    }
    return true;
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
    for(int i = 1; i <= t; i++)
    {
        clearInput();
        input();
        solve();
    }
    return 0;
}
