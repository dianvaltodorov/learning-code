#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXN 1000

using namespace std;
int n, m, all;
int dyn[MAXN];
int pr[MAXN];

void input()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &pr[i]);
}

void solve()
{
  for(int i = 0; i < n; i++)
    all += pr[i];

  dyn[0] = 1;
  for(int i = 0; i < n; i++)
    for(int j = all; j >= 0; j--)
      if(dyn[j] == 1) dyn[j + pr[i]] = 1;

  int i = all / 2;
  while(i >= 0 && !dyn[i]) i--;
  printf("%d\n", i);
}

void printDyn() {
  for(int i = 0; i <= all; i++)
    printf("%d ", dyn[i]);
  printf("\n");
}


int main()
{
  input();
  solve();
  printDyn();
  return 0;
}
