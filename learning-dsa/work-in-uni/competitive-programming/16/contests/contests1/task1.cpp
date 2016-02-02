#include <iostream>
#include <stdio.h>
using namespace std;

int newNumber(char statement[]){
  for (int j = 0; j < 3; j++) {
    if (statement[j] =='+')
      return 1;
    if (statement[j] =='-')
      return -1;
  }
  return 0;
}
int main()
{
  int n;
  scanf("%d", &n);
  char statement[3];
  int r = 0;
  for (int i = 0; i < n; i++) {
    printf("%d\n", i );
    scanf("%s", statement);
    r = r + newNumber(statement);
  }
  printf("%d\n", r);
  return 0;
}
