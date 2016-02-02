#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[1<<20];
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vector < int > s(n, 0);
    s[0] = a[0];
    for(int i = 1; i < n; i++)
    {
      s[i] = max(s[i-1], s[i-1] + a[i]);
    }

    int maxS = 0;
    int curS = 0;
    int maxEl = a[0];
    for(int i = 0; i < n; i++)
    {
      maxEl = max(maxEl, a[i]);
      curS += a[i];
      if(curS < 0)
        curS = 0;

      if(maxS < curS)
        maxS = curS;
    }

    if(maxS <= 0) cout << maxEl << " ";
    else cout << maxS << " ";
    cout << s[n - 1] << endl;
  }
}
