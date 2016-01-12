// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdio.h>
using namespace std;
#define MAXN 200000

struct Date
{
  int seconds;
  int minutes;
  int hours;
  int day;
  int month;
  int year;
  int pos;

  // Date(int hours, int minutes, int seconds, int day, int month, int year) :  hours(hours), minutes(minutes), seconds(seconds), day(day), month(month), year(year){};
  Date(int hours, int minutes, int seconds, int day, int month, int year, int pos) :  hours(hours), minutes(minutes), seconds(seconds), day(day), month(month), year(year), pos(pos){};

  bool operator<(const Date& a) const
  {
    // if(this.year < a.year) return true;
    //   else if(this.month)
  	if(this->year < a.year) return true;
    else  if(this->year == a.year)
            if(this->month < a.month) return true;
            else  if(this->month == a.month)
                    if(this->day < a.day) return true;
                    else if(this->day == a.day)
                            if(this->hours < a.hours) return true;
                            else if(this->hours == a.hours)
                                   if(this->minutes < a.minutes) return true;
                                   else if(this->minutes == a.minutes)
                                          if(this->seconds < a.seconds) return true;
                                          else return false;
                                        else return false;
                                 else return false;
                          else return false;
                  else return false;
          else return false;
  }
};
int main()
{
  vector<Date> dates;
  // Date dates[MAXN];
  // dates.push_back(Date(18, 41, 8, 3, 8, 1993));
	// dates.push_back(Date(18, 12, 1, 9, 6, 1991));
	// dates.push_back(Date(18, 12, 1, 9,12, 1991));
	// dates.push_back(Date(18, 12, 1, 9, 4, 1991));
	// dates.push_back(Date(18, 1, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 5, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 3, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 4, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 2, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 13, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 53, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 23, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 4, 1, 9, 8, 1991));
	// dates.push_back(Date(18, 12, 1, 9, 1, 1991));
	// dates.push_back(Date(18, 12, 1, 9, 12, 1991));
	// dates.push_back(Date(18, 12, 1, 11, 3, 1991));
	// dates.push_back(Date(18, 12, 1, 12, 4, 1991));
	// dates.push_back(Date(18, 41, 17, 19, 9, 1993));
	// dates.push_back(Date(11, 41, 17, 9, 9, 1993));
	// dates.push_back(Date(11, 41, 17, 1, 9, 1993));
	// dates.push_back(Date(14, 41, 17, 4, 9, 1993));
	// dates.push_back(Date(12, 41, 17, 6, 9, 1993));
	// dates.push_back(Date(1, 41, 17, 7, 9, 1993));
	// dates.push_back(Date(5, 41, 17, 2, 9, 1993));
	// dates.push_back(Date(9, 41, 33, 28, 11, 1994));
	// dates.push_back(Date(2, 41, 12, 1, 2, 1999));
	// dates.push_back(Date(3, 31, 9, 3, 3, 1998));
	// dates.push_back(Date(6, 12, 9, 3, 3, 1998));
	// dates.push_back(Date(7, 56, 9, 3, 3, 1998));
	// dates.push_back(Date(9, 45, 9, 3, 3, 1998));
	// dates.push_back(Date(18, 34, 9, 3, 3, 1998));
	// dates.push_back(Date(9, 13, 9, 3, 3, 1998));
	// dates.push_back(Date(0, 34, 9, 3, 3, 1998));
	// dates.push_back(Date(7, 38, 9, 3, 3, 1998));
	// dates.push_back(Date(5, 26, 9, 3, 3, 1998));
	// dates.push_back(Date(7, 37, 9, 3, 3, 1998));
	// dates.push_back(Date(10, 23, 9, 3, 3, 1998));
	// dates.push_back(Date(1, 4, 9, 3, 3, 1998));
	// dates.push_back(Date(12, 41, 9, 3, 3, 1998));
  int n, h, min, s, d, mon, y;;
  scanf("%d", &n);
  // dates.resize(n);

  for(int i = 0; i < n; i++)
  {
    scanf("%d:%d:%d %d.%d.%d", &h, &min, &s, &d, &mon, &y);
    dates.push_back(Date(h, min, s, d, mon, y, i));
    // dates[i] = Date(h, min, s, d, mon, y, i);
  }

  stable_sort (dates.begin(), dates.end());
  // stable_sort (dates, dates + n);

  for(int i = 0; i < n; i++)
  {
    // printf("%2d:%2d:%2d %2d.%2d.%4d\n", dates[i].hours, dates[i].minutes, dates[i].seconds, dates[i].day, dates[i].month, dates[i].year);
    printf("%d\n", dates[i].pos+1);
  }

}
