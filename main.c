// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE * fp;

    if (argc == 1)
    {
        printf("No file given, read from stdin.\n");
        fp = stdin;
    }
    else
    {
        printf("File listed: %s\n", argv[argc-1]);
        fp = fopen(argv[1], "r");
    }
    return 0;
}