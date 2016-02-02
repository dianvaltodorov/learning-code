#include <iostream>
#include <fstream>


using namespace std;
int main() {
  char filename[FILENAME_MAX + 1];
  cout << "Enter a file name and press ENTER: ";
  cin.getline(filename, FILENAME_MAX);
  ofstream fout(filename);
  if (!fout) {
    cout << filename << " could not be opened.";
    cout << endl;
    return -1;
  }
  cout << filename << " was opened." << endl;
  fout << "I read the" << endl;
  fout << "news today," << endl;
  fout << "ooh boy.";
  fout.close();
  return 0;
}
