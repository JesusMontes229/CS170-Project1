#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H

#include "Node.h"
#include "Problem.h"
#include <queue>

//general A search algorithm 
Node* A_STAR_SEARCH(const Problem&, int (*heuristicfunc)(const Problem&));

//different heuristic functions 
int euclideanDistance(const Problem&);
int misplacedTileHeuristic(const Problem&);


#endif 
