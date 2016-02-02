#include <iostream>
using namespace std;
struct s{
    char a : 4;
    char b : 2;
    char : 2;
    char c : 4;
    char d : 5;
};

struct A{
    struct B{int x; int y;}* p;
    int x;
}a;

struct K{
    union {double x; char y; int z;};
}s;

struct R{
    int x;
    char c;
    char r;
    char o;
    char u;
    char ty;
    float f;
    short s;
    char* p;
};




int main()
{
  cout << sizeof(struct s) << endl;
  cout << sizeof(struct R) << endl;
  cout << sizeof(void *) << endl;
  cout << sizeof(int *) << endl;
  cout << sizeof(double *) << endl;
  cout << sizeof(char *) << endl;
  // TODO: защо ми дава segmentation fault
  // a.p -> y = 0;
  s.z = 42;
  s.y = 'a';
  cout << s.z << endl;
}
