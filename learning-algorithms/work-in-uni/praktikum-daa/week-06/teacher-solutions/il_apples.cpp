int main()
{
  scanf("%d %d %d", &n, &m, &t);
  scanf("%d %d", &x, &y)
  q.push(make_pair(x, y));
  int a = 0;
  visited[x][y] = 1;
  ++a;
  if(scanf("%d %d", x, y) != EOF)
  {
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    ++a;
  }

  while(!q.empty())
  {
    pair <int, int> top = q.front();
    q.pop();
    if(visited[top.first][top.second] > t) continue;
    for(int i = 0; i < 4; ++i)
    {
      x = top.first + dir[i][0];
      y = top.second + dir[i][1];
      if(x >= 1 && x <= n && y >= 1 && y <=m && !visited[x][y])
      {
        q.push(make_pair(x, y));
        visited[x][y] = visited[top.first][top.second] + 1;
        ++a;
      }
    }
  }
  printf("%d\n",n * m - a);
}
