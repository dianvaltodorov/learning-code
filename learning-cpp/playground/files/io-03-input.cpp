#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream myfile("example.txt");
  if(myfile.is_open())
  {
    myfile << "Yolo\n";
    myfile << "Writing this to a file.\n";
    myfile.close();
  }
  else  cout << "Unable to open a file\n";

  string line;
  ifstream mf ("example.txt");
  if(mf.is_open())
  {
    while(getline(mf, line))
    {
      cout << line << '\n';
    }
    mf.close();
  } else cout << "Unable to open file";

}
