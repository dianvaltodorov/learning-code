#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ofstream foo;
    foo.open ("example.txt");
    foo << "Writing this to a file.\n";
    foo.close();


//    ifstream ree;
//    ree.open("example.txt");
//    char buff[1024];
//    ree.getline(buff, 1024, "\n\t ");
//    cout << buff  << endl;
//    ree.close();


    std::ifstream jaa("FN.txt");
    char buff[1024];
    int fn;

    if(!jaa)
    {
        cerr << "...";
        return -1;
    }

    while(jaa)
    {
        jaa >> fn;
        cout << fn;
        jaa.getline(buff, 1024, "\n");
    }

    return 0;
}
