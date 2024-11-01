#include "../headers/Problem.h"
#include "../src/Problem.cpp"
#include "../headers/Node.h"
#include "../src/Node.cpp"
#include "../headers/AStarSearch.h"
#include "../src/AStarSearch.cpp"
#include "gtest/gtest.h"
#include <string>

int h(const Problem& t)
{
    return 1;
}

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
    delete[] arr;
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
   delete[] arr;
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
    EXPECT_EQ(TestBoard.GetValueAtIndex(8), 8); delete[] arr;
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
   delete[] arr;
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
    delete[] arr;
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
   delete[] arr;
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
    delete[] arr;
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
    delete[] arr;
}
TEST(PROBLEM_EQ, not_equal)
{
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 3; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 6; 
    arr1[6] = 7;  arr1[7] = 8; arr1[8] = 0;
    Problem TestBoard1(arr1, size);
    int *arr2 = new int[9];
    arr2[0] = 1;  arr2[1] = 2; arr2[2] = 3; 
    arr2[3] = 4;  arr2[4] = 5; arr2[5] = 0; 
    arr2[6] = 7;  arr2[7] = 8; arr2[8] = 6;
    Problem TestBoard2(arr2, size);
    EXPECT_FALSE(TestBoard1 == TestBoard2);  
    delete[] arr1;
    delete[] arr2;
}
TEST(PROBLEM_EQ, equal)
{
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 3; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 6; 
    arr1[6] = 7;  arr1[7] = 8; arr1[8] = 0;
    Problem TestBoard1(arr1, size);
    int *arr2 = new int[9];
    arr2[0] = 1;  arr2[1] = 2; arr2[2] = 3; 
    arr2[3] = 4;  arr2[4] = 5; arr2[5] = 6; 
    arr2[6] = 7;  arr2[7] = 8; arr2[8] = 0;
    Problem TestBoard2(arr2, size);
    EXPECT_TRUE(TestBoard1 == TestBoard2);  
    delete[] arr1;
    delete[] arr2;
}

TEST(ASTAR_SEARCH, test1)
{
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 0; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 3; 
    arr1[6] = 7;  arr1[7] = 8; arr1[8] = 6;
    Problem TestBoard1(arr1, size);
    ASSERT_TRUE(A_STAR_SEARCH(TestBoard1, h) != nullptr);  
    ASSERT_TRUE(A_STAR_SEARCH(TestBoard1, h)->getState().isGoal());  
    delete[] arr1;
}
TEST(ASTAR_SEARCH, test2)
{
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 8;  arr1[1] = 7; arr1[2] = 1; 
    arr1[3] = 6;  arr1[4] = 0; arr1[5] = 2; 
    arr1[6] = 5;  arr1[7] = 4; arr1[8] = 3;
    Problem TestBoard1(arr1, size);
    ASSERT_TRUE(A_STAR_SEARCH(TestBoard1, h) != nullptr);  
    ASSERT_TRUE(A_STAR_SEARCH(TestBoard1, h)->getState().isGoal());  
    delete[] arr1;
}
TEST(ASTAR_SEARCH, test3_impossible)
{
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 3; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 6; 
    arr1[6] = 8;  arr1[7] = 7; arr1[8] = 0;
    Problem TestBoard1(arr1, size);
    ASSERT_TRUE(A_STAR_SEARCH(TestBoard1, h) == nullptr);   
    delete[] arr1;
}

//TESTING EUCLIDEAN HEURISTIC
TEST(ASTAR_SEARCH, testEuclideanDistance1) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 0; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 3; 
    arr1[6] = 7;  arr1[7] = 8; arr1[8] = 6;
    
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, euclideanDistance);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}

TEST(ASTAR_SEARCH, testEuclideanDistance2) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 8;  arr1[1] = 7; arr1[2] = 1; 
    arr1[3] = 6;  arr1[4] = 0; arr1[5] = 2; 
    arr1[6] = 5;  arr1[7] = 4; arr1[8] = 3; 
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, euclideanDistance);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}

TEST(ASTAR_SEARCH, testEuclideanDistance3) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 3; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 6; 
    arr1[6] = 8;  arr1[7] = 7; arr1[8] = 0;
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, euclideanDistance);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}

//TESTING MISPLACED TILE HEURISTIC
TEST(ASTAR_SEARCH, testMisplacedTile1) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 0; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 3; 
    arr1[6] = 7;  arr1[7] = 8; arr1[8] = 6;
    
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, misplacedTileHeuristic);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}

TEST(ASTAR_SEARCH, testMisplacedTile2) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 8;  arr1[1] = 7; arr1[2] = 1; 
    arr1[3] = 6;  arr1[4] = 0; arr1[5] = 2; 
    arr1[6] = 5;  arr1[7] = 4; arr1[8] = 3; 
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, misplacedTileHeuristic);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}

TEST(ASTAR_SEARCH, testMisplacedTile3) {
    int size = 9;
    int *arr1 = new int[9];
    arr1[0] = 1;  arr1[1] = 2; arr1[2] = 3; 
    arr1[3] = 4;  arr1[4] = 5; arr1[5] = 6; 
    arr1[6] = 8;  arr1[7] = 7; arr1[8] = 0;
    Problem TestBoard1(arr1, size);
    Node* result = A_STAR_SEARCH(TestBoard1, misplacedTileHeuristic);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(result->getState().isGoal());
    delete[] arr1;
    delete result; 
}


int main(int argc, char **argv) { ::testing::InitGoogleTest(&argc, argv); return RUN_ALL_TESTS();}