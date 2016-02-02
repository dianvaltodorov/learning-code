#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#define COL_WIDTH 80

using namespace std;

int get_int(int default_value);

int main()
{
  char filename[FILENAME_MAX];
  int n = 0;
  char name[20];
  int age = 0;
  int recsize = sizeof(name) + sizeof(int);
  cout << "Enter file name" << endl;
  cin.getline(filename, FILENAME_MAX);

  fstream fbin(filename, ios::binary | ios::out);
  if(!fbin){
    cout << "Could not open " << filename << endl;
    return -1;
  }

  cout << "Enter file record number: ";
  n = get_int(0);

  cout << "Enter name: ";
  cin.getline(name, sizeof(name) - 1);

  cout << "Enter age: ";
  age = get_int(0);

  fbin.seekp(n * recsize);
  fbin.write(name, sizeof(name) - 1);
  fbin.write((char*)(&age), sizeof(int));
  fbin.close();
  return 0;
}

int get_int(int default_value){
  char s[COL_WIDTH + 1];
  cin.getline(s, COL_WIDTH);
  if(strlen(s) == 0)
  {
    return default_value;
  }
  return atoi(s);
}
