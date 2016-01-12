#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;

/*
 * Complete the function below.
 */
void OutputMostPopularDestination(int count) {
  std::map <string, int> cities;
  string city;
  for(int i = 1; i <= count; i++)
  {
    cin >> city;
    cities[city]++;
  }
  std::map<string,int>::iterator it = cities.begin();
  pair <string , int> res;
  res.first = it->first;
  res.second = it->second;
  ++it;
  for (it; it != cities.end(); ++it){
    //  std::cout << it->first << "  => " << it->second << '\n';
      if(it->second > res.second)
      {
        res.first = it->first;
        res.second = it->second;
      }
  }
  cout << res.first << endl;
}


int main()
{
  int _count;
  cin >> _count;
  OutputMostPopularDestination(_count);
  return 0;
}
