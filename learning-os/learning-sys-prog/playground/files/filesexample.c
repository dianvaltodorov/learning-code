#include <stdio.h>
#include <string.h>

#define BUFFLEN 256

FILE *outfile;

char mybuf[BUFFLEN] ;


int storetofile()
{
    char *instring;

    outfile = fopen("/tmp/yolo.txt", "w+");
    if(!outfile)
    {
        return (-1);
    }
    while(1)
    {
        instring = fgets(mybuf, BUFFLEN, stdin);
        if(instring || strlen(instring) == 0)
        {
            break;
        }

        if(fputs(instring, outfile) < 0) 
        {
            break;
        }
    }
    fclose(outfile);
}
