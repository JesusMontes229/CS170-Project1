#include "../headers/Tree.h"

Tree::Tree(const Problem& initialState,  int(*HeuristicFunc)(const Problem&))
{
    root = new Node(initialState, nullptr, 0, HeuristicFunc(initialState), 0);
}
Tree::Tree()
{

}
Node* Tree::GetChild(Node* curr, ShiftDirection dir)
{
    switch(dir)
    {
        case LEFT:
        return curr->ChildrenArr[0];
        break;
        case RIGHT:
        return curr->ChildrenArr[2];
        break;
        case UP:
        return curr->ChildrenArr[1];
        break;
        case DOWN:
        return curr->ChildrenArr[3];
        break;
    }
    return nullptr;
}
Node* Tree::GetParent(Node* curr)
{
    return curr->Parent;
}
Node* Tree::ExpandNode(Node* curr, int(*HeuristicFunc)(const Problem&))
{
    if(curr->ChildrenArr[0] == nullptr && curr->ChildrenArr[1] == nullptr
    && curr->ChildrenArr[2] == nullptr && curr->ChildrenArr[3] == nullptr )
    {
        ShiftDirection dir[] = {LEFT, UP, RIGHT, DOWN};
        for(int i = 0; i < 4; ++i)
        {
            if(curr->state.CanShift(dir[i]))
            {
               curr->ChildrenArr[i] = 
               new Node(curr->state.Shift(dir[i]), curr, curr->g_cost + 1,HeuristicFunc(curr->state.Shift(dir[i])), curr->depth + 1) ;
               //curr->ChildrenArr[i]->printState();
            }
            else
            {
                curr->ChildrenArr[i] = nullptr;
            }
        }
    }
    return nullptr;
}
Node* Tree::getRoot()
{
    return root;
}
Tree::~Tree()
{
    destroyTree(root);
}
void Tree::destroyTree(Node* curr)
{
    if(curr == nullptr){}
    else
    {
        destroyTree(curr->ChildrenArr[0]);
        destroyTree(curr->ChildrenArr[1]);
        destroyTree(curr->ChildrenArr[2]);
        destroyTree(curr->ChildrenArr[3]);

        delete curr;
    }
}