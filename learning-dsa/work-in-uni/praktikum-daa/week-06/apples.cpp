#include <stdio.h>
#include <string.h>
#include <queue>
#define MAXN 1001
using namespace std;

int dirI[4] = {1, -1 , 0, 0};
int dirJ[4] = {0,  0,  1, -1};
int mat[MAXN][MAXN];

int main()
{
  int x, y, n, m, t, newI, newJ, a = 0;
  pair < int , int > current;
  queue < pair <int, int> > q;
  scanf("%d %d %d", &n, &m, &t);
  scanf("%d %d", &x, &y);
  q.push(make_pair(x, y));
  mat[x][y] = 1;
  ++a;
  if(scanf("%d %d", &x, &y) != EOF)
  {
    q.push(make_pair(x, y));
    mat[x][y] = 1;
    ++a;
  }

  while(!q.empty())
  {
    current = q.front();
    q.pop();
    if(mat[current.first][current.second] > t) continue;
    for(int i = 0; i < 4; i++)
    {
      newI = current.first + dirI[i];
      newJ = current.second + dirJ[i];
      if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && !mat[newI][newJ])
      {
        q.push(make_pair(newI, newJ));
        mat[newI][newJ] = mat[current.first][current.second] + 1;
        a++;
      }
    }
  }

  printf("%d\n", n * m - a);
}
