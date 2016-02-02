#include<stdio.h>
#include <ctime>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  int n, day, month, year ;
 /* scanf("%d", n);
  for(int i = 0; i <= n - 1; i++)
  {
    scanf("%d.%d.%d", &day, &month, &year);
  }*/

  time_t moment = time(0);
  cout << "Number of sec since January 1,1970: " << time << endl;
}
