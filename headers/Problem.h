#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
enum ShiftDirection {LEFT, UP, RIGHT, DOWN};
class Problem{
    private:
    std::vector<int> Board;
    int BlankSlateIndex;

    public:
    Problem(const int *Array, const int size);
    bool CanShift(ShiftDirection);
    Problem Shift(ShiftDirection);
    int GetIndex(int);
    int GetValueAtIndex(int);
    bool isGoal() const; 
    bool isSolvable() const; 
    
        

};
#endif
