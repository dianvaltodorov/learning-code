
#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int n, k, q;
vector <unsigned long long > vec;
unsigned long long Q[10001];
/*
14 3 9
3 4 0 5 7 2 3 7 10 9 3 39 11 1
5
9
12
14
24
89
10
53
100
*/
void input()
{
    unsigned i;
    unsigned long long x;
    scanf("%d %d %d", &n, &k, &q);
    vec.resize(n);
    for(i = 0; i < n; i++)
      scanf("%llu",  &vec[i]);

    for(i = 0; i < q; i++)
        scanf("%llu", &Q[i]);
}

void printA()
{
    for(int i = 0; i < vec.size(); i++)
        printf("%llu ", vec[i]);
    printf("\n");
}

int main()
{

  input();
  unsigned long long sum = 0;
  for(int i = 0; i < k; i++)
  {
    sum += vec[i];
  }
  unsigned long long  x = vec[0], y;
  vec[0] = sum;
  for(int i = 1; i < n - k + 1; i++)
  {
    y = vec[i];
    vec[i] = vec[i - 1] - x + vec[i + k - 1];
    x = y;
  }
  // printA();

  for(int i = 1; i < n - k + 1; i++)
    if(vec[i-1] > vec[i]) vec[i] = vec[i-1];

  // printA();

  for(int i = 0 ; i < q; i++)
  {
     int d = distance(vec.begin(), lower_bound (vec.begin(), vec.end() - k, Q[i]));
     if(vec[d] < Q[i]) printf("-1\n");
     else printf("%d\n", d);
  }
  return 0;
}
