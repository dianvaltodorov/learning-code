#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
int n, m;
int queenX, queenY;
int topX, topY;
int knightX, knightY;

int distance[1<<10];
int table[1<<10][1<<10];

int iMove[8] = {2, 1, -1, -2, -2, -1,  1,  2 };
int jMove[8] = {1, 2,  2,  1, -1, -2, -2, -1 };

bool isNewPositionValid(int i, int j)
{
  return (i > 0 && i < n && j > 0 && j < m && table[i][j] == 0);
}

bool isHit(int i, int j)
{
  return table[i][j]==2;
}

void bfs(int i, int j)
{
  queue < pair <int , int> > q;
  q.push(make_pair(i ,j));
  int level = 0;
  while(!q.empty())
  {
    pair<int , int> currentPos = q.front();
    if(isHit) break;
    q.pop();
    for(int k = 0; k < 8; k++)
    {
      int newI = currentPos.first + iMove[i];
      int newJ = currentPos.second + jMove[i];

      if(isNewPositionValid(newI, newJ))
      {
        table[newI][newJ] = level;
        q.push(make_pair(newI, newJ));
      }
    }
    level++;
  }
}

void printTable()
{
  
}
int main()
{
  scanf("%d %d", &n, &m);
  scanf("%d %d", &queenX, &queenY);
  scanf("%d %d", &topX, &topY);
  scanf("%d %d", &knightX, &knightY);
  table[queenX][queenY] = -2;
  table[topX][topY] = -1;
  table[knightX][knightY] = -2;
  bfs(knightX, knightY);
}
