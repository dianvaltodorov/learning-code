#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
int n, res;

char op[3];
int main()
{

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {

        scanf("%s", op);
        if(op[0] == '+' || op[1]=='+') res++;
        if(op[0] == '-' || op[1]=='-') res--;
    }
    printf("%d\n", res);
    return 0;
}
