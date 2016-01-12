#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Date
{
  int day;
  int month;
  int year;
  int order;
  Date(int d, int m, int y, int o):day(d), month(m), year(y), order(o){};

  bool operator<(const Date& a) const
  {
    if(this->year < a.year) return true;
    else  if(this->year == a.year)
            if(this->month < a.month) return true;
            else  if(this->month == a.month)
                    if(this->day < a.day) return true;
                    else return false;
                  else return false;
          else return false;
  }
};

vector < Date > dates;

int main()
{
  int n, d, m, y;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d.%d.%d", &d, &m, &y);
    dates.push_back(Date(d, m, y, i));
  }
  stable_sort(dates.begin(), dates.end());
  for(int i = 0; i < n; i++)
  {
   printf("%d\n", dates[i].order + 1);
  }
}
