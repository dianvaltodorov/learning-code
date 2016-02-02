#include <iostream>
#include <sstream>
#include <string>
using namespace std;


struct movie
{
  string title;
  int year;
}films[4];

void printmovie (movie mov)
{
  cout << mov.title;
  cout << " (" << mov.year << ")\n";
}

int main()
{
  int n;
  string mystr;
  for(n = 0; n < 3; n++)
  {
    cout << "Enter title: ";
    getline(cin, films[n].title);
    cout << "Enter year: ";
    getline(cin, mystr);
    stringstream(mystr) >> films[n].year;
  }

  for(n = 0; n < 3; n++)
  {
    printmovie(films[n]);
  }
}
