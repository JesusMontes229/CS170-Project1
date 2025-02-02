#include "../headers/Algorithm.h"
#include <unordered_set>
#include <functional>

struct HashProblem {
std::size_t operator()(const Problem& p) const {
    return p.GetValueAtIndex(0)*2 + p.GetValueAtIndex(1)*3+p.GetValueAtIndex(2)*5+
    p.GetValueAtIndex(3)*7 + p.GetValueAtIndex(4)*11+p.GetValueAtIndex(5)*13+
    p.GetValueAtIndex(6)*17 + p.GetValueAtIndex(7)*19+p.GetValueAtIndex(8)*23;
    }
};
struct NodeComp{
    bool operator()(const Node* LHS, const Node* RHS) const
    {
        return LHS->getTotalCost() > RHS->getTotalCost();
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
void ExpandSpace(std::priority_queue<Node* , std::vector<Node*>, NodeComp>& Search, unordered_multiset<Problem, HashProblem>& dump,
int (*heuristicfunc)(const Problem&), Node* curr, Tree& T)
{
    //cout << "visted ExpandSpace" << endl 
    //Node* ChildCompare = nullptr;
    T.ExpandNode(curr, heuristicfunc);
    for(int i = 0; i < 4; ++i)
    {
        if(curr->ChildrenArr[i] != nullptr)
        {
            //cout << "added to search" << endl;
            //ChildCompare = curr->ChildrenArr[i];
            if(!hasProblemBeenVisited(dump, curr->ChildrenArr[i]->state))
            {
                Search.emplace(curr->ChildrenArr[i]);
                dump.emplace(curr->ChildrenArr[i]->state);

            }
            
 
        }
    }
}
Node* A_STAR_SEARCH(Tree& T, int (*heuristicfunc)(const Problem&))
{
    Node* current = T.getRoot();
    std::priority_queue<Node* , std::vector<Node*>, NodeComp> searchSpace;
    unordered_multiset<Problem, HashProblem> checkedSpace;
    T.maxQueueSize = searchSpace.size();
    searchSpace.push(current);
    while(!searchSpace.empty())
    {
        current = searchSpace.top();
        searchSpace.pop();
        //cout << "current top t cost " << current->getTotalCost() << endl;
        if(current->state.isGoal())
        {
            //current->printState();
            //cout<< current->g_cost << endl;
            //cout <<  "checkedSpace" <<checkedSpace.size() << endl;
            return current; //173980

        }
        //current->printState();
        //cout<< current->g_cost << endl;
        ExpandSpace(searchSpace, checkedSpace, heuristicfunc, current, T);
        checkedSpace.emplace(current->state);
        if(T.maxQueueSize < searchSpace.size())
        {
            T.maxQueueSize = searchSpace.size();
        }
        
    }
    return nullptr;
}
/*
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
*/