#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>



int main()
{
  vector<int> vec;
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(5);
  vec.push_back(1);
  vec.push_back(100);
  vec.push_back(9);
  vec.push_back(3);
  for(int i = 0; i < vec.size(); i++)
  {
    printf("%d ", vec[i]);
  }
  sort(vec);
  for(int i = 0; i < vec.size(); i++)
  {
    printf("%d ", vec[i]);
  }
  return 0;

}
