#include<stdio.h>
#include<iostream>
#include <algorithm>
#define  MAXN 100002
using namespace std;

int n;
int rak[MAXN];
int dist[MAXN];
//фикция която изчислява дали езобщо е възможно да се направят  K на брой купони със
bool f(int k)
{
  int currDist = dist[0]; // тукущото разстояние на което се намираме
  int currRak = rak[0] - k;// представи си блок

  for(int i = 0; i < n - 1; ++i)
  {
    int diff = dist[i + 1]  - dist[i]; // необходимото разстояние за да достигенм следващия
    if(currRak >= 0) // ракията ще стигне
    {
      if(currRak > diff)
      {
          currRak -= diff;
      }
      else
      {
          currRak = 0; //курирера ще го изпие по средата
      }
    }
    else  //ако имаме дефицит
    {
      currRak -= diff; // вземаме разстоянието предвид
    }
    currRak += rak[i + 1] - k;
  }
  return currRak == 0;
 }

int searchMaximumParties()
{
  int m;
  int b = 0;
  int e =*max_element(rak, rak + n);
  while(e - b > 1)
  {
    m = (b + e + 1)/2;
    if(f(m) == 0)
    {
      e = m;
    }
    else
    {
      b = m;
    }
  }
  return b;
}


int main()
{
  scanf("%d", &n);
  for(int i  = 0; i < n; i++)
    scanf("%d %d", &dist[i], &rak[i]);
  searchMaximumParties();
  return 0;

}
