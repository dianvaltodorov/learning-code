#include<stdio.h>
#include<algorithm>
#include <string.h>
char s[512];
int t;
int dyn[512][512];

int rec(int a, int b)
{
  if(a == b) return 1;
  if(a > b) return 0;
  if(dyn[a][b] != -1) return dyn[a][b];
  if(s[a] != s[b])
    return dyn[a][b] = max(rec(a+1, b), rec(a, b-1));
  else
    return dyn[a][b] = 2 + rec(a + 1, b -1);
}

string pal(int a, int b)
{
  if(a == b) return "" + s[a];
  if(a > b) return "";
  if(s[a]!=s[b])
  {
    if(rec(a+1, b) >= rec(a, b - 1))
    {
      return pal(a + 1, b);
    }
    else
    {
      return pal(a, b +1);
    }
  }else
  {
    return "" + s[a] + pal(a + 1, b - 1) + s[a];
  }
}
int main()
{
  scanf("%d", &t);
  for(int i = 1; i < t; i++)
  {
    scanf("%s", s);
    rec(0, strlen(s) - 1);
  }
}
