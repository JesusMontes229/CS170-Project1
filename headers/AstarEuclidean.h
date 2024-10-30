#ifndef A_STAR_EUCLIDEAN_H
#define A_STAR_EUCLIDEAN_H

#include "Algorithm.h"

class AStarEuclidean : public Algorithm {
public:
    Node* solve(const Problem& initialState) override;
};

#endif 
