/*+
ID: dianval1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


char names[11][15];
int account[11];
unsigned np;

unsigned findIndex(char *currentName)
{
    int i = 0;

    while(i <= np - 1 && strcmp(currentName, names[i]))
    {
        i++;
    }
    return i;
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    //Input number of gift givers;
    fin >> np;

    //Input their names
    for(unsigned i = 0; i <= np - 1; i++)
    {
        fin >> names[i];
    }

    for(unsigned i = 1; i <= np ; i++)
    {
        char currentGiver[15];
        int amountToGive;
        int numberOfGiftReceivers;
        int indexOfGiver;

        fin >> currentGiver;
        fin >> amountToGive;
        fin >> numberOfGiftReceivers;


        indexOfGiver = findIndex(currentGiver);
        account[indexOfGiver] = account[indexOfGiver] - amountToGive;
        for(int i = 1; i <= numberOfGiftReceivers; i++)
        {
            char receiver[15];
            int indexOfReceiver;
            fin >> receiver;
            indexOfReceiver = findIndex(receiver);
            account[indexOfReceiver] += amountToGive / numberOfGiftReceivers;
        }
        if(numberOfGiftReceivers != 0) account[indexOfGiver] += (amountToGive - numberOfGiftReceivers * (amountToGive / numberOfGiftReceivers));
       }
    for(unsigned i = 0; i <= np - 1; i++)
    {
        fout << names[i] << " " << account[i]<<endl;
    }

    return 0;
}
