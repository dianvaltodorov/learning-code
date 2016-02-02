#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>

using namespace std;

struct Edge{
  int to, from;
  double w;
  Edge(int x,int y,double z):to(x), from(y), w(z){};
};


int last;
int n;
int m;
int total;
vector< vector < pair < int, double> > > ne;
double a[1000][1000];
bool used[5000];






























































































































































































































































































































































































































void dfs(int i)
{
    if(i == last) return;
    else
    {
        for(int k = 0; k <= m; k++)
        {
         /*   if(!used[k] && areConnected(i, k))
            {
                used[k] = true;
                total += pathBetween(i, k);
                dfs(k);
                used[k];
            }*/
        }

    }
}

/*
struct Edge{
  int to, from;
  double w;
  Edge(int x,int y,double z):to(x), from(y), w(z){};
}
*/

int main()
{
    int t;
    //scanf("%d", &t);

    int n; // number of vertexes
    int m; // numbers of edges
    int first; // starting vertex
    int last;  // ending vertex
    int x;
    int y;
    double z;
    /*for(int i = 1; i <= t; i++)
    {

        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &first);
        scanf("%d", &last);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &x);
            scanf("%d", &y);
            scanf("%lf", &z);
            ne[x].push_back(make_pair(y,z));
        }
    }*/
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%lf", &z);
    ne[x].push_back(make_pair(y, z));
    return 0;
}
