#include <stdio.h>
#include <algorithm>
#define MAXN 1000000

using namespace std;
int seq[MAXN];
int newSeq[MAXN];
int n, k;
int main()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &seq[i]);
  }
  int minV;
  for(int i = 0; i < k ; i++)
    if(seq[i] < minV) minV = seq[i];

   newSeq[0] = minV;
   for(int i = 1; i < n - k + 1; i++)
      newSeq[i] = min(newSeq[i - 1 ], seq[i + k - 1]);

  for(int k = 0; k < n; k++)
  {
    printf("%d\n", newSeq[k]);
  }

  return 0;
}
