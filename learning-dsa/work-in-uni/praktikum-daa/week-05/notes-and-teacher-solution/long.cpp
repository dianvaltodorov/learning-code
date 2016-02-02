int dfs(int x)
{
  vis[x] = 1;
  list[x] = b;

  for(int  i = 0; i < neiCount[x]; ++i)
  {
    y = neiVal[x][i];
    dy = neiDist[x][i];
    if(!vis[y])
      dfs(y);
    if(dist[x] < dy + dist[y])
      dist[x] =  dx + dist[y];
  }
}

int dfs(int x)
{
  vis[x] = 1;
  list[x] = b;

  for(int  i = 0; i < neiCount[x]; ++i)
  {
    y = neiVal[x][i];
    dy = neiDist[x][i];
    if(!vis[y])
      dfs(y);
  }

  for(int i = 0; i < neiCount[x]; ++i){
    x = neiVal[x][i];
    dy = newDist[x][i];
    if(dist[x] < dist[y] + dy)
      dist[x] = dist[y] + dy;
  }
}

s
