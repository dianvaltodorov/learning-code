#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

int pv[6] = {500, 1000, 1500, 2000, 2500};
int m[6];
int w[6];
int hs;
int hu;
int res =0;

void input()
{
  for(int i = 0; i < 5; i++)
    scanf("%d", &m[i]);

  for(int i = 0; i < 5; i++)
      scanf("%d", &w[i]);
  scanf("%d %d", &hs, &hu);

}

int getScore(int i)
{
  int a = 0.3 * pv[i];
  int b = ((250 - m[i]) * pv[i]) / 250 - 50 * w[i];
  // printf("%d\n", max(a, b));
  return max(a, b);
}
void solve()
{
  for(int i = 0; i < 5; i++)
    res += getScore(i);
  res += hs * 100;
  res -= hu * 50;
  printf("%d\n" , res);
}
int main()
{
  input();
  solve();
}
