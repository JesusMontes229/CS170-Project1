#ifndef A_STAR_EUCLIDEAN_H
#define A_STAR_EUCLIDEAN_H

#include "../headers/Algorithm.h"

class AStarEuclidean : public Algorithm {
public:
    Node* solve(const Problem& initialState) override;
    string getBoardString(const Problem& state);
};

#endif 
