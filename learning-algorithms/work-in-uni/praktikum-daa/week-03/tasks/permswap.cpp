#include <stdio.h>
#include <stdlib.h>
#define MAX 100
const unsigned n = 7;
int a[7]= { 5, 2, 1, 6, 0, 4, 3};

int b[MAX];
long long br;

void printList(void)
{
    unsigned i;
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}


void mergeSort(unsigned left, unsigned right)
{
    unsigned i, j, k, mid;
    if (right <= left) return;
    mid = (right + left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge()

}


int main(void)
{
    printf("Before Sorting:\n");
    printList();
    mergeSort(0, n-1);
    printf("After Sorting:\n");
    printList();
    printf("br = %d", br);
    return 0;
}
