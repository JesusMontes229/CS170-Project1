#include "../headers/Problem.h"
#include <stdexcept>
#include <unordered_map>
Problem::Problem(const int *Array, const int size)
{
    BlankSlateIndex = 0;
    this->size = size;
    Board.resize(size);
    std::unordered_map < int, int> testMap;

    for(int i = 0; i < size; ++i)
    {
        if(testMap.count(Array[i]) > 0 || Array[i] >= size)
        {
            throw std::runtime_error("INVALID ELEMENT IN THE BOARD");
        }
        else{
            testMap[Array[i]] = Array[i];
        }
        
        if(Array[i] == 0){BlankSlateIndex = i;}
        Board.at(i) = Array[i];
    }
}
bool Problem::CanShift(ShiftDirection _direction) const
{
    int shiftcase1, shiftcase2, shiftcase3;
    shiftcase1 = 0;
    shiftcase2 = 0;
    shiftcase3 = 0;
    switch(_direction){
    case LEFT:
    shiftcase1 = 0;
    shiftcase2 = 3;
    shiftcase3 = 6;
    break;
    case UP:
    shiftcase1 = 0;
    shiftcase2 = 1;
    shiftcase3 = 2;
    break;
    case RIGHT:
    shiftcase1 = 2;
    shiftcase2 = 5;
    shiftcase3 = 8;
    break;
    case DOWN:
    shiftcase1 = 6;
    shiftcase2 = 7;
    shiftcase3 = 8;
    break;
    default:
    break;
    }
    if(BlankSlateIndex == shiftcase1 || BlankSlateIndex == shiftcase2 || BlankSlateIndex == shiftcase3){return false;}
    return true;
}
Problem Problem::Shift(ShiftDirection _direction) const
{
    Problem NewBoard = *this;
    if(NewBoard.CanShift(_direction))
    {
        int i = 0;
        switch(_direction){
        case LEFT:
        i = -1;
        break;
        case UP:
        i = -3;
        break;
        case RIGHT:
        i = 1;
        break;
        case DOWN:
        i = 3;
        break;
        default:
        break;
        }
        int BlankHolder = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex) = NewBoard.Board.at(NewBoard.BlankSlateIndex + i);
        NewBoard.Board.at(NewBoard.BlankSlateIndex + i) = BlankHolder;
        
    }
    else{
        throw std::runtime_error("INVALID SHIFT");
    }
    return NewBoard;
}

int Problem::GetIndex(int Value)
{
    for(int i = 0; i < 8; ++i)
    {
        if(Board.at(i) == Value)
        {
            return i;
        }
    }
    return 0;
    
}
int Problem::GetValueAtIndex(int Index) const
{
    return Board.at(Index);
}

//comparing board with the goalState to make sure that we have solved it
bool Problem::isGoal() const {
    static const std::vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    return Board == goalState;
}

//some test cases can't be solved so have a checker here to check that 
bool Problem::isSolvable() const {
    int inversions = 0;
    for (int i = 0; i < Board.size(); ++i) {
        for (int j = i + 1; j < Board.size(); ++j) {
            if (Board[i] && Board[j] && Board[i] > Board[j]) {
                ++inversions;
            }
        }
    }
    return inversions % 2 == 0;
}
Problem::Problem()
{

}
bool Problem::operator==(const Problem& RHS)
{
    for(int i = 0; i < this->size; ++i)
    {
        if(this->Board.at(i) != RHS.Board.at(i))
        {
            return false;
        }
    }
    return true;
}
int Problem::getSize() const
{
    return size;
}