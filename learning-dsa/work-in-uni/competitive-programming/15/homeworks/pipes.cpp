#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAXN 10000
using namespace std;
int pipes[MAXN];
int n, k, t;


void input()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &pipes[i]);
}

void printP()
{
    for(int i = 0; i < n; i++)
    {
        int x;
        printf("%d ", pipes[i]);
    }
    printf("\n");
}

int possiblePipesWithLength(int d)
{
    int possiblePipes = 0;
    for(int i = 0; i < n; i++)
         possiblePipes = possiblePipes + (pipes[i]/d);
    return possiblePipes;
}

//Двете ми граници са 1 и дължината на максималната тръба
//Така покривам примерния случай, където имам вход
//4 10
//1
//1
//1
//400
// Изход: 40

// 3 4
// 5
// 5
// 10

// 2 3
// 10
// 10
int binarySearch(int left, int right)
{
    int mid;
    int bestMid = 0; // тук се пази  отговора, който върщаме
    while(left <= right)
    {
        int mid = (left + right)/2;
        int npp = possiblePipesWithLength(mid); // броя на избощо възможните  тръби с дължина mid
      //  printf("npp = %d, mid = %d\n", npp, mid );
        //ако сме открили за К трябва да сме сигурни, чее максималнотоq затова
        //изместваме долната лява граница с едно
        if(npp >= k && bestMid < mid)
        {
            bestMid = mid;
            left = mid + 1;
        }
        else if(npp > k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return bestMid;
}

int findMaxPipe()
{
  int maxPipe = pipes[0];
  for(int i = 1; i < n; i++)
  {
    if(pipes[i] > maxPipe)
      maxPipe = pipes[i];
  }
  return maxPipe;
}

int main()
{
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        input();
        printf("%d\n", binarySearch(1, findMaxPipe()));
    }
    return 0;
}
