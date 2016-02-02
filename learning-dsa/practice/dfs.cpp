#include <iostream>
#include <vector>
using namespace std;
vector < vector < int > > g;

vector <int> inT;
vector <int> used;
vector <int> outT;
int n, m;
int x, y;

int counter = 0;

void dfs(int v)
{

  used[v] = 1;
  inT[v] = counter++;
  for(int i = 0; i < g[v]. size(); i++)
  {
    int u = g[v][i];
    if(!used[u])
    {
      dfs(u);
    }
  }
  outT[v] = counter++;
}
int main()
{
  cin >> n >> m;
  used.assign(n, 0);
  g.resize(n);
  
  inT.resize(n);
  outT.resize(n);

  for(int i = 0; i < m; i++)
  {
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  int s = 1;
  dfs(s - 1);
  for(int i = 0; i < n; i++)
  {
    cout << "Vertex|In time: " << inT[i]<< " rOut time: " << outT[i] << endl;
  }


}
