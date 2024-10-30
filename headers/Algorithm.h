#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Node.h"
#include "Problem.h"
#include <queue>

using namespace std;

class Algorithm {
protected:
    // Variables to track the number of nodes expanded and the maximum queue size
    int nodesExpanded = 0;
    int maxQueueSize = 0;

public:
    virtual ~Algorithm() {}
    virtual Node* solve(const Problem& initialState) = 0;
    //get the number of nodes expanded
    int getNodesExpanded() const { return nodesExpanded; }
    //get the maximum queue size encountered
    int getMaxQueueSize() const { return maxQueueSize; }

protected:
    //update the maximum queue size
    void updateMaxQueueSize(int currentQueueSize) {
        if (currentQueueSize > maxQueueSize) {
            maxQueueSize = currentQueueSize;
        }
    }
};

#endif 
