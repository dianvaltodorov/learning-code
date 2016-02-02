#include<iostream>
#include<algorithm>

using namespace std;

bool isSorted(char x *, size_t n)
{
  for(size_t i = 0; i < n; i++)
}
int main()
{
  int t;
  cin >> t;
  for(size_t i = 0; i < t; t++)
  {
    char a[100][100];
    int n;
    cin >> n;
    for(size_t j = 0; j < n; j++)
    {
      cin >> a[j];
    }

    for(size_t j = 0; j < n; j++)
    {
      sort(a[j], a[j] + n);
    }

    for(size_t j = 0; j < n; j++)
    {
      cout << a[j] << endl;
    }

    for(int i = 0; i < n; i++)
    {

    }
  }
}
