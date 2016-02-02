#include<iostream>
#include<fstream>
#include <limits>

using namespace std;

int main()
{
  int a;
  cout<<"Enter: a ";
  cin >> a;
  cout << numeric_limits<streamsize>::max() << endl;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  char name[10];
  cout << name << endl;
  cout << "Enter card name: ";
  cin.ignore(); // TODO: това защо е нужно да го правя? Изтрива само един символ, какво има в буфера?
  if (!cin)
  {
   cin.clear();
   // TODO: в примерите се използва sync, но то не работи на linux, това става ли като алтернатива? Зачиства докрая на реда(с делимитър EOF) всичко?
   // Този делимътър става ли или да сложа EOF?
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return 0;
}
