#include<stdio.h>
#include<iostream>
#include <algorithm>
#define  MAXN 100002
using namespace std;

int n;
int rak[MAXN];
int dist[MAXN];
//фикция която изчислява дали езобщо е възможно да се направят  K на брой купони със входните данни
bool f(int k)
{
  int currDist = dist[0]; // тукущото разстояние на което се намираме
  int currRak = rak[0] - k;// задаваме текущо колическгво

  for(int i = 0; i < n - 1; ++i)
  {
    int diff = dist[i + 1]  - dist[i]; // необходимото разстояние за да достигенм следващия
    if(currRak >= 0) // ракията ще стигне
    {
      if(currRak > diff)
          currRak -= diff;
      else
          currRak = 0; //курирера ще го изпие по средата
    }
    else  //ако имаме дефицит
    {
      currRak -= diff; // вземаме разстоянието предвид
    }
    currRak += rak[i + 1] - k;
  }
  printf("currRak = %d\n", currRak);
  return currRak == 0;
 }

int searchMaximumParties()
{
  int m;
  int b = 0;
  int e =*max_element(rak, rak + n); // избираме по-голямото от двете
  //Правим двиочно обхождане като целта е да намерим максималния брой купони, който може да се получи.
  //Спрямо проверката  дали е осъществимо за средата правим избираме едната от двете половини на подинтервала
  while(e - b > 1)
  {

    m = (b + e + 1)/2;
    printf("%d %d %d\n", b, m ,e);
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
  printf("%d\n", searchMaximumParties());
  return 0;

}
