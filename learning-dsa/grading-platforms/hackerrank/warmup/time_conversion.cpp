#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int addT = 0;
    if(time[time.length() - 2] == 'A') addT = 0;
    else addT = 12;
    int a = time[0] - '0';
    int b = time[1] - '0';
    int newT = a*10 + b;
    newT = (newT + addT) % 24;
    if(newT <= 9 || ) time[0] = 0;
    else time[0] = newT / 10 + '0';
    time[1] = newT % 10 + '0';
    cout << time.substr(0,8) << endl;
    return 0;
}
