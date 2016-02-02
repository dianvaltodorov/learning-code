//#include <iostream>
//
//using namespace std;
//
//typedef long long ll;
//ll k, a, b;
//
//int main() {
//    cin>>k>>a>>b;
//    ll res;
//    if (a*b == 0) {
//        if (b == 0) {
//            b = -a;
//            a = 0;
//        }
//        res = 1 + b / k;
//    } else if (a*b > 0) {
//        if (a < 0) {
//            swap(a, b);
//            a = -a;
//            b = -b;
//        }
//        res = b/k - (a-1)/k;
//    } else {
//        res = (-a)/k + b/k + 1;
//    }
//    cout<<res<<endl;
//    return 0;
//}
