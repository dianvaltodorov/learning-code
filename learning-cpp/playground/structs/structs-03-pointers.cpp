#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct movie
{
  string title;
  int year;
};

void printmovie (movie mov)
{
  cout << mov.title;
  cout << " (" << mov.year << ")\n";
}

int main()
{
  movie amovie;
  movie * pmovie;
  pmovie = &amovie;
  string mystr;
  cout << "Enter title: ";
  getline(cin, pmovie->title);
  cout << "Enter year: ";
  getline(cin, mystr);
  stringstream(mystr) >> (*pmovie).year;
  printmovie((*pmovie));
  return 0;
}
