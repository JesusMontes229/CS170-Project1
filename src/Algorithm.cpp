#include "../headers/Algorithm.h"
#include <unordered_set>
#include <functional>

namespace std {
    template <>
    struct hash<Node*> {
        std::size_t operator()(const Node& p) const {
            return p.getHCost();
        }
    };
}

Node* A_STAR_SEARCH(const Problem& initial, int (*heuristicfunc)(const Problem&))
{
    Node* current = new Node(initial, nullptr, 0, heuristicfunc(initial), 0);
    std::priority_queue<Node* , std::vector<Node*>> searchSpace;
    unordered_multiset<Node*> checkedSpace;

    searchSpace.push(current);
    while(!searchSpace.empty())
    {
        current = searchSpace.top();
        searchSpace.pop();
        if(current->getState().isGoal())
        {
            return current;
        }
        vector<Node*> expandedChildren = current->generateChildren(heuristicfunc);
        for(int i = 0; i < expandedChildren.size(); ++i)
        {
            searchSpace.push(expandedChildren.at(i));
        }
        checkedSpace.insert(current);
    }
    return nullptr;
}