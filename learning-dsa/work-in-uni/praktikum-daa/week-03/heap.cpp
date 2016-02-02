#include<stdio.h>
#define MAXN 1000
using namespace std;

//const unsigned n = 10;
int heap[MAXN] = {0,4,1,3,2,16,9,10,14,8,7};

int heap_size = 10;

void printArray()
{
    for(int i = 1; i <= heap_size; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int parent(int i)
{
    return i / 2;
}

int left_child(int i)
{
    return 2 * i;
}

int right_child(int i)
{
    return 2 * i + 1;
}

void max_heapify(int i)
{
    int largest;
    int l = left_child(i);
    int r = right_child(i);

    if(l <= heap_size && heap[l] > heap[i])
    {
        largest = l;
    }else
    {
     largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    //printf("i: heap[%d] = %3d, \nleft = heap[%d] = %3d, right = heap[%d] = %3d, largest = heap[%d] = %3d\n\n", i, heap[i],  l, heap[l],  r, heap[r], largest, heap[largest]);
    if (largest != i)
    {
         int  z = heap[i];
         heap[i] = heap[largest];
         heap[largest] = z;
         max_heapify(largest);
    }
}
void build_max_heap()
{
    for(int i = heap_size / 2 ; i >= 1; i--)
    {
        max_heapify(i);
    }
}
void heapsort()
{
    build_max_heap();
    for(int i = heap_size; i>=1; i--)
    {
         int  z = heap[i];
         heap[i] = heap[1];
         heap[1] = z;

         heap_size --;
         max_heapify(1);
    }
}

int heap_maximum()
{
    return heap[1];
}

void heap_increase_key(int i,int  key)
{
    if(key < heap[i])
        printf("new key is smaller than curent key\n");

    heap[i] = key;
    while(i > 1 && heap[parent(i)] < heap[i])
    {
         int  z = heap[i];
         heap[i] = heap[parent(i)];
         heap[parent(i)] = z;
         i = parent(i);
    }
}

void max_heap_insert(int i, int key)
{
    heap_size++;
    heap[heap_size] = -1000;
    heap_increase_key(a, heap_size, key);
}

int main()
{
    printArray();
    build_max_heap();
    printArray();
    printf("heap maximum = %d\n", heap_maximum());
    printf("heap extract maximum = %d\n", heap_extract_max());
    printArray();
    printf("heap increase key with %d at position 4\n", 3, 4);
    heap_increase_key(3,4);
    printArray();
}
