#include <stdio.h>
using namespace std;
#define MAXN 2024
int n, m, k, x, y, ex, ey;
int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2 };
int YMove[8] = {1, 2,  2,  1, -1, -2, -2, -1 };
int table[MAXN];

int main()
{

  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &x, &y);
    table[x-1][y-1] = 1;
  }
  for(int i = 0; i < k; i++)
  {
    scanf("%d %d", &x, &y);
  }
    scanf("%d %d", &eX, &eY);

}
