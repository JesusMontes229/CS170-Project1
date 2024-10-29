#ifndef NODE_H
#define NODE_H
#include "Problem.h"


class Node {
    public: 
    Node(Problem, int (*funct)(Problem));
    ~Node();
    Node* GetChildOfDirection(ShiftDirection);
    bool operator()(const Node*, const Node*);
    bool operator==(const Node* );
    int getHeuristic(int); 
    int setHeuristic() const;
    int getCost(int);
    int setCost() const;
    Problem GetProblem() const;
    Problem SetProblem(Problem);
    private:
    Problem CurrentState;
    int edgeCost;
    int heuristicCost;
    Node* LeftMove;
    Node* RightMove;
    Node* UpMove;
    Node* DownMove;

};

#endif