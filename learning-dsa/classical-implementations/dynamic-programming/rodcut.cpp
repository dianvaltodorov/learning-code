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

int dyn[1<<10][1<<10];
int price[1<<10];

int main()
{
  int len;
  cin >> len;
  int n;
  cin >> n;
  for(int i = 1; i < n; i++)
    cin >> price[i];

  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j <= len; j++)
    {
      if (j < i)
        dyn[i][j] = dyn[i - 1][j];
      else
        dyn[i][j] = max(dyn[i - 1][j] , dyn[i][j - i] + price[i]);
    }
  }
  cout << dyn[n][len] << endl;
}
