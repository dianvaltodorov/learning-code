#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;
int const MAXN =2 * (1 << 20);
// int a[MAXN] = {1, 5, 8 ,19, 2, 4, 6, 8};
int a[MAXN];
int b[MAXN];
// int n = 8;
int n;
int cnt = 0;

void merge(int left, int mid, int right)
{
  int i = left;
  int j = mid;
  int k = left;
  while(i < mid && j < right)
  {
    if(a[i] < a[j])
    {
      b[k++] = a[i++];
    }
    else
    {
      b[k++] = a[j++];
      cnt++;
    }
  }

  while(i < mid)
    b[k++] = a[i++];

  while(j < right)
    b[k++] = a[j++];

  for(i = left; i < right; i++)
    a[i] = b[i];
}

void printArrayA()
{
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void printArrayB()
{
  for(int i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n");
}

void mergeSort(int left, int right)
{
  if(right - left < 2) return;
  int mid = (left + right) / 2;
  mergeSort(left, mid);
  mergeSort(mid, right);
  merge(left, mid, right);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printArrayA();
  mergeSort(0, n);
  printArrayA();
  printf("%d\n", cnt);
  return 0;
}
