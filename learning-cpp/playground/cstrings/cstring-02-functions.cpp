#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char s1[80];
  strcpy(s1, "One");
  strcpy(s1, "Two");
  strcpy(s1, "Three");
  cout << s1 << endl;

  char s2[5] = "Zero";
  strcat(s2, "One");
  strcat(s2, "Two");
  strcat(s2, "Three");
  cout << s2 << endl;

  char s3[20];
  strncpy(s1, s2 ,20);
  strncpy(s1, s2 ,20);
  strncpy(s1, s2 ,20);
  cout << s3 << endl;

}
