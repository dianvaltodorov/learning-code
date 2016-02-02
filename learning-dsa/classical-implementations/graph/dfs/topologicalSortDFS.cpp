#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>

using namespace std;

int n, m;
vector < vector <int> > g;
vector < bool > used;
stack <int> st;

void input()
{
  scanf("%d" , &n);
  scanf("%d" , &m);
  g.resize(n);
  used.resize(n);
  int x, y;
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d" , &x, &y);
    x--;
    y--;
    g[x].push_back(y);
  }
}

void dfs (int v) {
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	st.push(v);
}

void topological_sort() {
	for (int i=0; i < n; ++i)
		if (!used[i])
			dfs (i);
  while(!st.empty())
  {
    printf("%d ", st.top() + 1);
    st.pop();
  }

  printf("\n");
}

int main()
{
  input();
  topological_sort();

}
