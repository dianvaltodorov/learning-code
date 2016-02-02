#include <iostream>
using namespace std;
int n;
int m;
int a[1<<10][1<<10];
int u, v, w;
int q;
const int INF = 1<<20;
int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    a[u - 1][v - 1] = w;
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      a[i][j] = a[i][j] ? a[i][j] : INF;

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(a[i][k] + a[k][j] < a[i][j]){
            a[i][j] = a[i][k] + a[k][j];
        }

  // for(int i = 0; i < n; i++)
  // {
  //     for(int j = 0; j < n; j++)
  //       cout << a[i][j] << " ";
  //   cout << endl;
  // }
  for(int i = 0; i < n; i++) a[i][i] = 0;
  cin >> q;
  for(int i = 0; i < q; i++)
  {
    cin >> u >> v;
    if(a[u-1][v-1] == INF) cout << "-1"<<endl;
    else cout << a[u - 1][v -1] << endl;
  }
}
