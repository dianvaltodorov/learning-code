#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
int n;
int x[4];
int y[4];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &x[i], &y[i]);
  }

  int area ;
  if(n == 1) printf("-1\n");
  else if(n == 2 )
          if(x[0] == x[1] || y[0] == y[1]) printf("-1\n");
          else printf("%d\n", abs((x[0] - x[1]) * (y[0] - y[1])));
  else if(n >= 3)
          {
            int a = abs(x[0] - x[1]);
            int b = abs(x[0] - x[2]);
            int c = abs(x[1] - x[2]);

            int d = abs(y[0] - y[1]);
            int e = abs(y[0] - y[2]);
            int f = abs(y[1] - y[2]);

            printf("%d\n", (a + b + c)*(d + e + f)/4);
          }
}
