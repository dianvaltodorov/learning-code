#include <stdio.h>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define MAXN 1000
/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/

const int A[MAXN][MAXN] = {
  { 0, 1, 0, 2, 0, 0, 0, 0, 0},
  { 1, 0, 3, 0, 13, 0, 0, 0, 0},
  { 0, 3, 0, 4, 0, 3, 0, 0, 0},
  { 2, 0, 4, 0, 0, 16, 14, 0, 0},
  { 0, 13, 0, 0, 0, 12, 0, 1, 13},
  { 0, 0, 3, 16, 12, 0, 1, 0, 1},
  { 0, 0, 0, 14, 0, 1, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 0, 0, 0},
  { 0, 0, 0, 0, 13, 1, 0, 0, 0}};

int n = 9;
char used[MAXN];
unsigned prev[MAXN];
int T[MAXN];
int MST = 0;

int main()
{
  // vector < vector < pair <int, int> > >g;
  // int n, m;
  // scanf("%d%d",&n, &m);
  // g.resize(n);
  // for(int i = 0; i < m; i++)
  // {
  //   int x, y, w;
  //   scanf("%d%d%d", &x, &y, &w);
  //   // g[x - 1].push_back(make_pair(y - 1, w));
  //   // g[y - 1].push_back(make_pair(x - 1, w));
  //   g[x - 1][y - 1] = w;
  //   g[y - 1][x - 1] = w;
  // }

  int MST = 0; /* тук трупаме цената на минималното покриващо дърво */
  unsigned i, k;

  for (i = 0; i < n; i++)
  {
    used[i] = 0;
    prev[i] = 0;
  }

  int s = 1;
  used[s] = 1;
  for (i = 0; i < n; i++)
    T[i] = (A[s][i]) ? A[s][i] : INT_MAX;

  for (k = 0; k < n - 1; k++)
  {
    printf("\n");
    for(int idx = 0; idx < n; idx++)
    {
      printf("T[%d] = %d\n" , idx + 1, T[idx]);
    }

    int minDist = INT_MAX;

    int j = -1;
    for (i = 0; i < n; i++)
      if (!used[i])
        if (T[i] < minDist) {
          minDist = T[i];
          j = i;
        }

    used[j] = 1;
    // printf("(%u,%u) ", prev[j] + 1, j + 1);
    MST += minDist;
    for (i = 0; i < n; i++)
      if (!used[i] && A[j][i])
      {
        if (T[i] > A[j][i]) {
          T[i] = A[j][i];
          prev[i] = j;
        }
      }
    }
}
