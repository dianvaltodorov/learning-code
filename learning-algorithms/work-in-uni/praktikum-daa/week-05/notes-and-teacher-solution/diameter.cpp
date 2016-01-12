/*
1 решение - пускаме дфс от всички върхове и от тях отсяваем

От произволно листо пускаме дфс и намираме най отдалечения връх от него.
След това от това листо пускаме дфс

*/

#include<iostream>
#include<stdio.h>
#include <cstring>
using namespace std;
const int N = 1 << 10;//1024
int n;
int neiCount[N];
int neiDist[N][N];
int neiVal[N][N];
int vis[N];
int dist[N];
int maxDist;
int maxVert;

void edge(int x, int y, int d)
{
    neiDist[x][neiCount[x]] = d;
    neiVal[x][neiCount[x]] = y;
    neiCount[x]++;
}

int input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        --x;
        --y;
        edge(x, y, d);
        edge(y, x, d);
    }
}

void dfs(int x, int d)
{
    int y, dy;
    vis[x] = false;
    dist[x] = d;
    if(maxDist < d)
    {
        maxDist = d;
        maxVert= x;
    }
    for(int i = 0; i < neiCount[x]; i++)
    {
        y = neiVal[x][i];
        dy = neiDist[x][i];
        if (!vis[y])
        {
            dfs(y, d + dy);
        }
    }
}

void solve()
{
    for(int i = 0; i < n; ++i)
    {
        if(neiCount[i] == 1)
        {
            dfs(i, 0);
            break;
        }
    }
    maxDist = 0; // ресетваме
    memset(vis, 0, sizeof(vis));
    /*
    for(int i = n; i < n; i++)
    {
        vis[i] = 0;
    }
    */
    dfs(maxVert, 0);
    printf("%d\n",maxDist);
}
int main()
{
    input();
    solve();
    return 0;
}
