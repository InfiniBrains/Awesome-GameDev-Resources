---
date: 2023-10-02T23:00:00Z
categories:
  - Maze
  - Data Structures
  - C++
  - Optimization
  - Memory
  - Cache
  - Vector
  - Bitfield
  - Maze Generation
authors:
  - tolstenko
---

# Memory-efficient Data Structure for Procedural Maze Generation

In this post, you will learn how to create a memory-efficient data structure for maze generation. We will jump from a 320 bits data structure to just 2! It is achieved by taking a bunch of clever decisions, changing the referential and doing some math. Be warned, this not for the fainted hearts. Are you brave enough? 

<!-- more -->

Problem statement: You need to generate mazes dynamicly, and you need to break or add walls between rooms. Ex.: How can we store data for a simple 3x3 maze like this:

```text
 _ _ _ 
| |   |
| | | |
|_ _|_|
``` 

The naive approach is to create a data structure like this:

```c++
class Node {
    Node* top, right, bottom, left;
    bool top_wall, right_wall, bottom_wall, left_wall;
};
```

This one above will work, but it is:

- Cache unfriendly;
- Random access to any element will be slow;
- Memory inefficient;
- Huge memory consumption;
- Redundant data usage;

**Cache Unfriendly**: The cache locality is hurt by extensive usage of dynamic allocation (4 pointer per node), and not reserving contigous memory for every new object created.

**Random Access**: To access the room `{x,y}` will have to iterate over node by node from the origin. The access of a room will have the algorithmic complexity of O(rows+columns) or simply O(n). For small mazes it is not a problem, but for big mazes it will be.

**Memory inefficiency**: The memory allocation for each room is 4 pointers and 4 booleans. If the size of the pointer is 8 bytes and each boolean is 1 byte, we might think it will have 36 bytes per room, right? Wrong! The compiler will add padding to the struct, so it will have 40 bytes per room. If we have a 1000x1000 maze, we will have 40MB of memory allocated for the maze. It is a lot of memory for a simple maze.

**Data redundancy**: The wall data is stored in two neighbors. If we break a wall, we have to break the wall in two places. It is not a big deal, but it is a waste of memory.

## Optimization

Well, let's try to optimize it. The first step is to use a single array of data. And then we need to reduce the duplicity of data.

By removing all the pointers, and store the wall data in a single array following matrix linearization, we will drop the memory consumption to 4 bytes per room (10x improvement). It is a huge improvement, but we can do better. Now we can create an array of WallData as follows:

```c++
struct WallData {
    bool top, right, bottom, left;
};
vector<WallData> data;
WallData get_wall(int x, int y) {
    return data[y * width + x];
}
```

The size of the WallData is 4 bytes. But we can reduce it if we use data layout optimization:

```c++
struct WallData {
    bool top:1, right:1, bottom:1, left:1;
};
```

In this version, WallData will use 1 byte per room(40x improvement). But we will be using only 4 bits of the byte. Another way of optmizing it is to use vector of bools for every type of wall. Let's group them into vectors. 

```c++
vector<bool> topWalls, rightWals, bottomWalls, leftWalls;
```

For vector, depending on the implementation, it needs to store the size of it, the capacity, and the pointer to the data, which will use 24 bytes per vector. If  can reach 32 if it stores the reference count to it as a smart pointer.

So what we are going to do next? Reduce the number of vectors used to reduce overhead. If you want to go deeper, you can use only one vector<bool> where every bit is a wall. So we will have only 4 bits per room and do some math to get the right bit(80x improvement). 

```c++
vector<bool> walls;
```

Can we do it better? Yes! As you might have noticed, every wall data is being stored in two nodes redundantly. So we will jump from 40 bytes(320 bits) to 2 bits per room (approximately 160x improvement). But in order to achieve that, you have to follow a strict set of rules andodifications.

1. Every even bit is a top wall, and every odd bit is a right wall relative to an intersection;
2. Every dimension of the maze will be increased by one unity in order to properly address the borders.
3. We need to create accessors via matrix index and flaten with linearization technique. 

```text
 _ _ _
|_|_|_|
|_|_|_|
```

This 3x2 maze will be represented by a 4x3 linearized matrix. It is easier to understand if you look at the walls as edges and the wall intersections as nodes. So for a 3x2 maze, we need 4 vertical walls and 3 horizontal walls. So in this specific case, if we follow the pattern of 1 if the wall is present and 0 if it is not there, and do this only for top and right walls of a node(intersection), we will have:

```text
This fully blocked 3x2 maze
 _ _ _
|_|_|_|
|_|_|_|

Will give us 4x3 pairs of bits:
01 01 01 00
11 11 11 10
11 11 11 10

Linearized as:
010101001111111011111110
```

Just to recaptulate: we went from 40 Bytes (320 bits) per room to approximately 2 bits per room. A maze map with 128x128 would go from 128*128*320/8 = 640KB to 129*129*2/8 = 4161 bytes. It is 157.5 times densely packed. It is a huge improvement.

## Notes about vectors:

1. vector of bools is a bitfield, so it will pack 8 bools per byte, it will do the shift and masking for us. 
2. vector of bools is arguably an antipattern because it doesn't behave like a commom vector by not following the rule of zero cost abstraction from C++. It adds a cost for the densely packed bitfield.
3. For our intent, this is exactly what we want, so we can use it, just check if your compiler implements it as a bitfield.

Here goes a simple implementation of a data structure to hold the maze data:

```c++
struct Maze {
private:
  vector<bool> walls;
  vector<bool> visited;
  int width, height;
public:
  Maze(int width, int height): width(width), height(height) {
    walls.resize((width+1)*(height+1)*2, true);
    for(int i = 0; i <= width; i++) // clear verticals on the top
      SetNorthWall(i, 0, false);
    for(int i = 0; i <= height; i++) // clear horizontals on the right
      SetEastWall(width, i, false);
    visited.resize(width*height, false); // no room is visited yet
  }
  
  bool GetVisited(int x, int y) const { return visited[y*width + x]; }
  void SetVisited(int x, int y, bool val) { visited[y*width + x] = val; }
  
  bool GetNorthWall(int x, int y) const { return walls[(y*(width+1) + x)*2 + 1]; }
  bool GetSouthWall(int x, int y) const { return walls[((y+1)*(width+1) + x)*2 + 1];}
  bool GetEastWall(int x, int y) const { return walls[((y+1)*(width+1) + x+1)*2];}
  bool GetWestWall(int x, int y) const { return walls[((y+1)*(width+1) + x)*2];}
  
  void SetNorthWall(int x, int y, bool val) { walls[(y*(width+1) + x)*2 + 1] = val; }
  void SetSouthWall(int x, int y, bool val) { walls[((y+1)*(width+1) + x)*2 + 1] = val;}
  void SetEastWall(int x, int y, bool val) { walls[((y+1)*(width+1) + x+1)*2] = val;}
  void SetWestWall(int x, int y, bool val) { walls[((y+1)*(width+1) + x)*2] = val;}
}
```

## Further ideas

1. Is it possible to explore even more the structure?
2. Is it possible to do the same for hexagonal grids? Every node will have 3 walls instead of 4 in the squared grid. 
