#include "../headers/AstarSearch.h"
#include <unordered_set>

struct HashProblem {
std::size_t operator()(const Problem& p) const {
    return p.GetValueAtIndex(0)*2 + p.GetValueAtIndex(1)*3+p.GetValueAtIndex(2)*5+
    p.GetValueAtIndex(3)*7 + p.GetValueAtIndex(4)*11+p.GetValueAtIndex(5)*13+
    p.GetValueAtIndex(6)*17 + p.GetValueAtIndex(7)*19+p.GetValueAtIndex(8)*23;
    }
};

//the different heuristics 
int euclideanDistance(const Problem& state) {
    int heuristic = 0;
    //setting a goal state that needs to be achieved
    static const std::vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    for (int i = 0; i < 9; ++i) {
        int value = state.GetValueAtIndex(i);
        if (value != 0) { //skip the blank tile
            int targetIndex = value - 1; 
            int targetX = targetIndex % 3; //column index
            int targetY = targetIndex / 3; //row index 

            int currentX = i % 3; 
            int currentY = i / 3;  

            heuristic += static_cast<int>(sqrt(pow(currentX - targetX, 2) + pow(currentY - targetY, 2))); //calculates the euclidean distance 
        }
    }
    return heuristic;
}

int misplacedTileHeuristic(const Problem& state) {
    int misplacedCount = 0;
    static const std::vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0}; 

    for (int i = 0; i < 9; ++i) {
        if (state.GetValueAtIndex(i) != goalState[i] && state.GetValueAtIndex(i) != 0) {
            //makes sure to count tiles that aren't in the goal state position 
            ++misplacedCount;
        }
    }
    return misplacedCount;
}

bool hasProblemBeenVisited(const unordered_multiset<Problem, HashProblem>& vistedProblems, const Problem& state)
{
    auto range = vistedProblems.equal_range(state);
    for (auto it = range.first; it != range.second; ++it)
    {
        if(*it == state){return true;}
        
    }
    return false;

}


Node* A_STAR_SEARCH(const Problem& initial, int (*heuristicfunc)(const Problem&))
{
    Node* current = new Node(initial, nullptr, 0, heuristicfunc(initial), 0);
    std::priority_queue<Node* , std::vector<Node*>> searchSpace;
    unordered_multiset<Problem, HashProblem> checkedSpace;

    searchSpace.push(current);
    while(!searchSpace.empty())
    {
        //cout<< "entered" << endl;
        current = searchSpace.top();
        searchSpace.pop();
        if(current->getState().isGoal())
        {
            return current;
        }
        //current->printState();
        //cout << endl;
        vector<Node*> expandedChildren = current->generateChildren(heuristicfunc);
        for(int i = 0; i < expandedChildren.size(); ++i)
        {
            if(!hasProblemBeenVisited(checkedSpace, expandedChildren.at(i)->getState()))
            {
                searchSpace.push(expandedChildren.at(i));
            }
        }
        checkedSpace.insert(current->getState());
    }
    return nullptr;
}