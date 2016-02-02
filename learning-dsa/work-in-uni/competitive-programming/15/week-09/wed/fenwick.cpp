#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int tree[MAXN];

void Add(int pos, int val){
  for(;pos < MAXN;pos += pos & (-pos))
    tree[pos] += val;
}

int PreffixSum(int upto){
  int sum = 0;
  for(;upto > 0;upto -= upto & (-upto))
    sum += tree[upto];
  return sum;
}

int Sum(int from, int to){
  return PreffixSum(to) -
         PreffixSum(from - 1);
}

int main(){
  Add(1, 3);
  Add(2, 1);
  Add(3, 4);
  Add(4, 7);
  Add(5, 5);

  cout << Sum(2, 4) << endl;
  return 0;
}
