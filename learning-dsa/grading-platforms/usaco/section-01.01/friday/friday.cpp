/*+
ID: dianval1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int occurences[7];

const unsigned jan = 31;
const unsigned mar = 31;
const unsigned apr = 30;
const unsigned may = 31;
const unsigned jun = 30;
const unsigned jul = 31;
const unsigned aug = 31;
const unsigned sep = 30;
const unsigned octo = 31;
const unsigned nov = 30;
const unsigned decem = 31;

bool isLeapYear(unsigned year)
{
    if(year % 4 != 0) return false;
    else if(year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else return true;

}
int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    unsigned N, feb;
    unsigned daysPassed = 13;
    fin >> N;
    for(int i = 1900; i <= 1900 + N - 1; i++)
    {

        if(isLeapYear(i)) feb = 29;
        else feb = 28;

        occurences[daysPassed%7]++;
        daysPassed += jan;
        occurences[daysPassed%7]++;
        daysPassed += feb;
        occurences[daysPassed%7]++;
        daysPassed += mar;
        occurences[daysPassed%7]++;
        daysPassed += apr;
        occurences[daysPassed%7]++;
        daysPassed += may;
        occurences[daysPassed%7]++;
        daysPassed += jun;
        occurences[daysPassed%7]++;
        daysPassed += jul;
        occurences[daysPassed%7]++;
        daysPassed += aug;
        occurences[daysPassed%7]++;
        daysPassed += sep;
        occurences[daysPassed%7]++;
        daysPassed += octo;
        occurences[daysPassed%7]++;
        daysPassed += nov;
        occurences[daysPassed%7]++;
        daysPassed += decem;
    }

    fout << occurences[6] << " " << occurences[0] << " " << occurences[1] << " " << occurences[2] << " " << occurences[3] << " " << occurences[4] << " " << occurences[5]<<endl;
    return 0;
}
