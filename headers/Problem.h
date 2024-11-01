#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
enum ShiftDirection {NONE, LEFT, UP, RIGHT, DOWN};
class Problem{
    private:
    std::vector<int> Board;
    int BlankSlateIndex;

    int size;
    public:
    Problem(const int *Array, const int size);
    Problem();
    bool CanShift(ShiftDirection) const;
    Problem Shift(ShiftDirection) const;
    int GetIndex(int);
    int GetValueAtIndex(int);
    int getSize() const;
    bool isGoal() const; 
    bool isSolvable() const; 
    int GetValueAtIndex(int) const;
    bool operator==(const Problem& RHS) const;
        

};
#endif
