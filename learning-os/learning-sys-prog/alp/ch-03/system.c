#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int return_value;
    return_value = system("ls -l");
    return return_value;
}
