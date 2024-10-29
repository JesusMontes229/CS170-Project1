#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
    private:
    Node* root; 
    public:
    Tree(Node*);
    Node* Expand(Node*);
};

#endif