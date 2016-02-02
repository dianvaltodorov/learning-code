#include<iostream>
#include<stdio.h>
using namespace std;

int binarySearch(unsigned long long x)
{
    int left = 0;
    int right = 64;
    while(left < right)
    {
        int mid = (left + right)/2;
        if((1ULL << mid) < x)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main()
{
    int t;
    unsigned long long n;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%llu", &n);
        printf("%d\n", binarySearch(n));
    }
    return 0;
}
