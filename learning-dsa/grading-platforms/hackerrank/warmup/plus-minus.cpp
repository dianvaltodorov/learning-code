#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }

    int zeros;
    int pos;
    int negs;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0) zeros++;
        else if (arr[i] > 0) pos++;
             else negs++;
    }

    cout << pos/ (double)n << endl;
    cout << negs/(double)n << endl;
    cout << zeros/(double)n << endl;
    return 0;
}
