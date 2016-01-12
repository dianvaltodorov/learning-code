#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
long long d1, d2, d3;

int main()
{
  long long r[10];
  cin >> d1 >> d2 >> d3;
  long long ans = r[0];
  r[0] = d1 + d2 + d3;
  r[1] = 2 * d1 + 2 * d2;
  r[2] = 2 * d1 + 2 * d3;
  r[3] = 2 * d2 + 2 * d3;
  for(int i = 1; i < 4; i++)
    if(ans > r[i]) ans = r[i];

  cout << ans << endl;
  return 0;
}
