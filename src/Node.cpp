#include "../headers/Node.h"
#include "../headers/Problem.h"

Node::Node(Problem initialState, int (*funct)(Problem initialState))
{
    CurrentState = initialState;
    heuristicCost = funct(initialState);
    edgeCost = 0;
    LeftMove = nullptr;
    RightMove = nullptr;
    UpMove = nullptr;
    DownMove = nullptr;
}
Node::~Node()
{
}
Node* Node::GetChildOfDirection(ShiftDirection Dir)
{
    switch(Dir){
        case RIGHT:
        return RightMove;
        break;
        case LEFT:
        break;
        return LeftMove;
        case UP:
        return UpMove;
        break;
        case DOWN:
        return DownMove;
        break;
        default:
        break;
    }
    return nullptr;
}
bool Node::operator()(const Node* RHS, const Node* LHS)
{
    return (RHS->heuristicCost + RHS->edgeCost) < (LHS->heuristicCost + LHS->edgeCost);
}
bool Node::operator==(const Node* RHS)
{
    return (this->CurrentState == RHS->CurrentState);
}
int Node::getHeuristic(int x)
{
    heuristicCost = x;
}
int Node::setHeuristic() const
{
    return heuristicCost;
}
int Node::getCost(int x)
{
    edgeCost = x;
}
int Node::setCost() const
{
    return edgeCost;
}