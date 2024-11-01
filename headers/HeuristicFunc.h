#ifndef HEURISTICFUNC_H
#define HEURISTICFUNC_H

#include "Algorithm.h"

int UniformCostSearchHeuristic(const Problem& initialState);
int EuclideanDistHeuristic(const Problem& initialState);
//int MisplacedTileHeuristic(const Problem& initialState);

#endif 
