#include "../headers/AstarMisplacedTile.h"
#include "Node.h"
#include <vector>  //added for the openList
#include <unordered_set>  //added for the closedList
#include <algorithm> //added for sort function

using namespace std;

// helper function 
// uses getTotalCost() function from Node class 
// sorts them by lowest cost to work on nodes that are closer to the goal in terms of f_cost
bool compareNodes(Node* lhs, Node* rhs) {
    return lhs->getTotalCost() < rhs->getTotalCost();
}

// solve function implements the A* misplaced tile algorithm 
// A* algorithm wants to find the lowest cost 
//(f_cost = g_cost (cost from start to current node) + h_cost(counting the number of tiles in the wrong place)) 
Node* AStarMisplacedTile::solve(const Problem& initialState) {
    // create vector of openList for the nodes that we need to generate the cost for 
    // holds the nodes we need to explore
    vector<Node*> openList; 
    // create closedList to track the explored states 
    unordered_set<Problem> closedList;

    // initialize root node with initial g_cost of 0
    // h_cost of calculated heuristic cost with no shift direction 
    Node* root = new Node(initialState, nullptr, 0, root->calculateHeuristic(initialState), ShiftDirection::NONE);
    // adding the root node to the openList 
    openList.push_back(root);

    // initialize maxQueueSize to track the maximum size of the openList
    int maxQueueSize = openList.size();

    // runs this while loop while the openList is not empty 
    // when openList is empty either no solution can be found or we have reached the goal
    while (!openList.empty()) {
        // we sort openList using the compareNodes function (node with lowest f_cost is at the front) 
        sort(openList.begin(), openList.end(), compareNodes);

        // now the node at the front of openList has the lowest cost
        Node* currentNode = openList.front();
        openList.erase(openList.begin()); // then we remove it from openList so that we can evaluate it

        // goal check
        // check if the currentNode is the goalstate
        if (currentNode->getState().isGoal()) {
            // At this point, we have found the goal state
            cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
            return currentNode; // return currentNode if this is the case
        }

        // otherwise, current node is explored and put into closedList
        closedList.insert(currentNode->getState());

        // generate children and explore those nodes
        for (Node* child : currentNode->generateChildren()) {
            // if the child state is explored, in closedList, then delete
            if (closedList.find(child->getState()) != closedList.end()) { 
                delete child; 
                continue;
            }

            // update h_cost based on misplaced tile in the child state
            child->setHCost(child->calculateHeuristic(child->getState()));
            // add child to open list
            openList.push_back(child);

            // update maxQueueSize if the new openList size is larger than before
            if (openList.size() > maxQueueSize) {
                maxQueueSize = openList.size();
            }
        }
    }

    // if no solution is found
    cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
    return nullptr; // this is in the case that no solution is found and we return a nullptr 
}