#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector < vector <int > > g(n, vector <int> (n));
  for(size_t i = 0; i < n; i++)
    for(size_t j = 0; j < n; j++)
      cin >>g[i][j];

  // for(size_t i = 0; i < n; i++)
  // {
  //   for(size_t j = 0; j < n; j++)
  //     cout << g[i][j] << " ";
  //   cout << endl;
  // }
  int mainD = 0;
  int secondD = 0;

  for(size_t i = 0; i < n; i++)
  {
    mainD += g[i][i];
    secondD += g[i][n - 1 - i];
  }
  cout << abs(mainD - secondD) << endl;
  return 0;
}
