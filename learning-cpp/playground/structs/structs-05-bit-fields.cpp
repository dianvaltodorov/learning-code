#include <iostream>
using namespace std;

struct foo1
{
  unsigned int b : 3;
};



struct foo2
{
  unsigned char c : 3;
  unsigned char d : 2;
  unsigned char e : 2;
  unsigned char f : 2;
};

struct foo3
{
  unsigned char c : 3;
  unsigned char d : 2;
  unsigned char e : 2;
  unsigned char f : 1;
};


struct foo4
{
  unsigned char c : 3;
  unsigned char d : 2;
  unsigned char :0;
  unsigned char f : 1;
};


struct foo5
{
  unsigned int t: 1;
  unsigned char c : 3;
};


struct foo6
{
  unsigned int me : 2;
  unsigned char c : 3;
  int ta :2;
};

struct foo7
{
  int me;
  int ta;
  char c;
  char u;
  char t;
  char i;
};



struct foo8
{
  int me;
  int ta:2;
  char c:1;
  char u:1;
  char t:1;
  char i:1;
};


struct roo1 {
    char flag1 : 1;
    char flag2 : 1;
    char flag3 : 1;
    char flag4 : 1;
    char flag5 : 1;
    char flag6 : 1;
    char flag7 : 1;
    char flag8 : 1;
};


struct roo2 {
    char flag1 : 1;
    char flag2 : 1;
    char flag3 : 1;
    char flag4 : 1;
    char flag5 : 1;
    char flag6 : 1;
    char flag7 : 1;
    char flag8 : 1;
    char flag9 : 1;
};


int main()
{
  cout << "sizeof(foo1 with 1 int bitfield(3) ) = " << sizeof(struct foo1) << endl;
  cout << "sizeof(foo2 with 4 bitfield with sizes 3 + 2 + 2 +2 = 9) = "  << sizeof(struct foo2)<< endl;
  cout << "sizeof(foo3 with 4 bitfield with sizes 3 + 2 + 2 + 1 = 8) = "  << sizeof(struct foo3)<< endl;
  cout << "sizeof(foo4 with 5 bitfield with sizes 3 + 2 + 0 + 2 + 1 = 8) = "  << sizeof(struct foo3) << endl;
  cout << "sizeof(foo5 with 2 bitfield, one int, one char) = "  << sizeof(struct foo4) << endl;
  cout << "sizeof(foo6 with 2 bitfield, one int(2), one char(3), one int (2) ) = "  << sizeof(struct foo6) << endl;
  foo6 tt = {1,2,3};
  for(int i = 0; i < 10; i++)
  {
    cout << tt.me << "    " << tt.c << "    " << tt.ta << endl;
    tt.me++;
    tt.c++;
    tt.ta++;
  }
  cout << "sizeof(foo7 with int, int, char, char, char, char) = "  << sizeof(struct foo7) << endl;
  cout << "sizeof(foo8 with int, int, char, char, char, char) = "  << sizeof(struct foo8) << endl;
  cout << "sizeof(roo1 with 8 chars of size 1 bit) = "  << sizeof(struct roo1) << endl;
  cout << "sizeof(roo2 with 9 chars of size 1 bit) = "  << sizeof(struct roo2) << endl;

  return 0;
}
