// Joshua Bearden
// CS4280 Project 0
// 9/6/2018

#ifndef NODE_H
#define NODE_H

extern int stringMax = 20;

typedef struct Node{
    struct Node * left;
    struct Node * right;
    char values[stringMax][stringMax];
} node;

#endif //NODE_H
