#include<stdio.h>
int h[1<<20];
int n;

void printHeap()
{
    for(int i = 0; i <= n - 1; i++)
    {
        printf("%d ",h[i]);
    }
    printf("\n");
}

void sift_up(int x)
{
    h[n++] = x;
    int i = n - 1;
    while(i != 0 && h[(i - 1)/2] < h[i]){
        int z = h[i];
        h[i] = h[(i - 1)/2];
        h[(i - 1) / 2] = z;
        i = (i - 1) / 2;
    }
    //printHeap();
}

int sift_down()
{
    int top = h[0];
    h[0] = h[--n];
    int i = 0;
    while(i * 2 + 1 < n)
    {
        int mi = i;
        if(h[i * 2 + 1] > h[mi]) mi = i * 2 + 1;
        if(i * 2 + 2 < n && h[i * 2 + 2] > h[mi]) mi = 2 * i + 2;
        if(i == mi) break;
        int  z = h[i];
        h[i] = h[mi];
        h[mi] = z;
        i = mi;
    }
    //printHeap();
    return top;
}

void printMaximum()
{
    if(n = 0)
    {
        printf("Not available");
    }
    else
    {
         printf("%d\n", h[0]);
    }
}

int main()
{
    char command;
    int b;

    while( scanf("%c", &command))
    {
        if(command == 'Q') break;

        if(command == 'A')
        {
            scanf("%d", &b);
            sift_up(b);
        }

        if(command == 'R')
        {
            if(n == 0) printf("Not available\n");
            else {printf("%d\n", sift_down());}
        }

        if(command == 'L')
        {
            if(n == 0) printf("Not available");
            else {printf("%d\n", h[0]);}
        }
    }

    return 0;
}
