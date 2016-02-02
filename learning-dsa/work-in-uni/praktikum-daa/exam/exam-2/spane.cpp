#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> e(100);
int main()
{
  int n, m ,r;
  scanf("%d %d %d", &n, &m, &r);
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &e[i]);
  }
  printf("%d\n%d\n%d\n", n, m, r);
  return 0;
}
