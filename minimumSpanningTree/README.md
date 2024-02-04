
### Problem Description
All stands in a fare in The Netherlands require power. The aim is to have all stands connected to power, at the lowest cost possible. However, loops must be avoided in the power cable network as this may cause short circuits. 


### Input 
Firstly the program will be prompted with two numbers *n* and *m*. *n* represents the number of stands at the fare that need to be connected. *m* is the total number of power lines there are. Then there follows *m* lines, containing three integers *a*, *b* and *c*. 

*a* and *b* represent two stands that require power and *c* is the cost of the power line that could connect these two stands. 

### Output
A number stating the minimum total cost required to connect all the stands with the provided power cables. If there is no power network that can be made the output should be 0. 

An assumption that can be made: If you are given at least one power line, all stands can be connected. 

### Example Input-Output Behaviour
| Input | 
| --- |
| 5 10   |
| 1 2 10 |
| 1 3 10 |
| 1 4 10 |
| 1 5 10 |
| 2 3 1  |
| 2 4 8  |
| 2 5 9  |
| 3 5 6  |
| 4 5 1  |
| 1 2 3  |

**Output:**
11


### Solving the Problem: Minimum Spanning Tree
To solve the problem described above I implemented a Minimum Spanning Tree (MST) algorithm. I decided to implement a well-known MST algorithm, Kruskal's algorithm. To help in the execution of Kruskal's algorithm I made a *Graph* and *Heap* data structure. Lastly, I also make use of the Union-Find algorithm. 
