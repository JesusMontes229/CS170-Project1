#include "UniformCostSearch.h"

Node* UniformCostSearch::solve(const Problem& initialState) {
    nodesExpanded = 0;
    maxQueueSize = 0;

    // Create a priority queue for nodes
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;

    // Create the starting node
    Node* startNode = new Node(initialState);
    pq.push(startNode);

    while (!pq.empty()) {
        // Update maximum queue size
        updateMaxQueueSize(pq.size());

        // Get the node with the lowest cost
        Node* current = pq.top();
        pq.pop();

        //check if the current node is the goal state
        if (current->getState().isGoal()) {
            return current; //return the solution node
        }

        nodesExpanded++; //increments nodes expanded

        //generate child nodes and add to the queue
        vector<Node*> children = current->generateChildren();
        for (Node* child : children) {
            pq.push(child);
        }
    }
    return nullptr; 
}
