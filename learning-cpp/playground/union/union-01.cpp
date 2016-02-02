#include <iostream>
using namespace std;

union Data {
   int i;
   float f;
   char str[20];
} x;

union Test
{
  unsigned long l;
  unsigned short s;
  unsigned char c;

}
int main()
{
  Test t;
  union Test t2;
  Test* p = &t;
  
}
