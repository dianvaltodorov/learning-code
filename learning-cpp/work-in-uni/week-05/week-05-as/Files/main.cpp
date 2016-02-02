#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    char str[100]= "Hello World!";
    unsigned int var = 0x12345678;
    unsigned short arr[5] = {0xAB, 0xCD, 0xEF};
    cout << var << endl;
    ofstream file;
    file.open("test.dat");

    if(!file)
    {
        std::cerr << "Cannot open test.dat for writing" << endl;
        return 1;
    }
    file.write((char *)&var, sizeof(int));
    file.write((char *)arr, sizeof(short) * 3);
    file.write(str, strlen(str));
    file.close();


    ifstream iFile;
    iFile.open("test.dat");
    i
    return 0;
}
