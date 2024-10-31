#include "AStarEuclidean.h"
#include <queue>
#include <unordered_set>
#include <vector>
#include <iostream>

struct CompareNodes {
    bool operator()(Node* lhs, Node* rhs) {
        return (lhs->getTotalCost() > rhs->getTotalCost());
    }
};

//converts the board state to a string
string AStarEuclidean::getBoardString(const Problem& state) {
    string boardString;
    for (int i = 0; i < state.Board.size(); i++) {
        boardString += to_string(state.GetValueAtIndex(i)) + ",";
    }
    return boardString;
}

Node* AStarEuclidean::solve(const Problem& initialState) {
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;
    unordered_set<string> closedSet; 

    //initializing the first node
    Node* startNode = new Node(initialState, nullptr, 0, calculateHeuristic(initialState), NONE);
    openSet.push(startNode);
    updateMaxQueueSize(1);

    while (!openSet.empty()) {
        Node* currentNode = openSet.top();
        openSet.pop();
        nodesExpanded++;

        //checks if we have reached the goal
        if (currentNode->getState().isGoal()) {
            return currentNode; // Goal found
        }

        //gets a string representation of the board state for the closed set
        string boardString = getBoardString(currentNode->getState());
        if (closedSet.find(boardString) != closedSet.end()) {
            delete currentNode;
            continue;
        }

        closedSet.insert(boardString);

        //generates children and explore
        vector<Node*> children = currentNode->generateChildren();
        for (size_t i = 0; i < children.size(); i++) {
            //pushing the child node to the open set
            openSet.push(children[i]);
            updateMaxQueueSize(openSet.size());
        }

        delete currentNode;
    }

    return nullptr;
}

