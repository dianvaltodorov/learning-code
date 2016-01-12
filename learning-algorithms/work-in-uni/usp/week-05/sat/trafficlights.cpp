#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
int t, n, m, g, r, x, y, w;
vector < vector < pair < int , int > > > ne;
vector< pair <int, int> > times;
int MAX_VALUE;
int NO_PARENT;
int s = 1;
void printNe()
{
    for(int i = 0; i < n; i++)
    {
        printf("\n%d:\n\t", i + 1);
        for(int j = 0 ; j < ne[i].size(); j++)
            printf("(%d %d - > %d)", i + 1, ne[i][j].first + 1, ne[i][j].second);
    }
}


void input()
{
    scanf("%d %d", &n, &m);
    ne.resize(m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        ne[x - 1].push_back(make_pair(y - 1, w));
        ne[y - 1].push_back(make_pair(x - 1, w));
    }
    times.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &g, &r);
        times.push_back(make_pair(g, r));
    }
}

int d[MAXN];
int t[MAXN];

void dijkstra()
{
    for(int i = 0; i < n; i++) d[i] = MAX_VALUE;
    for(int i = 0; i < ne[s].size(); i++)
    {
        d[ne[s][i].first]  = ne[s][i].second;
    }

    pred[s] = NO_PARENT;
    d[s] = 0;
    T[s] = 0;

    while(1)
    {


    }

}
void solve()
{

}
int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
      input();
      solve();

    }
}
