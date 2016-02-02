#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

ll n, k;
vector<int> v;
vector<int> m;
vector<int> res;

ll binom(ll a, ll b) {
    ll res = 1;
    for(int i=1; i<=b; ++i) {
        res = res * (a-i+1) / i;
    }
    return res;
}

ll calc(ll best, ll needed) {
    if (best < needed) return 0;
    return binom(best, needed);
}

int main() {
    cin>>n>>k;
    v.resize(n);
    res.resize(n);
    m.resize(n+1);
    m[0] = 0;
    int L=0;
    for(int i=0; i<n; ++i) {
        cin>>v[i];
        int lo, hi;
        lo = 1;
        hi = L;
        while (lo <= hi) {
            int mid = (lo+hi+1)/2;
            if (v[m[mid]] < v[i]) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        int newL = lo;
        m[newL] = i;
        L = max(L, newL);
        res[i] = lo;
    }
//    for(int i=0; i<n; ++i) {
//        cout<<res[i]<<" ";
//    }

    ll r = 0;
    for(int i=0; i<n; ++i) {
        r += calc(res[i]-1, k);
    }
    cout<<r<<endl;
    return 0;
}
