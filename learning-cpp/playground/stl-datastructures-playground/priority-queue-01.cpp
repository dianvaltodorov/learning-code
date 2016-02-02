#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include <algorithm>
#include <cassert>

class Person
{
  public:
    int age;
    int weight;
    int height;
};


int main()
{
  std::priority_queue<int> q1;
  int a[100] = {1,2,3,4,1,2,3,4,1,2,4,5,6,4,7};
  for(int i = 0; i < 10; i++)
    q1.push(-1 * a[i]);

  std::cout << "Contents of q1: " << '\n';
  std::cout << q1.empty() << '\n';
  while(!q1.empty())
  {
    std::cout << abs(q1.top()) << " ";
    q1.pop();
  }
  std::cout << '\n';

  std::priority_queue<int> q2;
  int b[100] = {8,7,2,1,3,4,2,4,1,1,2,3,4,3,3,2,1,2,13};
  for(int i = 0; i < 10; i++)
    q2.push(a[i]);

  std::cout << "Contents of q2: " << '\n';
  while(!q2.empty())
  {
    std::cout << q2.top() << " ";
    q2.pop();
  }
  std::cout << '\n';

  std::priority_queue<int> q3;
  q3.push(1);
  q3.push(4);
  q3.push(2);
  q3.push(8);
  q3.push(5);
  q3.push(7);


  return 0;
}
