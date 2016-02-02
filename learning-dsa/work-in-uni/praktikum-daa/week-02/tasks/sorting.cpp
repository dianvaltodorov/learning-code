#include<stdio.h>
#include<vector>
int n, cnt;
int arr[10000][2];

using namespace std;

bool euclid(int x, int y)
{
    int t = x % y;
    while(t != 0)
    {
        x = y;
        y = t;
        t = x % y;
    }
    return y == 1;
}


void printArray()
{
    printf("0");
    for(int i = 0; i < cnt; i++)
        printf(" %d/%d", arr[i][0], arr[i][1]);
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      for(int j = i+1; j <= n; j++)
        if(euclid(i, j))
        {
            arr[cnt][0] = i;
            arr[cnt][1] = j;
            ++cnt;
        }

    for (int i = 0; i < cnt; i++)
        for(int j = 0; j < cnt - 1; j++)
        {
            if(arr[j][0] * arr[j + 1][1] > arr[j][1] * arr[j + 1][0])
            {
                int z = arr[j][0], q = arr[j][1];

                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];

                arr[j + 1][0] = z; arr[j + 1][1] = q;
            }
        }
    printArray();
    return 0;
}
