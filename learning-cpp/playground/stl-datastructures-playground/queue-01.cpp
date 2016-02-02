#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue

int main()
{
  std::queue <int> first;
  std::queue <int> second;

  std::deque <int> mydeck (3,100);
  std::list <int> mylist (2,200);

  std::queue <int> third(mydeck);
  std::queue <int> fourth();

  std::queue < int, std::list <int> >  fifth;
  std::queue < int, std::list <int> > sixth (mylist);

  first.push(1);
  first.push(2);
  first.push(3);
  first.push(5);
  first.push(6);
  first.push(8);

  std::cout << "The size of first is: " << first.size() << '\n';
  std::cout << "The size of second is " << second.size() << '\n';
  std::cout << "The result from sizeof() on first is: " << sizeof(first) << '\n';
  std::cout << "The result from sizeof() on second is: " << sizeof(second) << '\n';
  std::cout << "Is firts empty? " << first.empty() << '\n';

  std::cout << "Contents of first: ";
  while(!first.empty())
  {
    std::cout << ' ' << first.front();
    first.pop();
  }
  std::cout << '\n';
  second.push(100); second.push(200); second.push(400);

  std::cout << "Contents of second: ";
  while(!second.empty())
  {
    std::cout << ' ' << second.front();
    second.pop();
  }
  std::cout << '\n';

  return 0;
}
