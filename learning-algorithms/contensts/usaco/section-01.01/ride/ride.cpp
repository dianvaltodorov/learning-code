/*+
ID: dianval1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    char comet[10];
    char group[10];
    fin >> comet;
    fin >> group;
    cout<< comet << endl << group;
    unsigned cometSum = 1;
    unsigned groupSum = 1;
    int i;
    for(i = 0; i < strlen(comet); i++)
    {
        cometSum *= ((unsigned)comet[i] - 'A' + 1);
    }

    for(i = 0; i < strlen(group); i++)
    {
        printf("%d ", ((unsigned)group[i] - 'A' + 1));
        groupSum *= ((unsigned)group[i] - 'A' + 1);
    }

    if(groupSum % 47 == cometSum %47)
    {
        fout<< "GO\n";
    }else
    {
        fout << "STAY\n";
    }
    return 0;
}
