//Трябва ни едномерен масив до милион и два елемента. Във всеки елемент ще пазим решението на подзача
//Подзадачата е при остнали к монети човека който на ход печели или не
//Това можем да го направим с рекурсия, но 1 милион е много
//Ще направим динамичното по броя монети
//Ще се интересуваме кой печели


//Рекурсивно
#include<stdio.h>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int t, n, m, l ,k;
int N[1<<20];

void input()
{
  scanf("%d %d %d", &k, &l, &m);
  // for(int i = 0; i < m; i++)
  // {
  //   scanf("%d", &n[i]);
  // }
}

void kamenDP()
{
  dp[0] = 0;
  for((int i = 0; i <= 1 000 000; i++)
  {
    if(dp[i - 1] == 0)
    {
      dp[i] = 1;
      continue;
    }

    if(i- k >= 0 && dp[i - k] == 0)
    {
      dp[i] = 1;
      continue;
    }

    if(i - l >= 0 && dp[i - k] == 0)
    {
      dp[i] = 1;
      continue;
    }
    dp[i] = 0

    for(int i = 1; i <= n; i++)
    {
      if(dp[i] == 1)
        printf("A\n", );
      else
        printf("A\n", );
    }
  }
}

int main()
{
  scanf("%d", &t );
  for(int i = 1; i <= t; i++)
  {
    input();
    solve();
  }
}
