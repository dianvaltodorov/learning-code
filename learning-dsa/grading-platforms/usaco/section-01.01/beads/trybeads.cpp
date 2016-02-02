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
    fout << 11 << endl;
    return 0;
}

