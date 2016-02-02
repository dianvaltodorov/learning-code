#include <iostream>

void incrementAll(int*, int*);
void printAll(const int* , const int*);

int main()
{
  int myvar = 8;
  int *foo = &myvar;

  int baz = 20;
  std::cout << "baz = " << baz << "\n";
  std::cout << "foo = " << foo << "\n";
  std::cout << "myvar = " << myvar << "\n";

  int firstValue = 20, secondValue;
  int *ptr = &firstValue;
  std::cout << "ptr = " << ptr << " firstValue = " << firstValue << " ptr = " << ptr << " *ptr = " << *ptr << "\n";
  *ptr = 10;
  std::cout << "ptr = " << ptr << " firstValue = " << firstValue << " ptr = " << ptr << " *ptr = " << *ptr << "\n";
  ptr = &secondValue;
  *ptr = 3700;
  std::cout << secondValue << "\n";

  int thirdValue = 5, forthValue = 14;
  int *p1 , *p2;
  p1 = &thirdValue;
  p2 = &forthValue;
  *p1 = 10;
  *p2 = *p1 + 1000;
  std::cout << "p1 = " << *p1 << "\n";
  std::cout << "p2 = " << *p2 << "\n";

  p1 = p2;
  *p1 = 20;
  std::cout << "p1 = " << *p1 << "\n";
  std::cout << "p2 = " << *p2 << "\n";

  int myarray[20];
  int *mypointer;
  mypointer = myarray;

  int numbers[5];
  int *p;
  p = numbers;
  *p = 10;
  p++;
  *p = 20;

  p = &numbers[2];
  *p = 30;

  p = numbers + 3;
  *p = 40;

  p = numbers;
  *(p + 4) = 50;

  for (int n=0; n<5; n++)
    std::cout << numbers[n] << ", ";
  std::cout << "\n";

  int x;
  int y = 10;
  const int *poi = &y;
  x = *poi;
  poi = &x;

  int items[10] = {1,2,3,4,5,6,7};
  p = items;

  std::cout << *p++ <<  " " << *++p <<  " " <<   ++*p  <<  " " <<   (*p)++ << "\n";

  const char * roo = "hello";
  std::cout << *(roo+4) << "\n";
  std::cout << roo[4] << "\n";

  int nums[] = {1,2,3,4};
  incrementAll(nums, nums + 3);


  int moo;
  int * pmoo1 = &moo;
  const int * pmoo2 = &moo;
  int * const pmoo3 = &moo;
  const int * const pmoo4 = &moo;


  char a;
  char * b;
  char ** c;
  a = 'z';
  b = &a;
  c = &b;

  return 0;
}

void incrementAll(int* start, int* end)
{
  int *current = start;
  while(current != end)
  {
    ++(*current);
    ++current;
  }
}

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }
