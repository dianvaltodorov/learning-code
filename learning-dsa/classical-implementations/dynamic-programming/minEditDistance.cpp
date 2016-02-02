#include <iostream>
#include <cstring>
using namespace std;

int dyn[1<<10][1<<10];

int minOfThree(int a, int b, int c){
  return min(a, min(b, c));
}
int main()
{
  char a[1000];
  char b[1000];

  cin >> a >> b;
  int n = strlen(a);
  int m = strlen(b);

  for (int i=0; i<=m; i++)
  {
      for (int j=0; j<=n; j++)
      {
          if (i==0)
              dyn[i][j] = j;  // Min. operations = j
          else if (j==0)
              dyn[i][j] = i; // Min. operations = i
          else if (a[i-1] == b[j-1])
              dyn[i][j] = dyn[i-1][j-1];
          else
              dyn[i][j] = 1 + minOfThree(dyn[i][j-1],  // Insert
                                 dyn[i-1][j],  // Remove
                                 dyn[i-1][j-1]); // Replace
      }
  }

   for(int k = 0; k <= m; k++)
   {
     for(int r = 0; r <= n; r++)
       cout << " " << dyn[k][r] << " ";
     cout << endl;
   }
}
