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
    bool CanLeftShift();
    bool CanRightShift();
    bool CanUpShift();
    bool CanDownShift();
    Problem LeftShift();
    Problem RightShift();
    Problem UpShift();
    Problem DownShift();
    bool CanShift(ShiftDirection);
    Problem Shift(ShiftDirection);
    int GetIndex(int);
    int GetValueAtIndex(int);
        

};
#endif
