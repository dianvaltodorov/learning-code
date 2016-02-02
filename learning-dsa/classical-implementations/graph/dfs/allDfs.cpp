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

vector < vector < int > > g;
vector < path > 
int n,m,s,f;

void input()
{
  scanf("%d%d%d%d",&n,&m,&s,&f);
  int x, y;
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d", &x, &y);
    g[y - 1].push_back(x - 1);
    g[x - 1].push_back(y - 1);
  }
}

void printPath()
{

}
void allDfs(int s, int f)
{
  if(s == f)
  {
    printPath();
  }
}

int main()
{
  input();
  allDfs();

}
