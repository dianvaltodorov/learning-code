#include <iostream>
#include <ctime>

void getSeconds(unsigned long *par);
double getAverage(int *arr, int size);

int main()
{
  int var1;
  char var2[10];
  std::cout << "Address of var1: " << &var1  << "\n";
  std::cout << "Address of var2: " << &var2  << "\n";

  int var = 20;
  int *ip;
  ip = &var;

  std::cout << "Value of variable: "  << var <<  "\n";
  std::cout << "Address stored in ip variable: " << ip << "\n";
  std::cout << "Value of ip variable: " << *ip << "\n";

  int *ptr = NULL;
  std::cout << "The value of ptr is " << ptr << "\n";
  if(ptr) std::cout << "The value is not null" << "\n";
  if(!ptr) std::cout << "The value is null" << "\n";


  int* arrPtr;
  int arr[10] = {1,2,3,4,5,1,2,3,4};
  arrPtr = arr;
  for(int i = 0; i < 10; i++)
  {
    std::cout << "Address of var["<< i << "] = " << arrPtr << "\n";
    std::cout << "Value of var["<< i << "] = " << *arrPtr << "\n";
    arrPtr++;
  }

  for(int i = 10; i > 0; i--)
  {
    std::cout << "Address of var["<< i << "] = " << arrPtr << "\n";
    std::cout << "Value of var["<< i << "] = " << *arrPtr << "\n";
    arrPtr--;
  }

  std::cout << *(arrPtr + 2) << "\n";

  int x = 300;
  int *pointer;
  int **pptr;


  pointer = &x;
  pptr = &pointer;

  std::cout << "Value of var :" << x << "\n";
  std::cout << "Value available at *ptr :" << *pointer<< "\n";
  std::cout << "Value available at **pptr :" << **pptr << "\n";

  const char *name[10] = {"Dido", "Kido", "Mido", "Fido", "Yodo"};
  std::cout << *(name + 3) << "\n";
  unsigned long sec;
  getSeconds(&sec);
  std::cout << "Number of seconds :" << sec << "\n";

  int balance[5] = {100,1,2,34,4};
  double avg;

  avg = getAverage(balance, 5);
  std::cout << "Average value is " << avg << "\n";

  return 0;
}

double getAverage(int *arr, int size)
{
  int i, sum = 0;
  double avg;

  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }

  avg = double(sum) / size;

  return avg;
}

void getSeconds(unsigned long *par)
{
  *par = time(NULL);
  return;
}
