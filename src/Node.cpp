#include "../headers/Node.h"
#include <cmath>

Node::Node(const Problem& state, Node* parent, int g_cost, int h_cost, int depth)
    : state(state), parent(parent), g_cost(g_cost), h_cost(h_cost), move(move), depth(depth) {}
Node::Node()
{
    
}

bool Node::operator()(const Node* RHS, const Node* LHS){
    return (RHS->h_cost + RHS->g_cost) < (LHS->h_cost + LHS->g_cost);
}
bool Node::operator==(const Node* RHS){
    return (this->state == RHS->state);
}
bool Node::operator<(const Node* RHS)
{
    return this->getTotalCost() < RHS->getTotalCost();
}

//getters 
int Node::getTotalCost() const {
    return g_cost + h_cost;
}

const Problem& Node::getState() const {
    return state;
}

Node* Node::getParent() const {
    return parent;
}

int Node::getGCost() const {
    return g_cost;
}

int Node::getHCost() const {
    return h_cost;
}

int Node::getDepth() const {
    return depth;
}

/*ShiftDirection Node::getMove() const {
    return move;
}*/

//setters 
void Node::setState(const Problem& state) {
    this->state = state;
}

void Node::setParent(Node* parent) {
    this->parent = parent;
}

void Node::setGCost(int g_cost) {
    this->g_cost = g_cost;
}

void Node::setHCost(int h_cost) {
    this->h_cost = h_cost;
}

void Node::setDepth(int depth) {
    this->depth = depth;
}

void Node::setMove(ShiftDirection move) {
    this->move = move;
}

void Node::printState() const {
    // Print the current board configuration
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i > 0) cout << '\n';
        //cout << (this->state.GetValueAtIndex(i) == 0 ? 'b' : '0' + this->state.GetValueAtIndex(i)) << ' ';
        cout <<  this->state.GetValueAtIndex(i) << ' ';
    }
    cout << '\n';
}
//gets the all the children nodes from the current Node and stores them into a vector 
const vector<Node*> Node::generateChildren(int (*heuristicfunc)(const Problem &)) {
    vector<Node*> children; 
    Node* child = nullptr;
    for (ShiftDirection dir : {LEFT, UP, RIGHT, DOWN}) {
        if (state.CanShift(dir)) {
            children.push_back(new Node(state.Shift(dir), this, this->g_cost + 1 ,heuristicfunc(state.Shift(dir)), this->depth + 1));
        }
        child = nullptr;
    }
    return children;
}

/*int Node::calculateHeuristic(const Problem& state) const {
     int heuristic = 0;
    
    // Loop through each tile
    for (int i = 0; i < 9; ++i) {
        int value = state.GetValueAtIndex(i);
        
        if (value != 0) { // Skip the blank tile
            // Calculate the target index (1-8 mapped to 0-7)
            int targetIndex = value - 1; // 0-based index
            
            // Current position of the tile (row, column)
            int currentX = i % 3; // Column index in current state
            int currentY = i / 3;  // Row index in current state

            // Target position of the tile (row, column)
            int targetX = targetIndex % 3; // Column index in goal state
            int targetY = targetIndex / 3;  // Row index in goal state

            // Calculate Euclidean distance
            heuristic += static_cast<int>(sqrt(pow(currentX - targetX, 2) + pow(currentY - targetY, 2)));
        }
    }
    
    return heuristic;
}*/