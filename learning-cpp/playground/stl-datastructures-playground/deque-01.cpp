#include <iostream>
#include <deque>

int main()
{
  unsigned int i;

  // Constructors:
  std::deque<int> first;
  std::deque<int> second (17, 100);
  std::deque<int> third (second.begin(), second.end());
  std::deque<int> fourth(third);
  std::deque<int> sixth (10);

  int myints[] = {16, 2, 77, 29};
  std::deque<int> fifth (myints, myints + sizeof(myints)/sizeof(int));

  // Iterators
  std::cout << "The contents of the fifth are:";
  for(std::deque<int>::iterator it = fifth.begin(); it!=fifth.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
  std::cout << "The contents of the sixth are:";
  for(std::deque<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
    std::cout << ' ' << *it;

  //Capacity
  std::cout << '\n';
  std::deque<int> seventh (3);
  std::deque<int> eigth (5);
  seventh = eigth;
  eigth = std::deque<int>();
  std::cout << "Size of first: " << int(seventh.size()) << '\n';
  std::cout << "Size of second: " << int(eigth.size()) << '\n';


  std::deque<int> nineth;
  for(int i = 1; i <= 5; i++) nineth.push_back(i);
  std::cout << "Nineth deque contains: ";

  std::deque<int>::iterator it = nineth.begin();
  while(it != nineth.end())
    std::cout << " " << *it++;

  std::cout << '\n';
  std::deque<int> tenth(5);

  std::cout << "The size of first is: " << first.size() << '\n';
  std::cout << "The maximum size of first is: " << first.max_size() << '\n';
  first.resize(10);
  std::cout << "The size of first after resizing to 10 is: " << first.size() << '\n';

  //Element access
  std::deque<int> eleventh;
  eleventh.push_back(1);
  eleventh.push_back(3);
  eleventh.push_back(2);
  eleventh.push_back(9);
  eleventh.push_back(7);

  std::cout << "Eleventh deque contains: ";
  for(std::deque<int>::iterator it = eleventh.begin(); it!= eleventh.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The element at the front of eleventh is: " << eleventh.front() << '\n';
  std::cout << "The element at the back of eleventh is: " << eleventh.back() << '\n';

  //Modifiers
  eleventh.pop_back();
  eleventh.pop_front();
  std::deque<int>::iterator itEleventh = eleventh.begin();
  ++itEleventh;
  eleventh.insert(itEleventh, 10);
  eleventh.insert(++itEleventh, 3, 200);
  std::cout << "Eleventh deque contains: ";
  for(std::deque<int>::iterator it = eleventh.begin(); it!= eleventh.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The size of eleventh is: " << eleventh.size() << '\n';
  eleventh.clear();
  std::cout << "The size of eleventh after clear() is: " << eleventh.size() << '\n';
  return 0;

}
