#include "../headers/HeuristicFunc.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <iostream>

int UniformCostSearchHeuristic(const Problem& initialState)
{
    return 1;
}
int EuclideanDistHeuristic(const Problem& initialState)
{
    int heuristicValue = 0;
         for (int i = 0; i < 9; ++i) {
        int value = initialState.GetValueAtIndex(i);
        
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
            heuristicValue = heuristicValue + (int)floor((sqrt(pow((targetX - currentX), 2) + pow((targetY - currentY), 2))));
        }
    }
    //cout << heuristicValue << endl;
    return heuristicValue;
}