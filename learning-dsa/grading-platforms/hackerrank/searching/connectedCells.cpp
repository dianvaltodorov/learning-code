#include <iostream>

using namespace std;
int a[1<<10][1<<10];
int n, m;

int maxCover = 0;
int ys[8] = {1, -1,  1, -1, 1, 0, -1, 0};
int xs[8] = {1, -1, -1,  1, 0, 1, -1, 0};

void dfs(int x, int y, int sum)
{
  //  cout << a[x][y] << " " << x << " " << y << endl;
  if(maxCover < sum + 1)
  {
    maxCover = sum + 1;
  }
  a[x][y] = 0;
  for(int i = 0; i < 8; i++)
  {
    int newX = x + xs[i];
    int newY = y + ys[i];
    if( newX >= 0 || newX < n || newY >= 0 || newY  < m)
      if(a[newX][newY])
      {
        dfs(newX, newY, sum + 1);
      }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> a[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      {
        if(a[i][j]) dfs(i, j, 1);
      }

  cout << maxCover << endl;

}
