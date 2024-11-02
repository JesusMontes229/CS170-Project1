#ifndef TREE_H
#define TREE_H
#include "Node.h"
class Tree{
    public:
    Tree(const Problem&,  int(*HeuristicFunc)(const Problem&));
    Tree();
    Node* GetChild(Node*, ShiftDirection);
    Node* GetParent(Node*);
    Node* ExpandNode(Node*, int(*HeuristicFunc)(const Problem&));
    Node* getRoot();
    ~Tree();
    private:
    Node* root;
    void destroyTree(Node*);


};


#endif