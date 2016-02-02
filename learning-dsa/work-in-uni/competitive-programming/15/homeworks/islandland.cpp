#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
unsigned t, n, m;
int a[1000][1000]; //N rows x M colums
int c[4] = {  1, -1, 0, 0};
int r[4] = {  0, 0, 1, -1,};

void input()
{
 scanf("%d %d", &n, &m);
 for(int i = 0; i < n; i++)
 {
   for(int j = 0; j < m; j++)
   {
     scanf("%d", &a[i][j]);
   }
 }
}

void printA()
{
   printf("\nPrint A:\n");
   for(int i = 0; i < n; i++)
   {
       for(int j = 0; j < m; j++)
       {
           printf("%d ", a[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}

int calculateIslandSize(int i, int j)
{
   queue< pair<int, int> > q;
   q.push(make_pair(i, j));
   a[i][j] = 0;
   int islandSize = 1;

   while(!q.empty())
   {
       pair<int, int> current = q.front();
       q.pop();
//       printf("adjacent to <%d %d>:\n", current.first, current.second);

       for(int i = 0; i < 4; i++)
       {
           int newRow = current.first + c[i];
           int newColumn = current.second + r[i];
//           printf("\tnewRow = %d, newColumn = %d a[%d][%d] = %d\n", newRow, newColumn, newRow, newColumn, a[newRow][newColumn]);
           if((0 <= newRow && newRow < n) &&
              (0 <= newColumn && newColumn < m))
           {
               if(a[newRow][newColumn])
               {
//                 printf("\t\tnewRow = %d, newColumn = %d\n", newRow, newColumn);

                   q.push(make_pair(newRow, newColumn));
                   islandSize += 1;
                   a[newRow][newColumn] = 0;
               }
           }
       }
   }
   return islandSize;
}
int main()
{
    unsigned t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {

       input();
//       printA();
       int maxSize = 0;
       for(int j = 0; j < n; j++)
           for(int k = 0; k < m; k++)
               if(a[j][k])
               {
//                    printf("\nComponent:\n");
                    int x = calculateIslandSize(j, k);
//                    printf("Size of Component: %d\n", x);
//                    printA();
                    if(x > maxSize) maxSize = x;
               }
       printf("%d\n", maxSize);
   }
   return 0;
}
