// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include "tree.h"
#include "node.h"
#include <string.h>
#include <stdio.h>

char buf[100];
int length;
node * treePtr;
node tree;

void recurseAddTree(node * currentNode, char* string)
{
    printf("Entered recurseAddTree\n");
    int len = strlen(string);
    if((currentNode->value) == NULL)
    {
        printf("Add to this node\n");
        strcpy(currentNode->value, string);
        return;
    }
    printf("Getting length of value in current node\n");
    int templen = strlen(currentNode->value);

    printf("Got value\n");
    if (len == templen)
    {
        printf("Need to add to this node that already exists\n");
    }
    else if(len > templen)
    {
        printf("Needs to go into right subtree\n");
        if(!currentNode->right)
        {
            printf("No right subtree, creating...\n");
            node tempnode;
            strcpy(tempnode.value, string);
            currentNode->right = &tempnode;
            return;
        }
        else
        {
            printf("Right subtree exists, recursing\n");
            recurseAddTree(currentNode->right, string);
        }
    }
    else if(len < templen)
    {
        printf("Needs to go into left subtree\n");
        if(!currentNode->left)
        {
            printf("No left subtree, creating...\n");
            node tempnode;
            strcpy(tempnode.value, string);
            currentNode->left = &tempnode;
            return;
        }
        else
        {
            printf("Left subtree exists, recursing\n");
            recurseAddTree(currentNode->left, string);
        }
    }
}

node * buildTree(FILE * fp)
{
    treePtr = &tree;
    strcpy(treePtr->value, NULL);
    while(fscanf(fp, "%s", buf) != EOF)
    {
        recurseAddTree(treePtr, &buf[0]);
//        length = strlen(buf);
//        if(!treePtr)
//        {
//            printf("Null tree pointer, creating tree\n");
//            tree.left = NULL;
//            tree.right = NULL;
//            strcpy(tree.value, buf);
//            treePtr = &tree;
//        }
//        else
//        {
//            printf("Tree exists, adding data\n");
//            int templen = strlen(treePtr->value);
//            if (length == templen)
//            {
//                printf("Strings are the same length\n");
//            }
//            else if(length > templen)
//            {
//                printf("New string is longer than old string\n");
//                if(!tree.right)
//                {
//                    printf("No right subtree, creating one\n");
//                    node tempnode;
//                    tempnode.right = NULL;
//                    tempnode.left = NULL;
//                    strcpy(tempnode.value, buf);
//                    treePtr->right = &tempnode;
//                }
//                else if(strlen(tree.right->value) >= )
//            }
//            else
//            {
//                printf("New string is shorter than old string\n");
//            }
//        }
    }
    return treePtr;
}
