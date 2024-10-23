#include "../headers/Problem.h"
#include "../src/Problem.cpp"
#include "gtest/gtest.h"
#include <string>

TEST(CONSTRUCTOR, to_big_element)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 10; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    ASSERT_ANY_THROW(Problem TestBoard(arr, size));
    delete[] arr;
}
TEST(CONSTRUCTOR, duplicate_element)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 4; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    ASSERT_ANY_THROW(Problem TestBoard(arr, size));
    delete[] arr;
    
}
TEST(CONSTRUCTOR, goodState)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 7;  arr[1] = 2; arr[2] = 6; 
    arr[3] = 5;  arr[4] = 4; arr[5] = 3; 
    arr[6] = 1;  arr[7] = 8; arr[8] = 0;
    ASSERT_NO_THROW(Problem TestBoard(arr, size));
}
TEST(SHIFTS, valid_left_shift1)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(LEFT));
    delete[] arr;
}
TEST(SHIFTS, valid_left_shift2)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 0; arr[8] = 8;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(LEFT));
    delete[] arr;
}
TEST(SHIFTS, invalid_left_shift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 0;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(!TestBoard.CanShift(LEFT));
    delete[] arr;
}
TEST(SHIFTS, valid_right_shift1)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 0;  arr[4] = 4; arr[5] = 5; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(RIGHT));
    delete[] arr;
}
TEST(SHIFTS, valid_right_shift2)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 5; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(RIGHT));
    delete[] arr;
}
TEST(SHIFTS, invalid_right_shift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 0; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(!TestBoard.CanShift(RIGHT));
    delete[] arr;
}
TEST(SHIFTS, valid_up_shift1)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 0;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(UP));
    delete[] arr;
}
TEST(SHIFTS, valid_up_shift2)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 5; arr[8] = 8;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(UP));
    delete[] arr;
}
TEST(SHIFTS, invalid_up_shift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 0; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 3; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(!TestBoard.CanShift(UP));
    delete[] arr;
}
TEST(SHIFTS, valid_down_shift1)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 0;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 1;  arr[4] = 4; arr[5] = 5; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(DOWN));
    delete[] arr;
}
TEST(SHIFTS, valid_down_shift2)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 5; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(TestBoard.CanShift(DOWN));
    delete[] arr;
}
TEST(SHIFTS, invalid_down_shift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    Problem TestBoard(arr, size);
    EXPECT_TRUE(!TestBoard.CanShift(DOWN));
    delete[] arr;
}
TEST(SHIFTMOVE, leftshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    Problem TestBoard(arr, size);
    TestBoard = TestBoard.Shift(LEFT);
    EXPECT_EQ(TestBoard.GetValueAtIndex(0), 1);
    EXPECT_EQ(TestBoard.GetValueAtIndex(1), 2);
    EXPECT_EQ(TestBoard.GetValueAtIndex(2), 3);
    EXPECT_EQ(TestBoard.GetValueAtIndex(3), 4);
    EXPECT_EQ(TestBoard.GetValueAtIndex(4), 5);
    EXPECT_EQ(TestBoard.GetValueAtIndex(5), 6);
    EXPECT_EQ(TestBoard.GetValueAtIndex(6), 7);
    EXPECT_EQ(TestBoard.GetValueAtIndex(7), 0);
    EXPECT_EQ(TestBoard.GetValueAtIndex(8), 8);
}
TEST(SHIFTMOVE, invalidleftshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 0;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    ASSERT_ANY_THROW(TestBoard.Shift(LEFT));
   
}
TEST(SHIFTMOVE, rightshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 5; 
    arr[6] = 6;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    TestBoard = TestBoard.Shift(RIGHT);
    EXPECT_EQ(TestBoard.GetValueAtIndex(0), 1);
    EXPECT_EQ(TestBoard.GetValueAtIndex(1), 2);
    EXPECT_EQ(TestBoard.GetValueAtIndex(2), 3);
    EXPECT_EQ(TestBoard.GetValueAtIndex(3), 4);
    EXPECT_EQ(TestBoard.GetValueAtIndex(4), 5);
    EXPECT_EQ(TestBoard.GetValueAtIndex(5), 0);
    EXPECT_EQ(TestBoard.GetValueAtIndex(6), 6);
    EXPECT_EQ(TestBoard.GetValueAtIndex(7), 7);
    EXPECT_EQ(TestBoard.GetValueAtIndex(8), 8);
}
TEST(SHIFTMOVE, invalidrightshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    Problem TestBoard(arr, size);
    ASSERT_ANY_THROW(TestBoard.Shift(RIGHT));
   
}
TEST(SHIFTMOVE, upshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 5; 
    arr[6] = 6;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    TestBoard = TestBoard.Shift(UP);
    EXPECT_EQ(TestBoard.GetValueAtIndex(0), 1);
    EXPECT_EQ(TestBoard.GetValueAtIndex(1), 0);
    EXPECT_EQ(TestBoard.GetValueAtIndex(2), 3);
    EXPECT_EQ(TestBoard.GetValueAtIndex(3), 4);
    EXPECT_EQ(TestBoard.GetValueAtIndex(4), 2);
    EXPECT_EQ(TestBoard.GetValueAtIndex(5), 5);
    EXPECT_EQ(TestBoard.GetValueAtIndex(6), 6);
    EXPECT_EQ(TestBoard.GetValueAtIndex(7), 7);
    EXPECT_EQ(TestBoard.GetValueAtIndex(8), 8);
}
TEST(SHIFTMOVE, invalidlUPshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 0; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 3; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 6;
    Problem TestBoard(arr, size);
    ASSERT_ANY_THROW(TestBoard.Shift(UP));
   
}
TEST(SHIFTMOVE, downshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 0; arr[5] = 5; 
    arr[6] = 6;  arr[7] = 7; arr[8] = 8;
    Problem TestBoard(arr, size);
    TestBoard = TestBoard.Shift(DOWN);
    EXPECT_EQ(TestBoard.GetValueAtIndex(0), 1);
    EXPECT_EQ(TestBoard.GetValueAtIndex(1), 2);
    EXPECT_EQ(TestBoard.GetValueAtIndex(2), 3);
    EXPECT_EQ(TestBoard.GetValueAtIndex(3), 4);
    EXPECT_EQ(TestBoard.GetValueAtIndex(4), 7);
    EXPECT_EQ(TestBoard.GetValueAtIndex(5), 5);
    EXPECT_EQ(TestBoard.GetValueAtIndex(6), 6);
    EXPECT_EQ(TestBoard.GetValueAtIndex(7), 0);
    EXPECT_EQ(TestBoard.GetValueAtIndex(8), 8);
}
TEST(SHIFTMOVE, invalidDownshift)
{
    int size = 9;
    int *arr = new int[9];
    arr[0] = 1;  arr[1] = 2; arr[2] = 3; 
    arr[3] = 4;  arr[4] = 5; arr[5] = 6; 
    arr[6] = 7;  arr[7] = 8; arr[8] = 0;
    Problem TestBoard(arr, size);
    ASSERT_ANY_THROW(TestBoard.Shift(DOWN));
   
}
