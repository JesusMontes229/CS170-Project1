# CS170-Project1

## Project 1 Report: The Eight-Puzzle
By: Ananya Sood, Ridhima Inukurti, and Jesus Montes
link to github repository: https://github.com/JesusMontes229/CS170-Project1/tree/main 

## Introduction
The purpose of this program is to solve an 8 puzzle through various search algorithms: uniform cost, A* misplaced tile, and A* euclidean distance. The program allows you to enter in the 8 puzzle and provides the option to choose from the three algorithms. Once selected it will run through that algorithm and return the expanded states with the cost at each state (cost and heuristic cost). It will continue to do this until it reaches the goal state (when the puzzle is solved). When the goal state is achieved, it will relay the number of expanded nodes, maximum number of nodes in a queue at a time, and the depth of the goal node. 

## Observations
Our design for this project was through object oriented programming. We had five main classes: Node, Problem, Heuristic, Tree and Algorithm class. Within the node class our main objective was to track the current state of * puzzle and keep track of the costs. As a result, we mainly had variables like a parent pointer, the state, and cost variables and functions that calculated the g_cost, h_cost, and total cost. Within the problem class our main objective was to keep track of the problem especially regarding the operators, goal state, the board. As a result, we mainly had variables and functions that managed operators (leftShift, rightShift, up, down), the board, and checking for the goal state (isGoal()). Within the heuristic class our main objective was to have different functions for the euclidean distance, uniform cost, and misplaced tiles. Also for our tree class our main objective was to help with the expansion of the states so we have an expand function that takes care of that. 

In terms of optimization, we used vectors in order to store the board/problem and even the current states. Within each of the algorithms itself we use a priority queue which would prioritize them in terms of cost. Therefore keeping the nodes with the lowest cost in the front of the queue would make it helpful to expand to and keep track of. We also maintain a minimum heap concept, which would have the node with the lowest cost be at the top of the heap. Once the node with lowest cost is expanded, then the min-heap structure would provide the next lowest cost node to be accessed quickly. The overall runtime with the min-heap structure applied along with the priority queue would be lower than without it. 

## Challenges 
Throughout developing this project there were a couple of challenges that our group faced. During the design stage, we had a difficult time thinking about what classes we wanted and their private variables and methods. At first we were unsure of how to organize the three algorithms but ultimately developed a general algorithm called A* and created different heuristic functions to do. During the development process we had to figure out how to implement the three search algorithms and make it general enough. Also within some of our classes we deal with pointer/memory management which resulted in compilation and testing errors when not implemented correctly. 

## Uniform Cost Algorithm 
The Uniform Cost Algorithm has the main goal of finding the path that has the minimum total cost from the initial node to the goal node. What the Uniform Cost Algorithm does is expand nodes based on the g(n) value. In terms of this project, we wanted to use the uniform cost algorithm to solve the eight-puzzle. In the code that we implemented, we used our knowledge of knowing that when we are in the case where the heuristic cost h(n) is a constant value of 1 for all nodes, the A* algorithm essentially behaves as a Uniform Cost Search Algorithm. Knowing this, we used the general A* search algorithm that we implemented and implemented Uniform Cost by taking in the initial state of the problem and ensuring that for every state that it calculates, the heuristic cost is 1. 

## A* With The Misplaced Tile Algorithm 
The A* search algorithm that is modified using the Misplaced Tile Heuristic has the main goal of finding the shortest path from the start state to the goal state by minimizing cost. It does this by using the function f(n) = g(n) + h(n), where the g(n) value represents the cost to reach a node from the starting node, while the h(n) represents the heuristic cost which is the number of tiles in the 8 puzzle that are not in their correct positions. The way this heuristic works is by prioritizing nodes that are closer to the goal state to reach an optimal solution. In our implementation, we first created a general A* search in our Algorithm.cpp that begins at the root node of the tree and initializes a priority queue to manage the nodes based on their cost estimates. In a loop, the current node is initialized to the node with the lowest estimated cost, and if it reaches a goal state, returns the solution node and the size of the checked space. If the goal state is not reached, we have implemented a space expanding function to generate and explore the child nodes of the current nodes, and employ the same process. We call the A* with the MisplacedTileHeuristic function in our Heuristicfunc.cpp. This function takes in the problem object and initial state (the current puzzle state), and returns the heuristic value estimate. A for loop keeps track of the number of misplaced tiles that we pass into our general A* function to find the optimal solution.
 
## A* With The Euclidean Distance Algorithm  
The A* search algorithm that is modified using the Euclidean Distance Heuristic has the main goal of finding the shortest path from the start state to the goal state by using the Euclidean Distance Formula. It does this by using the function f(n) = g(n) + h(n), where the g(n) value represents the cost to reach a node from the starting node, while the h(n) represents the heuristic cost which calculated by finding the distance from the current node to the goal node. This way this heuristic works is by estimating the distance to the goal, where we prioritize nodes that can lead to an optimal solution. Through the use of a Euclidean Distance heuristic, the A* algorithm can find the goal state in a more efficient way.  In our implementation, we first created a general A* search in our Algorithm.cpp that begins at the root node of the tree and initializes a priority queue to manage the nodes based on their cost estimates. In a loop, the current node is initialized to the node with the lowest estimated cost, and if it reaches a goal state, returns the solution node and the size of the checked space. If the goal state is not reached, we have implemented a space expanding function to generate and explore the child nodes of the current nodes, and employ the same process. We call the A* with the EuclideanDistHueristic function in our Heuristicfunc.cpp. The function essentially calculates how far the current state of the 8-puzzle is from the goal state through calculating the Euclidean distance of each tile from its goal tile position to find the optimal solution. 

## Test Cases
Trivial:                Easy:               Oh Boy: 
1 2 3                    1 2 *                 8 7 1
4 5 6                    4 5 3                 6 * 2
7 8 *                    7 8 6                 5 4 3

Very Easy:          Doable:            Impossible:
1 2 3                    * 1 2                 1 2 3
4 5 6                    4 5 6                 4 5 6
7 * 8                    7 8 6                 8 7 *

We tested our code by making sure that it was able to solve the following test cases above. If the test case was the one where it was solvable, it would reach the goal state and relay an output of “Goal!!!” along with all the other necessary information. If the goal state was not reached, it would relay an output of “No solution found.” 

## Diagrams/Graphs 
* <img width="669" alt="Screenshot 2025-01-04 at 12 26 00 PM" src="https://github.com/user-attachments/assets/c8c5807b-971e-419d-bca9-a3299b480b16" />
* <img width="619" alt="Screenshot 2025-01-04 at 12 26 24 PM" src="https://github.com/user-attachments/assets/7ff0fedb-518e-4615-b36f-d48997ab57ec" />
* <img width="678" alt="Screenshot 2025-01-04 at 12 26 47 PM" src="https://github.com/user-attachments/assets/827e9abc-fc70-437e-9348-0414522b37b9" />
* <img width="608" alt="Screenshot 2025-01-04 at 12 27 05 PM" src="https://github.com/user-attachments/assets/333eeab9-8c56-4dd8-8eab-a0d355828415" />

## Conclusion/Our Findings 
We found that out of the three algorithms that we implemented to solve the eight-puzzle, the A* Search with the Euclidean Distance heuristic performed the best. The second best algorithm was the A* with the Misplaced Tile heuristic, and the third best was the Uniform Cost Algorithm. We found that the algorithms that were most efficient were the ones where we used a heuristic to enhance the A* search algorithm.

We found that for easier test cases, such as the trivial, easy and very easy cases, it did not matter which algorithms we used, as the three algorithms found the solution easily. However, as the test cases got more complicated, the heuristics became more effective in solving the problem in an efficient way. We found that the use of heuristics in these difficult problems allowed us to find better solutions, and the better the heuristic the better we would be able to solve the challenging 8-puzzle. 
