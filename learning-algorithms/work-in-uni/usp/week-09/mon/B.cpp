#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A {
   int a, b;
   bool operator < (const A &r) const {
       return b < r.b;
   }
};

int main() {
   int n;
   cin>>n;
   vector<A> v;
   v.resize(n);
   for(int i=0; i<n; ++i) {
       cin>>v[i].a>>v[i].b;
   }
   sort(v.begin(), v.end());
   int res = 0;
   int to = -1;
   for(int i=0; i<n; ++i) {
       if (v[i].a > to) {
           res++;
           to = v[i].b;
       }
   }
   cout<<res<<endl;
   return 0;
}
