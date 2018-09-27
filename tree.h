// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include "node.h"

node * buildTree(FILE * fp);
void inOrderTraversal(node * treePtr);

#endif //TREE_H
