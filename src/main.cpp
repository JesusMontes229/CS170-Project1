#include <iostream>
#include <vector>
#include <string>
#include "../headers/Problem.h" 
#include "../headers/Node.h" 
#include "../headers/Algorithm.h"
#include "../headers/Tree.h"
#include "../headers/HeuristicFunc.h"

void PrintPath(Node* currentNode)
{
    if(currentNode == nullptr)
    {
        
    }
    else{
        PrintPath(currentNode->Parent);

    }
}


using namespace std;

void printPuzzle(const Problem& problem) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i > 0) cout << endl;
        cout << (problem.GetValueAtIndex(i) == 0 ? 'b' : '0' + problem.GetValueAtIndex(i)) << ' ';
    }
    cout << endl;
}

int main() {
    cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver." << endl; 
    cout << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;

    int choice;
    cin >> choice;

    // define a default puzzle
    const int defaultPuzzle[] = {8, 7, 1, 6, 0, 2, 5, 4, 3};
    const int *puzzlePTR = nullptr;
    //Problem initialState(defaultPuzzle, 9); // nullptr initialize

    if (choice == 1) {
        // using default puzzle
        puzzlePTR = defaultPuzzle;
    } else if (choice == 2) {
        cout << "Enter your puzzle, use a zero to represent the blank." << endl;

        // read puzzle from user
        vector<int> input(9);
        for (int i = 0; i < 3; ++i) {
            cout << "Enter row " << (i + 1) << ", use space or tabs between numbers: ";
            for (int j = 0; j < 3; ++j) {
                cin >> input[i * 3 + j];
            }
        }
        
        
        // initialize problem accordingly
        puzzlePTR = input.data();
    }
    Problem initialState(puzzlePTR, 9);
    cout << "Enter your choice of algorithm:" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with the Misplaced Tile heuristic." << endl;
    cout << "3. A* with the Euclidean distance heuristic." << endl;

    int algorithmChoice;
    cin >> algorithmChoice;
    Node* resultNode = nullptr;
    
    int(*HeuristicFunc)(const Problem&);
    // call each algorithm according to user input
    switch (algorithmChoice) {
        case 1: {
            HeuristicFunc = UniformCostSearchHeuristic;
            break;
        }
        case 2: {
            HeuristicFunc = MisplacedTileHeuristic;
            break;
        }
        case 3: {
            HeuristicFunc = EuclideanDistHeuristic;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return 1; // Exit if the choice is invalid
    }
    Tree SearchTree(initialState, HeuristicFunc);
    resultNode = A_STAR_SEARCH(SearchTree, HeuristicFunc);
    // print the results if there is a solution
    if (resultNode != nullptr) {
        // print the path from the initial state to the goal state
        vector<Node*> path;
        for (Node* node = resultNode; node != nullptr; node = node->Parent) {
            path.push_back(node);
        }

        // output the expanding states with their g(n) and h(n)
        for (int i = path.size() - 1; i >= 0; --i) {
            Node* currentNode = path[i];
            int g_n = currentNode->depth; // Cost to reach this node
            int h_n = currentNode->h_cost; // Heuristic value

            // print the current state being expanded
            cout << "Expanding state:" << endl;
            //printPuzzle(currentNode->state);
            currentNode->printState();

            //print the best state to expand
            if (i > 0) { // ensure there's a next state to expand
                Node* nextNode = path[i - 1];
                cout << "The best state to expand with g(n) = " << g_n << " and h(n) = " << h_n << " is..." << endl;
                //printPuzzle(nextNode->state);
                nextNode->printState();
                cout << "Expanding this node..." << endl;
            }
        }

        cout << "Goal!!!" << endl;
        cout << "To solve this problem the search algorithm expanded a total of " 
             << SearchTree.NumOfNodes << " nodes." << endl; // print total nodes expanded
        cout << "The maximum number of nodes in the queue at any one time: " 
             << SearchTree.maxQueueSize << "." << endl; // display maxQueueSize*/
        cout << "The depth of the goal node was " 
             << resultNode->depth << "." << endl; // depth of the goal node*/

    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}