// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

// This is a program to build a binary search tree and print
// three traversals in three separate files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

int main(int argc, char * argv[])
{
    FILE * fp;
    node *tree;
    char file[30];
    char * filename;

    // Check command line arguments
    if (argc == 1)
    {
        printf("No file given, read from stdin.\n");
        fp = stdin;
        filename = "out";
    }
    else if (argc == 2) // If there is a file listed
    {
//        printf("File listed: %s.fs18\n", argv[argc-1]);
        strcpy(file, argv[1]);
        strcat(file, ".fs18");
        fp = fopen(file, "r");
        filename = argv[1];
    }
    else // too many arguments
    {
        printf("ERROR: takes a single command line argument with a file name\n");
        exit(1);
    }

    // if the file was unable to be opened, error
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


    // Build the tree using buildTree and get a pointer to the root node
    tree = buildTree(fp);

    // Print all three traversals
    preOrderTraversal(tree, filename);
    inOrderTraversal(tree, filename);
    postOrderTraversal(tree, filename);

    // Free memory
    freeTree(tree);

    // Close the file unless the file is stdin
    if (fp != stdin)
    {
        fclose(fp);
    }
    return 0;
}
