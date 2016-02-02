#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 20;
const int oo = 1E9;
int tree[2 * MAXN];

void Set(int pos, int val){
  tree[pos + MAXN] = val;
  for(int i = (pos + MAXN) / 2;
      i > 0;i = i / 2){
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
}

int GetHelper(int vr, int lo, int hi,
              int from, int to){
  if(to < lo || hi < from) return 0;
  if(from <= lo && hi <= to)
    return tree[vr];
  int mid = (lo + hi) / 2;
  return GetHelper(2 * vr, lo, mid, from, to) +
         GetHelper(2 * vr + 1, mid + 1, hi, from, to);
}

int Get(int from, int to){
  return GetHelper(1, 0, MAXN - 1, from, to);
}

int main(){
  Set(0, 3);
  Set(1, 1);
  Set(2, 4);
  Set(3, 7);
  Set(4, 7);
  Set(5, 5);

  while(true){
    int a, b;
    cin >> a >> b;
    cout << Get(a, b) << endl;
  }
  return 0;
}
