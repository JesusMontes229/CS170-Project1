#include "../headers/Algorithm.h"
#include <unordered_set>

struct HashProblem {
std::size_t operator()(const Problem& p) const {
    return p.GetValueAtIndex(0)*2 + p.GetValueAtIndex(1)*3+p.GetValueAtIndex(2)*5+
    p.GetValueAtIndex(3)*7 + p.GetValueAtIndex(4)*11+p.GetValueAtIndex(5)*13+
    p.GetValueAtIndex(6)*17 + p.GetValueAtIndex(7)*19+p.GetValueAtIndex(8)*23;
    }
};

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
    std::priority_queue<Node* , std::vector<Node*>, std::greater<Node*> > searchSpace;
    unordered_multiset<Problem, HashProblem> checkedSpace;

    searchSpace.push(current);
    while(!searchSpace.empty())
    {
        //cout<< "entered" << endl;
        current = searchSpace.top();
        searchSpace.pop();
        if(current->getState().isGoal())
        {
            current->printState();
            cout << endl;
            cout << current->getHCost() << endl;
            cout << current->getGCost() << endl;
            cout << current->getDepth() << endl;
            return current;
        }
        vector<Node*> expandedChildren;
        expandedChildren = current->generateChildren(heuristicfunc);
        for(int i = 0; i < expandedChildren.size(); ++i)
        {
            if(!hasProblemBeenVisited(checkedSpace, expandedChildren.at(i)->getState()))
            {
                searchSpace.emplace(expandedChildren.at(i));
                expandedChildren.at(i) = nullptr;
                
            }
        }
        checkedSpace.emplace(current->getState());
    }
    return nullptr;
}