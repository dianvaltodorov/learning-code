#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < n - i + 1; j++) cout <<" ";
        for(int k = n - i; k <= n - 1; k++) cout <<"#";
        cout << endl;
    }
    return 0;
}
