#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>

using namespace std;
int n, m;
char u[1<<5];
char v[1<<5];


int main()
{
    int am b;
    int cnt = 0;
    while(scanf("%d %d", &a &b) != EOF)
    {
      mas[cnt++] = make_pair(a+b, a);
    }
    sort(mas, mas + cnt);
    int ans=0;
    int end = 0;
    for(int i = 0; i < cnt; i++){
    if(mas[i].second >= end)
    {
      ans++;
      end = mas[i].first;
    }

    printf("%d\n", ans);
    return 0;
}
