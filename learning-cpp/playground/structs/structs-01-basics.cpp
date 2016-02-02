#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct product
{
  int weight;
  double price;
}lemon;

struct movies_t
{
  string title;
  int year;
} mine, yours, films[3];

void printmovie(movies_t movie);

int main()
{
  product apple;
  product banana, melon;

  cout << "Pinting the values of these undefined members:" << endl;
  cout << apple.weight << endl;
  cout << apple.price << endl;
  cout << banana.weight << endl;
  cout << banana.price << endl;
  cout << melon.weight << endl;
  cout << melon.price << endl;

  cout << "=== First example(basic): ===" << endl;
  string mystr;
  mine.title = "2001 A Space Odyssey";
  mine.year = 1968;
  cout << "Enter title: ";
  getline(cin, yours.title);
  cout << "Enter year: ";
  getline(cin, mystr);
  stringstream(mystr) >> yours.year;
  cout << "My favorite movie is:\n ";
  printmovie (mine);
  cout << "And yours is:\n ";
  printmovie (yours);

  cout << "=== Second example(array): ===" << endl;
  int n;
  for(n = 0; n < 3; n++)
  {
    cout << "Enter title: ";
    getline(cin, films[n].title);
    cout << "Enter year: ";
    getline(cin, mystr);
    stringstream(mystr) >> films[n].year;
  }

  cout << "=== Second example(pointers): ===" << endl;
  movies_t amovie;
  movies_t * pmovie;
  pmovie = &amovie;
  cout << "Enter title: ";
  getline(cin, pmovie->title);
  cout << "Enter year: ";
  getline(cin, mystr);
  stringstream(mystr) >> (*pmovie).year;

  cout << "=== Thried example(sizes): ===" << endl;

  product joo;
  joo.price = 10;
  joo.weight = 9;
  product foo;

  movies_t gaa;
  cout << "sizeof(joo) =  " << sizeof(joo) << endl;
  cout << "sizeof(foo) = " << sizeof(foo) << endl;
  cout << "sizeof(gaa) = " << sizeof(gaa) << endl;
  return 0;
}

void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
