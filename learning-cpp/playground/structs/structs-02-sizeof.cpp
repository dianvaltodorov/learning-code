
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct product
{
  int weight;
  long long kg;
  double y;
  char o;
  char *make;
  double price;
}lemon;

struct movie
{
  string title;
  int year;
};

struct student1
{
  char a;
};

struct student2
{
  int a;
};

struct student3
{
  char a;
  int b;
};

struct student4
{
  int a;
  int b;
};

struct student5
{
  int a;
  int b;
  double c;
};


struct student6
{
  int a;
  char y[1];
};

struct student7
{
  int a;
  char y[2];
};

struct student8
{
  int a;
  char y[3];
};

struct student9
{
  int a;
  char y[4];
};

struct student10
{
  int a;
  char y[5];
};

struct student11
{
  int a;
  char u;
  int b;
  char y;
};

struct student12
{
  int a;
  int b;
  char u;
  char y;
};

int main()
{

  product joo;
  joo.price = 10;
  joo.weight = 9;

  product foo;
  cout << "sizeof(Product joo) =  " << sizeof(joo) << endl;
  cout << "sizeof(Product foo) = " << sizeof(foo) << endl;
  movie gaa;
  cout << "sizeof(Movie gaa) = " << sizeof(movie) << endl;
  cout << "sizeof(student 1 with a member char) = " << sizeof(struct student1) << endl;
  cout << "sizeof(student 2 with a member int) = " << sizeof(struct student2) << endl;
  cout << "sizeof(student 3 with a member char and a member int) = " << sizeof(struct student3) << endl;
  cout << "sizeof(student 4 with 2 members ints) = " << sizeof(struct student4) << endl;
  cout << "sizeof(student 5 with 2 members ints, and a double) = " << sizeof(struct student5) << endl;
  cout << "sizeof(student 6 with 1 member int, and 1 array with size 1) = " << sizeof(struct student6) << endl;
  cout << "sizeof(student 7 with 1 member int, and 1 array with size 2) = " << sizeof(struct student7) << endl;
  cout << "sizeof(student 8 with 1 member int, and 1 array with size 3) = " << sizeof(struct student8) << endl;
  cout << "sizeof(student 9 with 1 member int, and 1 array with size 4) = " << sizeof(struct student9) << endl;
  cout << "sizeof(student 10 with 1 member int, and 1 array with size 5) = " << sizeof(struct student10) << endl;
  cout << "sizeof(student 11 with int, char, int, char) = " << sizeof(struct student11) << endl;
  cout << "sizeof(student 12 with int, int, int, char) = " << sizeof(struct student12) << endl;

  return 0;
}
