#ifndef A_STAR_MISPLACED_TILE_H
#define A_STAR_MISPLACED_TILE_H

#include "Algorithm.h"

class AStarMisplacedTile : public Algorithm {
public:
    Node* solve(const Problem& initialState) override;
};

#endif 
