#include "../headers/Problem.h"
#include <stdexcept>
#include <unordered_map>
Problem::Problem(const int *Array, const int size)
{
    BlankSlateIndex = 0;
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
bool Problem::CanShift(ShiftDirection _direction)
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
Problem Problem::Shift(ShiftDirection _direction)
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
int Problem::GetValueAtIndex(int Index)
{
    return Board.at(Index);
}