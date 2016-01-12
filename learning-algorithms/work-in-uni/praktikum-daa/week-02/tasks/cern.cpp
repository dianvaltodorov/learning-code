#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
int n;
char arr[10000][16];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i <= n - 1; i++)
        scanf("%s", arr[i]);
    for(int i = 0; i <= n - 2; i++)
    {
        int minimum_element = i;
        for(int j = i + 1; j <n ; j++)
        {
                if(strcmp(arr[minimum_element], arr[j]) > 0) minimum_element = j;
        }
        char tmp [16];

        strcpy(tmp, arr[minimum_element]);
        strcpy(arr[minimum_element], arr[i]);
        strcpy(arr[i], tmp);
    }

    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}
