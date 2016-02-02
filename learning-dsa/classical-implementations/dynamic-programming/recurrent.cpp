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

int main()
{
  unsigned long long a;
  unsigned long long b;
  int n;
  cin >> a >> b >> n;

  vector<unsigned long long> dyn(32);
  dyn[0] = a;
  dyn[1] = b;
  for(int i = 2; i < n; i++)
  {
    dyn[i] = dyn[i-1] * dyn[i - 1] + dyn[i - 2];
  }
  cout << dyn[n - 1] << endl;
}
