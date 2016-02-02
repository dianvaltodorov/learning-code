#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  int x = 1234;
  ofstream output("data.dat", ios::binary | ios::trunc );
  output.write((const char*)&x, sizeof(x));

  int y;
  ifstream input("data.dat", ios::binary);
  input.read((char*)&y, sizeof(y));
  input.close();
  cout << y << endl;
  return 0;
}
