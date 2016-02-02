#include<stdio.h>
#include<algorithm>
using namespace std;
char c[10000000];
int main()
{
    int n, a, g, Sa = 0, Sg = 0, S = 0, k = 0;
    long long ifA, ifG;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &g);
        ifA = abs((Sa  + a)- Sg);
        ifG = abs(Sa - (Sg + g));
        if(ifA < ifG)
        {
            Sa += a;
            c[k++] = 'A';
        }
        else
        {
            Sg += g;
            c[k++] = 'G';
        }
    }
    if(abs (Sa - Sg) <= 500) printf("%s\n", c);
    else printf("-1\n");
    return 0;

}
