#include<stdio.h>
#define MAXN 1000
using namespace std;
int arr[100];
int tree_size;

int calculate_tree_size(int array_size)
{
    int n2 = 1;
    while(n2 < array_size)
    {
      n2*=2;
    }
    return 2 * n2;
}

int sum(int end_idx)
{

  end_idx += tree_size/2;
  int s = 0;
  printf("s = ");
  while(end_idx > 1)
  {
    //printf("idx = %d \n", end_idx);
    if(end_idx % 2 ==1) // проверяваме десен син ли е? Ако е десен прибавяме 11
    {
        printf("%d + ", arr[end_idx - 1]);
        s += arr[end_idx - 1];
    }
    end_idx = end_idx /2;
  }
  return s;
}

int change(int idx, int new_val)
{
  idx += tree_size/2;
  arr[idx] = new_val;

  int s = 0;
  while(idx > 1)
  {
    if(idx % 2 ==1) // проверяваме десен син ли е? Ако е десен прибавяме 11
        arr[idx>>1] = arr[idx] + arr[idx^1];
        idx /= 2;
    idx /2;
  }
}

void printArray(int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    tree_size  =   calculate_tree_size(n);
    printf("%d\n", tree_size);
    for (int i = tree_size / 2; i < tree_size / 2 + n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(tree_size);
    for(int i = tree_size/2 -1 ;i >= 1; i--)
    {   printf("arr[%d] = arr[%d] + arr[%d] = %d + %d = %d\n", i, 2*i, 2*i + 1, arr[2*i], arr[2*i+1],arr[2*i] + arr[2*i+1] );
        arr[i] = arr[2 * i] + arr[2 * i + 1];
    }
    printArray(tree_size);
    printf("\n%d\n", sum(1));
    printf("\n%d\n", sum(2));
    printf("\n%d\n", sum(3));
    printf("\n%d\n", sum(4));
    printf("\n%d\n", sum(5));
    printf("\n%d\n", sum(6));
}

