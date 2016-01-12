#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;
int a[1<<16];
int main ()
{
    int x;
    int cnt = -1;
    while(scanf("%d", &x) != EOF)
    {
        a[++cnt] = x;
    }

    while (cnt >= 0)
    {
     printf("%.6f\n", sqrt(a[cnt--]));
    }
    return 0;
}
