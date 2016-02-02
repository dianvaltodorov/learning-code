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

}
