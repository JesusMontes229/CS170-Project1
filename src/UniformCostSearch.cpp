#include "UniformCostSearch.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

Node* UniformCostSearch::solve(const Problem& initialState) {
    //comparator function for priority queue (min-heap based on total cost)
    struct CompareNodeCost {
        bool operator()(Node* a, Node* b) {
            return a->getTotalCost() > b->getTotalCost(); //min heap based on total cost
        }
    };

    nodesExpanded = 0;
    maxQueueSize = 0;

    //initialized priority queue to store nodes, ordered by total cost (min-heap)
    priority_queue<Node*, vector<Node*>, CompareNodeCost> pq;

    //creating initial starting node with a g_cost of 0
    int initialHeuristic = startNode->calculateHeuristic(initialState);
    Node* startNode = new Node(initialState, nullptr, 0, initialHeuristic, NONE);
    pq.push(startNode);

    //using unordered map to track minimum cost 
    unordered_map<Problem, int, ProblemHash> cost_so_far; // Assumes Problem has a hash function
    cost_so_far[initialState] = 0;

    while (!pq.empty()) {
        updateMaxQueueSize(pq.size());
        Node* current = pq.top();
        pq.pop();

        //checking for the goal state 
        if (current->getState().isGoal()) {
            return current; 
        }

        nodesExpanded++; //increment nodes expanded

        //generate child nodes and add to the queue if they offer a cheaper path
        vector<Node*> children = current->generateChildren();
        for (int i = 0; i < children.size(); i++) {
            Node* child = children[i];
            int new_cost = current->getGCost() + 1; 

            //checking if this path to the child is cheaper than any previous path
            Problem childState = child->getState();
            if (cost_so_far.find(childState) == cost_so_far.end() || new_cost < cost_so_far[childState]) {
                cost_so_far[childState] = new_cost;
                child->setGCost(new_cost);
                pq.push(child);
            } else {
                delete child; 
            }
        }
    }

    return nullptr;
}
