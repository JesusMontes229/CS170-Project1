#include <iostream>
#include <vector>
#include <string>
#include "AStarMisplacedTile.h" // all three searches
#include "UnfiformCostSearch.h"
#include "AstarEuclidean.h"
#include "Problem.h" 
#include "Node.h" 

using namespace std;

void printPuzzle(const Problem& problem) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i > 0) cout << endl;
        cout << (problem.GetValueAtIndex(i) == 0 ? 'b' : '0' + problem.GetValueAtIndex(i)) << ' ';
    }
    cout << endl;
}

int main() {
    cout << "Welcome to 862359197 8 puzzle solver." << endl; 
    cout << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;

    int choice;
    cin >> choice;

    // we define a default puzzle
    const int defaultPuzzle[] = {1, 2, 3, 4, 0, 5, 7, 8, 6};
    Problem initialState(nullptr, 9); // nullptr intialize

    if (choice == 1) {
        // using default puzzle
        initialState = Problem(defaultPuzzle, 9);
        // user-defined puzzle
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
        initialState = Problem(input.data(), 9);
    }

    cout << "Enter your choice of algorithm:" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with the Misplaced Tile heuristic." << endl;
    cout << "3. A* with the Euclidean distance heuristic." << endl;

    int algorithmChoice;
    cin >> algorithmChoice;

    Node* resultNode = nullptr;

    // call each algorithm according to user input
    switch (algorithmChoice) {
        case 1: {
            UniformCostSearch solver; 
            resultNode = solver.solve(initialState);
            break;
        }
        case 2: {
            AStarMisplacedTile solver;
            resultNode = solver.solve(initialState);
            break;
        }
        case 3: {
            AstarEuclideanTile solver;
            resultNode = solver.solve(intialState);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return 1; // exit if the choice is invalid
    }

    // print the results if there is a solution
    if (resultNode != nullptr) {
        cout << "Goal!!!" << endl;

        // print the path from the initial state to the goal state
        vector<Node*> path;
        for (Node* node = resultNode; node != nullptr; node = node->getParent()) {
            path.push_back(node);
        }

        cout << "Solution steps (from goal to initial):" << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            printPuzzle(path[i]->getState());
        }

        cout << "To solve this problem the search algorithm expanded a total of " 
             << resultNode->getDepth() << " nodes." << endl; // print nodes expanded
        cout << "The maximum number of nodes in the queue at any one time: " 
             << solver.maxQueueSize << "." << endl; // display maxQueueSize
        cout << "The depth of the goal node was " 
             << resultNode->getDepth() << "." << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}