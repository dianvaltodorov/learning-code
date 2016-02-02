#include <iostream>
using namespace std;
int main()
{
   string str ("Test string");
   cout << str << endl;
   cout << "Length = " << str.length() << endl;
   cout << "Size = " << str.size() << endl;
   cout << "Max Size = " << str.max_size() << endl;
   cout << "Is Empty = " << str.empty() << endl;
   cout << "Capacity = " << str.capacity() << endl;
   str = str + "DIDO";
   cout << str.capacity() << endl;
   str.shrink_to_fit();
   
}
