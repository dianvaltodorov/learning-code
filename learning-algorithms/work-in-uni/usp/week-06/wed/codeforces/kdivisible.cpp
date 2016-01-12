#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
int t;
long long  a, b, k;

void input()
{
  cin >> k >> a >> b;
}

int numberOfDivisible()
{
  // res = 0;
  // if(a % k == 0 || b %k == 0)
  //   res++;
  // cout << (b - a) / k + res; // hack 3 2 4
  //
  // long long  p1 = a / k;
  // long long  p2 = b / k;
  // if(a % k == 0)
  //   return p2 - p1 + 1;
  // else return p2 - p1;

  if(a>=0 && b >= 0)
    cout<<b/k - a/k - (a%k==0) <<endl;
  else
    cout << b/k + a/k+ 1<<endl;
}

int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
      input();
      cout << numberOfDivisible() << endl;
    }
}
