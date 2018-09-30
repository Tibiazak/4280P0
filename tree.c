// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#include "tree.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void printNode(node * treePtr, int level, FILE * fp)
{
    fprintf(fp, "%*c%d:%s ", level*2, ' ', (int)strlen(treePtr->values[0]), treePtr->values[0]);
    int i;
    for(i = 1; i < stringMax; i++)
    {
        if(treePtr->values[i][0] != 0)
        {
            fprintf(fp, "%s ", treePtr->values[i]);
        }
    }
    fprintf(fp, "\n");
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

void inOrderRecursive(node * treePtr, int level, FILE * fp)
{
    if(treePtr->left)
    {
        inOrderRecursive(treePtr->left, ++level, fp);
    }
    printNode(treePtr, level, fp);
    if(treePtr->right)
    {
        inOrderRecursive(treePtr->right, ++level, fp);
    }
}

void inOrderTraversal(node * treePtr, char * filename)
{
    strcpy(buf, filename);
    strcat(buf, ".inorder");
    FILE * fp = fopen(buf, "w");
    //check for error

    inOrderRecursive(treePtr, 0, fp);
    fclose(fp);
}

void preOrderRecursive(node * treePtr, int level, FILE * fp)
{
    printf("Preorder level %i\n", level);
    printNode(treePtr, level, fp);
    if(treePtr->left)
    {
        preOrderRecursive(treePtr->left, ++level, fp);
    }
    if(treePtr->right)
    {
        preOrderRecursive(treePtr->right, ++level,  fp);
    }
}

void preOrderTraversal(node * treePtr, char * filename)
{
    strcpy(buf, filename);
    strcat(buf, ".preorder");
    FILE * fp = fopen(buf, "w");
    //check for error

    preOrderRecursive(treePtr, 0, fp);
    fclose(fp);
}

void postOrderRecursive(node * treePtr, int level, FILE * fp)
{
    if(treePtr->left)
    {
        postOrderRecursive(treePtr->left, ++level, fp);
    }
    if(treePtr->right)
    {
        postOrderRecursive(treePtr->right, ++level, fp);
    }
    printNode(treePtr, level, fp);
}

void postOrderTraversal(node * treePtr, char * filename)
{
    strcpy(buf, filename);
    strcat(buf, ".postorder");
    FILE * fp = fopen(buf, "w");
    //check for error

    postOrderRecursive(treePtr, 0, fp);
    fclose(fp);
}


void printParseTree(node *rootP,int level, FILE * fp) {
    if (rootP==NULL) return;
    fprintf(fp, "%*c%d:%s ",level*2,' ',(int)strlen(rootP->values[0]),rootP->values[0]);
    int i;
    for(i = 1; i < stringMax; i++)
    {
        if(rootP->values[i][0] != 0)
        {
            fprintf(fp, "%s ", rootP->values[i]);
        }
    }
    fprintf(fp, "\n");
    printParseTree(rootP->left,level+1, fp);
    printParseTree(rootP->right,level+1, fp);
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