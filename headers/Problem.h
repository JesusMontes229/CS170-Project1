#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>
enum ShiftDirection {LEFT, UP, RIGHT, DOWN};
class Problem{
    private:
    std::vector<int> Board;
    int BlankSlateIndex;
    int size;
    public:
    Problem(const int *Array, const int size);
    Problem();
    bool operator==(const Problem&);
    bool CanShift(ShiftDirection);
    Problem Shift(ShiftDirection);
    int GetIndex(int);
    int GetValueAtIndex(int);
        

};
#endif
