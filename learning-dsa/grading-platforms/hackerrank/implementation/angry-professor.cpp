#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int j = 0; j< n; j++){
           cin >> a[j];
        }
        int onTime = 0;

        for(int j = 0; j < n; j++) {
          if(a[j] <= 0){
            onTime++;
          }
        }
        // cout << onTime << endl;
        if(onTime >= k) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
