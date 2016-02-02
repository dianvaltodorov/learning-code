#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;
int main()
{
  char buffer[100];
  ofstream out("io-15.dat", ios::out | ios::trunc | ios::binary);
  while(true)
  {
   cin >> buffer;
   if(!cin)
   {
     cin.clear();
   }
   buffer [100] = { d, i , d , o, '\0', cd}
   out.write((const char *) buffer, 100);
   if(out.good() && !strcmp("exit", buffer))
      break;
  }
  out.close();

  unsigned int var = 0x0000000a;
  unsigned short arr[3] = { 0xAB, 0xCD, 0xEF };
  out.write((const char *) &var, sizeof(var));
  out.write((const char *) arr, sizeof(arr));
  cout << var << endl;
  return 0;
}
