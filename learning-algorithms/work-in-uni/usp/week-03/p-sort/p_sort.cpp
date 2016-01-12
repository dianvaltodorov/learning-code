#include<stdio.h>

using namespace std;
unsigned t, m, n, a[100];
//[2; 10)  [10; 15)
int binarySearch(unsigned x, unsigned* arr, unsigned low, unsigned high)
{
    unsigned med;
    while(low < high)
    {
     med = (low + high) / 2;

     if(arr[med] == x)
      return med;
     else if(arr[med] < x )
      low = med + 1;
     else
      high = med - 1;
    }
    return med;
}

int main()
{
    unsigned i, j, k, x;

    for(i = 0; i <= t - 1; i++)
    {
        scanf("%d", &m);
        scanf("%d", &n);

        for(j = 0; j <= n - 1; j++)
        {
            scanf("%d", &a[i]);
        }

        for(k = 0; k <= m - 1;  k++)
        {
           scanf("%d", &x);
           printf("%d ", binarySearch(a, ));
        }
        printf("\n");
    }
}
