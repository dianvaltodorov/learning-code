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

int a[1<<10];
unsigned long long dyn[1<<10][1<<10];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++)
  {
    cin >> a[i];
  }

  for(int j = 0; j < m; j++)
  {
    dyn[0][j] = 1;
  }

  for(int i = 1; i <= m; i++)
  {
    for(int j = 0; j <= n; j++)
    {
      if(j < a[i])
        dyn[i][j] = dyn[i - 1][j];
      else
        dyn[i][j] = dyn[i - 1][j] + dyn[i - 1][j - a[i]];
    }
  }

  for(int k = 0; k <= m; k++)
  {
    for(int r = 0; r <= n; r++)
      cout << " " << dyn[k][r] << " ";
    cout << endl;
  }
  cout << dyn[m][n] << endl;
  return 0;

}
