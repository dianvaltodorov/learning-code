#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#define MAXN 1001

using namespace std;
int n, t, x, y;

vector < vector < int > > ne;
bool used[MAXN], ok;

void input()
{

    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    ne.resize(n);
    while(x != 0 && y != 0)
    {
        ne[x - 1].push_back(y - 1);
        scanf("%d %d", &x, &y);
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
    ne.clear();
    clearUsed();
}

void printNe()
{
    for(int i = 0; i < n; i++)
    {
        printf("\n%d:\n\t", i + 1);
        for(int j = 0 ; j < ne[i].size(); j++)
            printf("%d ", ne[i][j] + 1);
    }
}

void dfs(int i)
{
    used[i] = true;
    for(int j = 0 ; j < ne[i].size(); j++)
    {
        if(!(used[ne[i][j]]))
        {
            dfs(ne[i][j]);
        }
    }
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
        //printUsed(i + 1);
       // printf("\n");
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
        input();
      //  printNe();
      //  printf("\n");
        solve();
        clearInput();
    }
}
