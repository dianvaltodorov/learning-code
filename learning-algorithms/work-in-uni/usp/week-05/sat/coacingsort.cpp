#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#define MAX_RANGE 100
using namespace std;
int t, n;
int m[1000001];
int b[MAX_RANGE];

void solve()
{
    for(int i = 0; i < MAX_RANGE; i++)
        b[i] = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
        b[m[i]]++;
    }


   /* for(int i = 1; i < MAX_RANGE; i++)
    {
        b[i] = b[i] + b[i - 1];

    }

    for(int i = n; i > 0; i--)
    {
        m[i] = b[i]
    }*/
    int k = 0;
    for(int i = 0; i < MAX_RANGE; i++)
    {
        int j = 0;
        while(j < b[i])
        {
                j++;
                m[k++] = i;
        }
    }

   for(int i = 0; i < n - 1; i++)
   {
        printf("%d ", m[i]);
   }
   printf("%d\n", m[n - 1]);
}

int main()
{
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        solve();
    }
}
