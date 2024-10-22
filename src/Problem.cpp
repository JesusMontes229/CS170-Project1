#include "../headers/Problem.h"
#include <stdexcept>
Problem::Problem(const int *Array, const int size)
{
    BlankSlateIndex = 0;
    Board.resize(size);
    for(int i = 0; i < size; ++i)
    {
        if(Array[i] == 0){BlankSlateIndex = i;}
        Board.at(i) = Array[i];
    }
}
bool Problem::CanLeftShift()
{
    if(BlankSlateIndex == 0 || BlankSlateIndex == 3 || BlankSlateIndex == 6){return false;}
    return true;
}
bool Problem::CanRightShift()
{
    if(BlankSlateIndex == 2 || BlankSlateIndex == 5 || BlankSlateIndex == 8){return false;}
    return true;
}
bool Problem::CanUpShift()
{
    if(BlankSlateIndex == 0 || BlankSlateIndex == 1 || BlankSlateIndex == 2){return false;}
    return true;
}
bool Problem::CanDownShift()
{
    if(BlankSlateIndex == 6 || BlankSlateIndex == 7 || BlankSlateIndex == 8){return false;}
    return true;
}
Problem Problem::LeftShift()
{
    Problem NewBoard = *this;
    if(this->CanLeftShift())
    {
        int BlankHolder = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex - 1) = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex) = BlankHolder;
        
    }
}
Problem Problem::RightShift()
{
    Problem NewBoard = *this;
    if(this->CanLeftShift())
    {
        int BlankHolder = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex + 1) = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex) = BlankHolder;
        
    }
}
Problem Problem::UpShift()
{
    Problem NewBoard = *this;
    if(this->CanLeftShift())
    {
        int BlankHolder = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex - 3) = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex) = BlankHolder;
        
    }
}
Problem Problem::DownShift()
{
    Problem NewBoard = *this;
    if(this->CanLeftShift())
    {
        int BlankHolder = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex + 3) = NewBoard.Board.at(NewBoard.BlankSlateIndex);
        NewBoard.Board.at(NewBoard.BlankSlateIndex) = BlankHolder;
        
    }
}
int Problem::GetIndex(int)
{

}
int Problem::GetValueAtIndex(int)
{

}