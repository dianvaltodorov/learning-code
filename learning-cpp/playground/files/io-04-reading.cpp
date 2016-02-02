#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ofstream myfile;
  myfile.open();
  myfile << "Write text\n";
  myfile.close();

  ofsrteam fout("output.txt");
  fout << "This is line of text.";
  fout << "This is another one";
  fout << endl;
  fout.close();

  fout = open("output.txt");


  return 0;
}
