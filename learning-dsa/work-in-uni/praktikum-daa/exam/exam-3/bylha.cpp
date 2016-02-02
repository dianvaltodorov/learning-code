#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;
int a[1501][1501];
int n;
int dyn[1500][1500];
//
/*4
0 1 1 1
0 1 0 0
1 0 1 1
1 0 1 1
*/
void printDyn()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", dyn[i][j]);
    printf("\n");
  }
}


int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  dyn[0][0] = 1;
  for(int i = 1; i < n; i++)
    if(!((dyn[0][i - 1]  + a[0][i]) % 2 == 1)) dyn[0][i] = dyn[0][i-1] + 1;
    else dyn[0][i] = dyn[0][i-1] + 2;

  for(int j = 1; j < n; j++)
      if(!((dyn[j - 1][0]  + a[j][0]) % 2 == 1)) dyn[j][0] = dyn[j - 1][0] + 1;
      else dyn[j][0] = dyn[j - 1][0] + 2;

  for(int i = 1; i < n; i++)
    for(int j  = 1; j < n; j++)
    {
      int above = (!((dyn[i - 1][j]  + a[i][j]) % 2 == 1)) ?  dyn[i - 1 ][j] + 1 : dyn[i - 1][j] + 2;
      int left = (!((dyn[i][j - 1]  + a[i][j]) % 2 == 1)) ?  dyn[i][j - 1] + 1 : dyn[i][j-1] + 2;
      dyn[i][j] = min (above, left);
    }

  printf("%d\n", dyn[n-1][n-1]);
  // printDyn();

}
