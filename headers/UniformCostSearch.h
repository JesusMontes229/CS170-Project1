#ifndef UNIFORMCOSTSEARCH_H
#define UNIFORMCOSTSEARCH_H

#include "Algorithm.h"

class UniformCostSearch : public Algorithm {
public:
    Node* solve(const Problem& initialState) override;
};

#endif 
