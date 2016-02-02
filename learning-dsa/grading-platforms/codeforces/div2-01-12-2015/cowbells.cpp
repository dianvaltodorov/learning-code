#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
int n, k;
const int MAXN = 100001;
int s[MAXN];
void input()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &s[i]);
}
bool f(int x)
{
  int i = 0;
  int j = n - 1;
  int leftK = k;
  while (i <= j)
  {
    if(s[i] + s[j] <= x)
    {
      i++;
      j--;
    }
    else
    {
      j--;
    }
    leftK--;
  }
  // printf("leftK = %d\n", leftK);
  return leftK == 0;
}
int solve()
{
  int b = s[n - 1];
  int e = s[n - 1] + s[n - 2];
  int m;
  while(e - b > 1)
  {
    m = (b + e + 1)/2;
    printf("%d %d %d\n", b, m , e);
    if(f(m))
    {
      e = m;
    }
    else
    {
      b = m;
    }
  }
  return m;
}

int main()
{
  input();
  // cout << isPossible(18) << endl;
  // cout << isPossible(17) << endl;
  // cout << isPossible(16) << endl;
  // cout << isPossible(15) << endl;
  // cout << f(5) << endl;
  // cout << f(6) << endl;
  // cout << f(7) << endl;

  cout << solve() << endl;
}
