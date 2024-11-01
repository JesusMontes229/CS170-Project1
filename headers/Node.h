#ifndef NODE_H
#define NODE_H

#include "../headers/Problem.h"
#include <vector>
#include <iostream>

using namespace std;


class Node {
private:
    Problem state;
    Node* parent;
    int g_cost;
    int h_cost;
    int depth;
    //to help keep track of the move direction from current state to parent state
    ShiftDirection move;

    //helper private function for calculating hueristic cost
    //int calculateHeuristic(const Problem& state) const;

public:
    //initializing everyrhting to nothing (constructor, intial state)
    Node (const Problem& state, Node* parent = nullptr, int g_cost = 0, int h_cost, int depth = 0);
    Node();

    //bool operators 
    bool operator()(const Node*, const Node*);
    bool operator==(const Node* );

    //getters
    int getTotalCost() const;
    const Problem& getState() const;
    Node* getParent() const;
    int getGCost() const;
    int getHCost() const;
    int getDepth() const;
    //ShiftDirection getMove() const;

    //setters 
    void setState(const Problem& state);
    void setParent(Node* parent);
    void setGCost(int g_cost);
    void setHCost(int h_cost);
    void setDepth(int depth);
    void setMove(ShiftDirection move);

    void printState() const;
    //create and return all child nodes from current node states
    //for A* and Uniform Cost Search
    const vector<Node*> generateChildren(int (*heuristicfunc)(const Problem &));
};

#endif // NODE_H
