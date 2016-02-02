#include <iostream>
#include <algorithm>
using namespace std;

const int NOT_FOUND = -1;
int binarySearch(pair<int, int> * a, const int n, int x)
{
    int l = 0;
    int r = n;

    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if(x == a[m].first) return a[m].second;
        else if(x < a[m].first) r = m - 1;
        else l = m + 1;
    }
    return NOT_FOUND;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        int n;
        pair<int, int> c[10];
        cin >> m >> n;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            c[i] = make_pair(temp, i);
        }

        sort(c, c+n);
        for(int i = 0; i < n; i++)
        {
            int pos = binarySearch(c, n - i, m - c[i].first);
            if(pos != NOT_FOUND)
            {
                cout << i + 1 << " " << pos + 1 << " " << endl;
                break;
            }

        }

    }
}
