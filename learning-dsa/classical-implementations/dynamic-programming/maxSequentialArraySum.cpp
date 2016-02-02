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
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++)
  {
    int n;
    cin >> n;
    vector <int> s(n, 0);
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    s[0] = a[0];
    int currentSum = 0;
    int macSequentialSum = 0;
    for(int i = 1; i < n; i++)
    {
      s[i] = max(s[i - 1], s[i - 1] + a[i]);a
    }
    cout << s[n-1] << endl;
  }
}
