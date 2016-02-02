#include<iostream>
using namespace std;
int s[1<<20];
int a[1<<20];
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    int all = 0;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
      all += a[i];
      s[i] = all;
    }

    // for(int i = 0; i <= n; i++)
    //   cout << s[i] << " ";
    // cout << endl << all << endl;
    bool success = false;
    for(int i = 1; i <= n; i++)
    {
      if(s[i-1] == all - s[i])
      {
        success = true;
        break;
      }
    }
    cout << (success ? "YES" : "NO") << endl;
  }
}
