#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> v;
  v.assign(10, 0);
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
