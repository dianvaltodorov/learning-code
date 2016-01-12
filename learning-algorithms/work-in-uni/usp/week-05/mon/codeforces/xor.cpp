#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<cstring>
using namespace std;

char a[10000000];
char b[10000000];
void input()
{
    scanf("%s", a);
    scanf("%s", b);

}
int main()
{

    0 | 0 -> 0  0 ^ 0 -> 0
    ако имаме 1 можем да получим каквото си искаме
    трябва да се направи проверка
    input();
    bool ok = true;
    if(strlen(a) != strlen(b)) {
     printf("NO");
     return 0;
    }
    else
    {
        for(int i = 1; i < strlen(b); i++)
        {
            if(b[i - 1] == '0' && b[i+1] =='0')
            {
                if((a[i - 1] != '0' && a[i] == '0') || (a[i - 1] != '0' && a[i] == '0'))
                    ok = false;
            }
        }
    }
    if(ok) printf("YES");
    else printf("NO");
}
