// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

int main(int argc, char * argv[])
{
    FILE * fp;
    FILE * outfile;
    node *tree;
    char file[30];
    char * filename;

    if (argc == 1)
    {
        printf("No file given, read from stdin.\n");
        fp = stdin;
        filename = "out";
    }
    else
    {
        printf("File listed: %s\n", argv[argc-1]);
        fp = fopen(argv[1], "r");
        filename = argv[1];
    }

    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        if (size == 0)
        {
            printf("Error, no input!\n");
            exit(1);
        }
        fseek(fp, 0, SEEK_SET);
    }
    else
    {
        printf("Error, invalid file!\n");
        exit(1);
    }


    tree = buildTree(fp);

    preOrderTraversal(tree);
    inOrderTraversal(tree);
    postOrderTraversal(tree);

    printf("about to strcpy\n");
    strcpy(file, filename);
    printf("about to strcat\n");
    strcat(file, ".fs18");
    printf("about to fopen\n");
    outfile = fopen(file, "w");
    printf("about to printparsetree\n");
    printParseTree(tree, 0, outfile);
    freeTree(tree);

    fclose(outfile);

    if (fp != stdin)
    {
        fclose(fp);
    }
    return 0;
}
