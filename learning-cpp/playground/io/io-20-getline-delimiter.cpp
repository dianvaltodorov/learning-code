#include <iostream>
using namespace std;
int main()
{
  char buffer[100];
  cin.getline(buffer, 10, ','); //TODO:  къде отиват останалата част от символите  коийто съм въвел
  cout << cin << endl;
  cout << buffer << endl;
  cin >> buffer;
  cout << endl;
}
