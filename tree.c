// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include "tree.h"
#include "node.h"
#include <string.h>

char buf[100];
int length;
node * treePtr;
node tree;

node * buildTree(FILE * fp)
{
    fscanf(fp, %s, buf);
    while(buf != EOF)
    {
        length = strlen(buf);
        if(!treePtr)
        {
            printf("Null tree pointer, creating tree\n");
            tree.left = NULL;
            tree.right = NULL;
            strcpy(tree.value, buf);
            treePtr = &tree;
        }
        else
        {
            printf("Tree exists, adding data\n");
            int templen = strlen(treePtr->value);
            if (length == templen)
            {
                printf("Strings are the same length\n");
            }
            else if(length > templen)
            {
                printf("New string is longer than old string\n");
            }
            else
            {
                printf("New string is shorter than old string\n");
            }
        }
    }
    return treePtr;
}