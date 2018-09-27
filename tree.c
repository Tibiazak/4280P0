// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include "tree.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char buf[100];
int length;
node tree;

node * createNode()
{
    node* newnode = (node *)malloc(sizeof(node));
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->value[0] = 0;
    return newnode;
}

void recurseAddTree(node * currentNode, char* string)
{
    printf("Entered recurseAddTree\n");
    int len = strlen(string);
    if(currentNode->value[0] == 0)
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
            node * tempnode = createNode();
            strcpy(tempnode->value, string);
            currentNode->right = tempnode;
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
            node * tempnode = createNode();
            strcpy(tempnode->value, string);
            currentNode->left = tempnode;
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
    node * treePtr = createNode();
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
    printf("Exiting buildTree\n");
    return treePtr;
}

void inOrderTraversal(node * treePtr)
{
    printf("Entering inOrder\n");
    if(treePtr->left != NULL)
    {
        printf("Entering left subtree\n");
        inOrderTraversal(treePtr->left);
    }
    else
    {
        printf("Skipping left subtree\n");
    }
    printf("About to print current node:\n");
    printf("Current node: %s\n", treePtr->value);
    if(treePtr->right)
    {
        printf("Entering right subtree\n");
        inOrderTraversal(treePtr->right);
    }
    else
    {
        printf("skipping right subtree\n");
    }
}

void freeTree(node * treePtr)
{
    if(treePtr->left)
    {
        freeTree(treePtr->left);
    }
    if(treePtr->right)
    {
        freeTree(treePtr->right);
    }
    free(treePtr->left);
    free(treePtr->right);
    return;
}