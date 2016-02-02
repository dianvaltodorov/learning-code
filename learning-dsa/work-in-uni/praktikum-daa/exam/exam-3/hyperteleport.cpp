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
char names[1000][50];
int g[1000][1000];
int n, m, k;


int calculatePrice(char x[], char y[])
{
  int i = 0;
  while(i < m && x[i] == y[i])
    i++;

  if(i == m) return 1;
  else
  {
    int price = 0;
    i = m;
    while(i < k)
    {
      if(x[i]!=y[i]) price++;
      i++;
    }
    return price + m;
  }
}

void printAdjMat()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", g[i][j]);
    printf("\n");
  }
}

int main()
{
  scanf("%d%d%d", &n,&m,&k);
  for(int i = 0; i < n; i++)
    scanf("%s",  names[i]);

  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      int price =  calculatePrice(names[i], names[j]);
      g[i][j] = price;
      g[j][i] = price;
    }
  }

  // printAdjMat();

  int s = 0;
  int MST = 0;
  vector<bool> used (n);
  vector<int> min_e (n, INT_MAX);
  min_e[0] = 0;
  for (int i=0; i < n; ++i) {
  	int v = -1;
  	for (int j=0; j < n; ++j)
  		if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
  			v = j;

  	if (min_e[v] == INT_MAX) {
  		break;
  	}
    MST += min_e[v];
  	used[v] = true;
  	for (int to=0; to<n; ++to)
  		if (g[v][to] < min_e[to]) {
  			min_e[to] = g[v][to];
  		}
  }
  printf("%d\n", MST);
  return 0;
}
