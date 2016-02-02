#include <iostream>
#include <fstream>

using namespace std;
#define COL_WIDTH 50

int main()
{
  int c;
  char filename[FILENAME_MAX];
  char inputline[COL_WIDTH + 1];
  cout << "Enter a file name and press ENTER: ";
  cin.getline(filename, FILENAME_MAX);

  ifstream fin(filename);
  if(!fin)
  {
    cout << filename << " could not be opened";
    cout << endl;
    return -1;
  }

  while(true)
  {
    for(int i = 1; i < 24 && !fin.eof(); ++i)
    {
      fin.getline(inputline, COL_WIDTH);
      cout << inputline;
      cout << endl;
    }

    if(fin.eof())
    {
      break;
    }

    cout << "More? (Press Q and Enter to quit).";
    cin.getline(inputline, COL_WIDTH);
    c = inputline[0];
    if(c=='Q' || c=='q')
    {
      break;
    }
  }
}
