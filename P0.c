//
// Created by fof_z on 9/6/2018.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf("No file given, read from stdin");
    }
    else
    {
        printf("File listed: %s", argv[argc-1]);
    }
    return 0;
}