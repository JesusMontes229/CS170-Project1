#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
    private:
    Node* root;
    Node* CurrentNode;
    public:
    Tree(Node*);
    ~Tree();
    Node* getCurrentNode();
    Node* Expand(Node*);
};

#endif