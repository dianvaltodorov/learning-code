#include <stdio.h>
#include <stdlib.h>
int main()
{
    static int x = 10;
    int a=10;
    int b=10;
    int c=10;
    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);
    printf("%p\n",&x);
    int *y = malloc(sizeof(int));
    printf("%p\n", y);
    return 0;
}


