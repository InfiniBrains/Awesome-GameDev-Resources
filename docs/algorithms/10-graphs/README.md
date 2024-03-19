# Graph

Graphs are a type of data structures that interconnects nodes (or vertices) with edges. They are used to model relationships between objects.

## Basic Definitions

- **Nodes or vertices** are the basic entities in a graph and hold the data. 
- **Edges** are the connections and relation between the nodes. The relationship can be enriched in multiple ways such as direction, weight, and others. 
- **Neighbours** are the nodes that are connected to a specific node.
- **Path** is the sequence of edges and nodes that allows you to go from one node to another.
- **Degree** of a node is the number of edges connected to it.

## Representation

A graph is composed by a set of vertices(nodes) and edges. There are multiple ways to represent a graph, and every style has its own advantages and disadvantages.

### Adjacency matrix

Assuming every node is labeled with a number from `0` to `n-1`, an adjacency matrix is a 2D array of size `n` x `n`. The entry `a[i][j]` is 1 if there is an edge from node i to node j, and 0 otherwise. The adjacency matrix for a graph is always a square matrix.

```c++
// adjacency matrix
// NUMBER_OF_NODES is the number of nodes
// bool marks if there is an edge between the nodes.
// switch bool to float if you want to store the weight of the edge.
// switch bool to a data structure if you want to store more information about the edge.
bool adj_matrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
vector<Node> nodes;
```

- **Pros**: it is simple and easy to implement and blazing fast for checking if there is an edge between two nodes. 
- **Cons**: it consumes a lot of space, especially for sparse graphs.

### Adjacency list

It can be implemented in multiple ways, but a common one is to use an array of lists(or vectors). The index(key) of the array is the node id, and the value is a list of nodes that are connected to the key node.

```c++
// adjacency list
// NUMBER_OF_NODES is the number of nodes
// vector for storing the connected nodes ids as integers
// switch vector<int> to map<int, float> if you want to store the weight of the edge.
// switch map<int, float> to map<int, data_structure> if you want to store more information about the edge.
vector<int> adj_list[NUMBER_OF_NODES];
vector<Node> nodes;
```

- **Pros**: it is more memory efficient for sparse graphs.
- **Cons**: it can be slower to check if there is an edge between two nodes.

### Edge list

It is a collection of edges, where each egge can be represented as a pair of nodes, a pair of node ids, or a pair of references to nodes.  

```c++
// edge list
vector<pair<int, int>> edges;
vector<Node> nodes;
```

- **Pros**: it is the most memory efficient representation for sparse graphs.
- **Cons**: it can be slower to check if there is an edge between two nodes.

## Graph Types

- **Null graph**: A graph with no edges.
- **Trivial graph**: A graph with only one vertex.
- **Directed graph**: A graph where the edges have direction.
- **Weighted graph**: A graph where the edges have a weight.
- **Undirected graph**: A graph where the edges have no direction or are bidirectional. If weighted, the weights are the same in both directions.
- **Connected graph**: A graph where all nodes can be reached from any other node.
- **Disconnected graph**: A graph where some nodes cannot be reached from other nodes.
- **Cyclic graph**: A graph that has at least one cycle, a path that starts and ends at the same node.
- **Acyclic graph**: A graph that has no cycles.
- **Complete graph**: A graph where every pair of nodes is connected by a unique edge.
- **Regular graph**: A graph where every node has the same degree.

## Graph Algorithms

### Depth-First Search (DFS)

DFS is a graph traversal algorithm based on a stack data structure. Basically, the algorithm starts at a node and explores as far as possible along each branch before backtracking. It is used to find connected components, determine the connectivity of the graph, and solve many other problems.

<iframe scrolling="no" style="position:relative;top:0px;width:100%;height:500px;" src="https://www.cs.usfca.edu/~galles/visualization/DFS.html"></iframe>
<a href="https://www.cs.usfca.edu/~galles/visualization/DFS.html">source</a>

### Breadth-First Search (BFS)

BFS is a graph traversal algorithm based on a queue data structure. It starts at a node and explores all of its neighbours before moving on to the next level of neighbours by enqueing them. It is used to find the shortest path, determine the connectivity of the graph, and others.

<iframe scrolling="no" style="position:relative;top:0px;width:100%;height:500px;" src="https://www.cs.usfca.edu/~galles/visualization/BFS.html"></iframe>
<a href="https://www.cs.usfca.edu/~galles/visualization/BFS.html">source</a>