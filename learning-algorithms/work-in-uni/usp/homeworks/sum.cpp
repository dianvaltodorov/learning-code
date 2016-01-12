#include<iostream>
#include<stdio.h>

using namespace std;
long long t, n, m; // 1 <
long long treeSize; // 0 < treeSize < 262144 = 2^18
long long command; // 0 1
long long x, y; // 0 < x, y < 1000
long long a[1<<22]; //maximum elements of the array 262144 = 2^18.
                    //Това идва от факта че входа ни е от 100000 на брой елемента
                    //2^17 = 131072  се пада първата степен на двойката по голяма или равна на 100000
                    //max elements count = 2^17 * 2 > 131072 * 2 = 262144
void printA()
{
  for(long long i = 1; i < treeSize; i++)
  {
      printf("%lld ", a[i]);
  }
  printf("\n");
}

void makeIndexTree()
{
  for(long long i = treeSize / 2ll - 1ll; i >= 1ll; i--)
    a[i] = a[2ll * i] + a[2ll * i + 1ll];
}

long long sum(long long endIndex)
{
  endIndex += treeSize/2ll;
  long long s = 0ll;
  while(endIndex > 1ll)
  {
      if(endIndex % 2ll ==1ll) // проверяваме десен син ли е? Ако е десен прибавяме 11
      {
          s += a[endIndex - 1ll];
      }
      endIndex = endIndex /2ll;
  }
  return s;
}

void change(long long idx, long long valToAdd)
{
  idx = idx +  treeSize/2ll  - 1ll;
  a[idx] += valToAdd;
  idx /= 2ll;
  while(idx >= 1ll)
  {
      a[idx] = a[2ll * idx] + a[2ll * idx + 1ll];
      idx /= 2ll;
  }
  //printA();
}
long long findSize(long long n)
{
  long long res = 1ll;
  while(res < n) res *= 2ll;
  return res * 2ll;
}

void solve()
{
  scanf("%lld %lld", &n, &m);
  treeSize = findSize(n);
  long long i;
  for(i = treeSize / 2 ; i < treeSize/2 + n; i++)
    scanf("%lld", &a[i]);

  makeIndexTree();

  for(i = 0; i < m; i++)
  {
    scanf("%lld %lld %lld", &command, &x, &y);
    if(command == 1)
      printf("%lld\n", sum(y) - sum(x-1));
    else
    {
      change(x, y);
    }
  }
}

int main()
{
  scanf("%lld", &t);
  for(long long i = 1; i <= t; i++)
  {
    solve();
  }
}
