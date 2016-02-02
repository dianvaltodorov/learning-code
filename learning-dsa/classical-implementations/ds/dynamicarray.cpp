#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct DynamicArray
{
  int *pData;
  size_t capacity;
  size_t used;
};

void init(DynamicArray* pArr)
{
	pArr->pData = NULL;
	pArr->capacity = 0;
	pArr->used = 0;
}

void free(DynamicArray* pArr)
{
	delete [] pArr->pData;
	pArr->pData = NULL;
	pArr->capacity = 0;
	pArr->used = 0;
}

void reallocate(DynamicArray* pArr, size_t NewSize)
{
	int* pTemp = new int[NewSize];

	for(size_t i = 0; i < std::min(pArr->capacity, NewSize); i++)
		pTemp[i] = pArr->pData[i];

	delete [] pArr->pData;

	pArr->pData = pTemp;
	pArr->capacity = NewSize;
}

void add(DynamicArray* pArr, int Element)
{
	if(pArr->used >= pArr->capacity)
	{
		size_t NewSize = (pArr->capacity == 0 ? 2 : pArr->capacity*2);

		reallocate(pArr, NewSize);
	}

	pArr->pData[pArr->used++] = Element;
}
int getAt(DynamicArray* da, int idx)
{
  return da->pData[idx];
}
void printArrayStatus(DynamicArray* pda)
{
	std::cout
		<< "Array at 0x"   << pda
		<< " buffer at 0x" << pda->pData
		<< " size ("       << pda->used
		<< " / "           << pda->capacity
		<< ")\n";
}

int main()
{
	DynamicArray da;

	init(&da);

	for(int i = 0; i < 100; i++)
	{
		// printArrayStatus(&da);
		add(&da, i);
	}

	printArrayStatus(&da);
  cout <<"item at 2 =" <<  getAt(&da, 2)<<endl;
	free(&da);

	return 0;
}
