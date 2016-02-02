#include <algorithm>
#include <iostream>
#include <set>

int main()
{
  std::set<std::string> first;
  std::cout << "Adding 'Hello' and 'World' to the set twice" << std::endl;

  first.insert("Hello");
  first.insert("World");
  first.insert("Hello");
  first.insert("World");

  std::cout << "Set contains: ";
  while (!first.empty()) {
    std::cout << ' ' << *first.begin();
    first.erase(first.begin());
  }
  std::cout << "\n";
  int a[] = {10000,1,2,3,1,12,3,2,2,3,10000000,4,1,2,3,2,2,3,1,2,32,2,1,2,1,};

  std::set<int> second(a, a+20);
  std::cout << "Size of second: " << second.size() << "\n";
  std::set<int>::iterator p = second.begin();
  while(p!=second.end()) std::cout << *p++ << " ";
  std::cout << "\n";
  return 0;
}
