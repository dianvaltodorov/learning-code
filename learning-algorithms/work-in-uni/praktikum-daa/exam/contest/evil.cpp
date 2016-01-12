#include <stdio.h>
#include <vector>
#include <algorithm>

typedef unsigned long long llu;

using namespace std;

bool cmp(pair<llu , llu> a, pair < llu , llu > b)
{
  return a.second < b.second;
}

int main()
{
  llu n, m, x, y;
  vector< pair < llu, llu > > v;
  scanf("%llu %llu ",&n , &m);
  v.resize(m);

  for(int i = 0; i < m; i++)
  {
    scanf("%llu %llu", &x, &y);
    v[i] = make_pair(x, y);
  }

  sort(v.begin(), v.end(), cmp);
  // for(int i = 0 ; i < v.size(); i++)
  //   printf("%llu %llu\n", v[i].first, v[i].second);
  // printf("\n");

  llu ans = 0;
  llu beg = v[0].first;
  llu end = v[0].second;
  for(int i = 1; i < v.size(); i++)
  {
      printf("%llu %llu \t beg = %llu, end = %llu\n", v[i].first, v[i].second, beg, end);

      if(v[i].first <= end)
      {
        if(v[i].second > end)
          end = v[i].second;

        if(v[i].first < beg)
          beg = v[i].first;
      }
      else
      {
        ans = ans + (end - beg + 1);
      //  printf("%llu\n", ans);
        beg = v[i].first;
        end = v[i].second;
      }
  }
  ans = ans +  (end - beg + 1);
  printf("%llu\n", ans);
}
