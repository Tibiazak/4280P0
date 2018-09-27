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
int stringMax = 20;

node * createNode()
{
    node* newnode = (node *)malloc(sizeof(node));
    newnode->right = NULL;
    newnode->left = NULL;
    int i;
    for(i = 0; i < stringMax; i++)
    {
        newnode->values[i][0] = 0;
    }
//    printf("initialized first value\n");
    return newnode;
}

void recurseAddTree(node * currentNode, char* string)
{
//    printf("Entered recurseAddTree\n");
    int len = strlen(string);
    if(currentNode->values[0][0] == 0)
    {
//        printf("Add to this node\n");
        strcpy(currentNode->values[0], string);
        return;
    }
//    printf("Getting length of value in current node\n");
    int templen = strlen(currentNode->values[0]);

//    printf("Got value\n");
    if (len == templen)
    {
        printf("Need to add to this node that already exists\n");
        int ptr = 0;
        while(true)
        {
            if(currentNode->values[ptr][0] == 0)
            {
                strcpy(currentNode->values[ptr], string);
                return;
            }
            else
            {
                if( ptr > stringMax)
                {
                    printf("ERROR! Too many strings of the same length. Current max: %i\n", stringMax);
                    exit(1);
                }
                else
                {
                    ptr++;
                }
            }
        }
    }
    else if(len > templen)
    {
//        printf("Needs to go into right subtree\n");
        if(!currentNode->right)
        {
//            printf("No right subtree, creating...\n");
            node * tempnode = createNode();
            strcpy(tempnode->values[0], string);
            currentNode->right = tempnode;
            return;
        }
        else
        {
//            printf("Right subtree exists, recursing\n");
            recurseAddTree(currentNode->right, string);
        }
    }
    else if(len < templen)
    {
//        printf("Needs to go into left subtree\n");
        if(!currentNode->left)
        {
//            printf("No left subtree, creating...\n");
            node * tempnode = createNode();
            strcpy(tempnode->values[0], string);
            currentNode->left = tempnode;
            return;
        }
        else
        {
//            printf("Left subtree exists, recursing\n");
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
    }
//    printf("Exiting buildTree\n");
    return treePtr;
}

void inOrderTraversal(node * treePtr)
{
//    printf("Entering inOrder\n");
    if(treePtr->left)
    {
//        printf("Entering left subtree\n");
        inOrderTraversal(treePtr->left);
    }
    else
    {
//        printf("Skipping left subtree\n");
    }
//    printf("About to print current node:\n");
//    printf("Current node: %s\n", treePtr->value);
    if(treePtr->right)
    {
//        printf("Entering right subtree\n");
        inOrderTraversal(treePtr->right);
    }
    else
    {
//        printf("skipping right subtree\n");
    }
}

void preOrderTraversal(node * treePtr)
{
//    printf("Entering Preorder\n");
//    printf("Current node: %s\n", treePtr->value);
    if(treePtr->left)
    {
        preOrderTraversal(treePtr->left);
    }
    if(treePtr->right)
    {
        preOrderTraversal(treePtr->right);
    }
}

void postOrderTraversal(node * treePtr)
{
//    printf("Entering Postorder\n");
    if(treePtr->left)
    {
        postOrderTraversal(treePtr->left);
    }
    if(treePtr->right)
    {
        postOrderTraversal(treePtr->right);
    }
//    printf("Current node: %s\n", treePtr->value);
}

void printParseTree(node *rootP,int level) {
    if (rootP==NULL) return;
    printf("%*c%d:%-9s ",level*2,' ',(int)strlen(rootP->values[0]),rootP->values[0]); // assume some info printed as string
    printf("\n");
    printParseTree(rootP->left,level+1);
    printParseTree(rootP->right,level+1);
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