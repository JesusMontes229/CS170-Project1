#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Node.h"
#include "Problem.h"
#include <queue>

Node* A_STAR_SEARCH(const Problem&, int (*heuristicfunc)(const Problem&));


#endif 
