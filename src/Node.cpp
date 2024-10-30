#include "Node.h"
#include <cmath>

Node::Node(const Problem& state, Node* parent, int g_cost, int h_cost, ShiftDirection move)
    : state(state), parent(parent), g_cost(g_cost), h_cost(h_cost), move(move) {
    depth = parent;
    if (parent) {
        depth = parent->depth + 1; // Calculate depth based on the parent
    }
}

int Node::GetTotalCost() const {
    return g_cost + h_cost;
}

const Problem& Node::GetState() const {
    return state;
}

Node* Node::GetParent() const {
    return parent;
}

int Node::GetGCost() const {
    return g_cost;
}

int Node::GetHCost() const {
    return h_cost;
}

int Node::GetDepth() const {
    return depth;
}

ShiftDirection Node::GetMove() const {
    return move;
}

void Node::PrintState() const {
    // Print the current board configuration
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i > 0) cout << '\n';
        cout << (state.GetValueAtIndex(i) == 0 ? 'b' : '0' + state.GetValueAtIndex(i)) << ' ';
    }
    cout << '\n';
}

vector<Node> Node::GenerateChildren() const {
    vector<Node> children;
    for (ShiftDirection dir : {LEFT, UP, RIGHT, DOWN}) {
        if (state.CanShift(dir)) {
            Problem newState = state.Shift(dir);
            Node* child = new Node(newState, this, g_cost + 1, CalculateHeuristic(newState), dir);
            children.push_back(child);
        }
    }
    return children;
}

int Node::CalculateHeuristic(const Problem& state) const {
    int heuristic = 0;
    for (int i = 0; i < 9; ++i) {
        int value = state.GetValueAtIndex(i);
        if (value != 0) {
            int targetIndex = value;
            heuristic += abs(i / 3 - targetIndex / 3) + abs(i % 3 - targetIndex % 3);
        }
    }
    return heuristic;
}