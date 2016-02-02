#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
/*
5
11.03.2012
28.10.2011
03.03.2012
05.04.2011
11.03.2012
*/
using namespace std;

struct Date
{
	int day, month, year, order;
	Date(){};
	Date(int d, int m, int y, int o): day(d), month(m), year(y), order(o){};
    bool operator<(const Date& d) const
    {
        if(this->year < d.year) return true;
        else
        {
            if(this->year == d.year)
            {
                if(this->month < d.month) return true;
                else
                {
                    if(this->month == d.month)
                    {
                        if(this->day < this->day) return true;
                        return false;
                    }
                    else return false;
                }
            }
            else return false;
        }
    }


};

void sortDates(Date* dates, size_t n)
{
    Date minDate = dates[0];
    for(int i = 0; i < n - 1 ; i++)
    {
        Date minDate = dates[i];
        int idx = i;
        for(int j = i + 1; j < n; j++)
          if(minDate < dates[j])
            {
                minDate = dates[j];
                idx = j;
            }
        swap(idx, i);

    }
}

int main()
{
	int n;
	int d, m, y;
	scanf("%d", &n);
	Date dates[110];
	for(int i = 0; i < n; ++i)
	{
		scanf("%d.%d.%d", &d, &m, &y);
		Date  date(d, m, y, i + 1);
		dates[i] = date;
	}
	//sort(dates, dates + n);
    //sortDates(dates, n);
	for(int i = 0; i < n; i++)
	{
        printf("%d\n", dates[i].order);
	}


	return 0;
}
