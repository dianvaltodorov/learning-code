#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(8);
  v.push_back(9);
  v.push_back(1);
  v.push_back(8);
  v.push_back(7);
  v.push_back(4);

  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << endl;

  sort(v.begin(), v.end(), std::greater<int>());
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << endl;
}
