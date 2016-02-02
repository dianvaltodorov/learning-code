#include <iostream>
#include <new>

void MyNewHandler()
{
  std::cerr <<"ERROR: allocation failed (entering MyNewHandler()) \n";
  throw std::bad_alloc();
}

int main()
{
  size_t SIZE = 0xFFFFFFF;

  int *p;

  // while(new (std::nothrow) int [SIZE])
  // {
  //   std::cout << "Allocated " << SIZE << " ints.\n";
  // }

  // Vesrion 1
  p = new (std::nothrow) int[SIZE]; // В случая new е функция?
  if(!p)
  {
    std::cerr << "ERROR: allocation failed\n";
  }

  //
  try
	{
		p = new int[SIZE];
	}
	catch (std::bad_alloc& e) // идеята на това е да се подаде по адрес.
	{
		std::cerr << "ERROR: allocation failed (exception: " << e.what() << ")\n";
	}

  //Version 3
  std::set_new_handler(MyNewHandler);
  try
  {
    p = new int[SIZE];
  }
  catch (std::bad_alloc& e) /
  {
    std::cerr << "ERROR: allocation failed (exception: " << e.what() << ")\n";
  }
}
