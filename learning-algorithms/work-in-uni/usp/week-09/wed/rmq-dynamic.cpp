#include <iostream>
#include <vector>
#include <string> 

using namespace std;

const int MAXN = 1 << 20;
const int LOGMAXN = 21;
int n;
int v[MAXN] = {1, 2, 5, 8, 3, 4, 9, 3};
int R[MAXN][LOGMAXN];

//O(N Log N)
void init(){
  int i, j;
  for(int i = 0; i < n; ++i){
    R[i][0] = i;
  }

  for(j = 1; (1<<j) <= n; ++j){
    for(i = 0; i + (1<<j)-1 < n; ++i){
      if(v[ R[ i ][ j - 1 ] ] < v[ R[ i + ( 1 << (j - 1))][j - 1]]){
        R[i][j] = R[i][j - 1];
      }else{
        R[i][j] = R[i+ (1<<(j-1))][j-1];
      }
    }
  }
}

int query(int b, int e)
{
  int sz = e - b; // i
  int p = 31 - __builtin_clz(sz);
  if(v[R[b][p]] < v[ R [e - (1<<p)][p]]){
    return R[b][p];
  }else{
    return v[ R [e - (1<<p)][p]];
  }
}
int main()
{
  memset(R, -1, sizeof(R));
  n = 8;
  init();
  cout << query(2, 3);
  return 0;
}
