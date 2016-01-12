/*+
ID: dianval1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

char necklace[700];

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    unsigned n, i, j, k;
    fin >> n;
    fin >> necklace;
    strcat(necklace, necklace);

    unsigned maximum = 0;
    unsigned lastW = 0;
    unsigned len = 0;

    unsigned leftBeadsStart = 0;
    unsigned leftBeadsEnd = 0;

    unsigned rightBeadsStart= 0;
    unsigned rightBeadsEnd = 0;

    char currentBead;
    i = 0;
    while(necklace[i] == 'w') i++;
    currentBead = necklace[i];


    do
    {
            if(necklace[i] == 'w')
            {
                lastW++;
            }
            else
            {
                lastW = 0;
            }
            i++;
    }while(necklace[i] == currentBead || necklace[i] == 'w');
    rightBeadsStart = 0;
    rightBeadsEnd = i - 1;
    currentBead = necklace[i];


   while(i <= 2 * n - 1);{
        printf("i = %d\n", i);
        leftBeadsEnd = rightBeadsEnd - lastW;
        leftBeadsStart = rightBeadsStart;
        do
        {
            if(necklace[i] == 'w')
            {
                lastW++;
            }
            else
            {
                lastW = 0;
            }
            i++;
        }while(necklace[i] == currentBead || necklace[i] == 'w');

        rightBeadsStart = leftBeadsEnd + 1;
        rightBeadsEnd = i - 1;
        len = leftBeadsEnd - leftBeadsStart + 1 +  rightBeadsEnd - rightBeadsStart + 1;
        if(maximum < len)
            maximum = len;
        currentBead = necklace[i];
    }

    fout << maximum << endl;
    return 0;
}

