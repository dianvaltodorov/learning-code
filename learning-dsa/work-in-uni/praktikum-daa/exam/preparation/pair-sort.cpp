#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>

using namespace std;

bool secondElementSort(pair<int , int> a, pair < int , int > b) { return a.second < b.second;}

int main()
{
  vector< pair < int , int > > vec;
  vec.push_back(make_pair(1, 3));
  vec.push_back(make_pair(2, 6));
  vec.push_back(make_pair(7, 3));
  vec.push_back(make_pair(9, 1));
  vec.push_back(make_pair(6, 5));
  vec.push_back(make_pair(4, 3));
  vec.push_back(make_pair(8, 9));

  sort(vec.begin(), vec.end());
  for(int i = 0; i < vec.size(); i++)
    printf("%d %d\n", vec[i].first, vec[i].second);

  printf("\n");

  sort(vec.begin(), vec.end(), secondElementSort );
  for(int i = 0; i < vec.size(); i++)
    printf("%d %d\n", vec[i].first, vec[i].second);

  printf("\n");
  return 0;
}
