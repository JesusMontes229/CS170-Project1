#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Node.h"
#include "Problem.h"
#include "Tree.h"
#include <queue>

Node* A_STAR_SEARCH(Tree&, int (*heuristicfunc)(const Problem&));


#endif 
