// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include <stdio.h>
#include "node.h"
#include "tree.h"

int main(int argc, char * argv[])
{
    FILE * fp;
    node *tree;

//    char str[100];

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

//    fscanf(fp, "%s", str);
//
//    printf("Read: %s\n", str);

    tree = buildTree(fp);

    inOrderTraversal(tree);

    freeTree(tree);

    if (fp != stdin)
    {
        fclose(fp);
    }
    return 0;
}