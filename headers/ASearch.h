#ifndef ASEARCH_H
#define ASEARCH_H
#include "Tree.h"
#include "Problem.h"
#include <queue>

Problem A_STAR_SEARCH(Tree& InitialState, int (*funct)(Problem)); //search space and heuristic function

#endif