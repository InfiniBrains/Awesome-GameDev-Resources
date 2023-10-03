# Space quantization

Space quantization is a way to sample continuous space, and it can to be used in in many fields, such as Artificial Intelligence, Physics, Rendering, and more. Here we are going to focus primarily Spatial Quantization for AI, because it is the base for pathfinding, line of sight, field of view, and many other techniques.

Some of the most common techniques for space quantization are: grids, voxels, graphs, quadtrees, octrees, KD-trees, BSP, Spatial Hashing and more. Another notable techniques are line of sight(or field of view), map flooding, caching, and movement zones.

# Grids

Grids are the most common technique for space quantization. It is a very simple technique, but it is very powerful. It consists in dividing the space in a grid of cells, and then we can use the cell coordinates to represent the space. The most common grid is the square grid, but we can use hexagonal and triangular grids, you might find some irregular shapes useful to exploit the space conformation better.

## Square Grid

The square grid is a regular grid, where the cells are squares. It is very simple to implement and understand.

There are some ways to store data for squared grids. Arguably you could 2D arrays, arrays of arrays or vector of vectors, but depending on the way you implement it, it can hurt the performance. Example: if you use an array of arrays or vector of vectors, where every entry from de outer array is a pointer to the inner array, you will have a lot of cache misses, because the inner arrays are not contiguous in memory. 

### Notes on cache locality

So in order do increase data locality for squared grids, you can use a single array, and then use the following formula to calculate the index of the cell. We call this strategy matrix flattening.

```c++
int arrray[width * height]; // 1D array with the total size of the grid
int index = x + y * width; // index of the cell at x,y
```

There is a catch here, given we usually represent points as X and Y coordinates, we need to be careful with the order of the coordinates. While you are iterating over all the matrix, you need to iterate over the Y coordinate first, and then the X coordinate. This is because the Y coordinate is the one that changes the most, so it is better to have it in the inner loop. By doing that, you will have better cache locality and effectively the index will be sequential.

```c++
vector<YourStructure> data; // data is filled with some data elsewhere
for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
        // do something with the cell at index x,y
        data[y * width + y] = yourstrucure;
        // it is the same as: data[y][x] = yourstructure;
    }
}
```

### Quantization and dequantization of square grids

If your world is based on floats, you can use the square by using the floor function or just cast to integer type, because the default behavior of casting from float to integer is to floor it. Example: In the case of a quantization resolution of size of 1.0f, everything between 0 and 1 will be in the cell (0,0), everything between 1 and 2 will be in the cell (1,0), and so on.

```c++
Vector2int quantize(Vector2f position, float resolution) {
    return Vector2int((int)floor(position.x/resolution), (int)floor(position.y/resolution));
}
```

If you need to get the center of the cell in the world coordinates following the quantization resolution, you can use the following code.

```c++
Vector2f dequantize(Vector2int index, float resolution) {
    return Vector2f((float)index.x * resolution + resolution/2.0f, (float)index.y * resolution + resolution/2.0f);
}
```

If you need to get the corners of the cell following the quantization resolution, you can use the following code.

```c++
Rectangle2f cell_bounds(Vector2int index, float resolution) {
    return {index.x * resolution, index.y * resolution, (index.x+1) * resolution, (index.y+1) * resolution};
}
```

If you need to get the neighbors of a cell, you can use the following code.

```c++
std::vector<Vector2int> get_neighbors(Vector2int index) {
    return {{index.x-1, index.y}, {index.x, index.y-1},
            {index.x+1, index.y}, {index.x, index.y+1}};
}
```

We already understood the idea of matrix flattening to improve efficiency, we can use it to represent a maze. But in a maze, we have walls to 

Imagine that you are willing to be as memory efficient and more cache friendly as possible. You can use a single array to store the maze, and you can use the following formula to convert from matrix indexes to the index of the cell in the array.

```c++

## Hexagonal Grid

Hexagonal grid is an extension of a square grid, but the cells are hexagons. It feels nicer to human eyes because we have more equally distant neighbors. If used as subtract for pathfinding, it can be more efficient because the path can be more straight.

It can be implemented as single dimension array, but you need to be careful with shift that happens in different odd or even indexes. You can use the following formula to calculate the index of the cell. In this world quantization can be in 4 conformations, depending on the rotation of the hexagon and the alignment of the first cell.

1. Point pointy top hexagon with first line aligned to the left:
``` text
  / \ / \ / \ 
 | A | B | C |
  \ / \ / \ / \
   | D | E | F |
  / \ / \ / \ /
 | G | H | I |
  \ / \ / \ / 
```

2. Point pointy top hexagon with first line aligned to the right
```text 
    / \ / \ / \
   | A | B | C |
  / \ / \ / \ / 
 | D | E | F |
  \ / \ / \ / \
   | G | H | I |
    \ / \ / \ /
```
3. Flat top hexagon with first column aligned to the top:
```text 
 __    __
/A \__/C \
\__/B \__/
/D \__/F \
\__/E \__/
/G \__/I \
\__/H \__/
   \__/
```
4. Flat top hexagon with first column aligned to the bottom:
```text 
     __
  __/B \__ 
 /A \__/C \
 \__/E \__/
 /D \__/F \
 \__/H \__/
 /G \__/I \
 \__/  \__/
```

### Quantization and dequantization of hexagonal grids

For simplicity, we are going to use the first conformation, where the first line is aligned to the left, and the hexagons are pointy top. The quantization is done by using the following formula.

```c++
// I am assuming that the hexagon is pointy top, and the first line is aligned to the left
// I am also assuming that the hexagon is centered in the cell, and the top left corner is at (0,0), 
// y axis is pointing down and x axis is pointing right
// this dont work for all the cases, but it is a good approximation for locations near the center of the hexagon
/*
  / \ / \ / \ 
 | A | B | C |
  \ / \ / \ / \
   | D | E | F |
  / \ / \ / \ /
 | G | H | I |
  \ / \ / \ /
 */
Vector2int quantize(Vector2f position, float hexagonSide) {
    int y = (position.y - hexagonSide)/(hexagonSide * 2);
    int x = y%2==0 ?
      (position.x - hexagonSide * sqrt3over2) / (hexagonSide * sqrt3over2 * 2) : // even lines
      (position.x - hexagonSide * sqrt3over2 * 2)/(hexagonSide * sqrt3over2 * 2) // odd lines
    return Vector2int(x, y);
}
Vector2f dequantize(Vector2int index, float hexagonSide) {
    return Vector2f(index.y%2==0 ? 
      hexagonSide * sqrt3over2 + index.x * hexagonSide * sqrt3over2 * 2 : // even lines
      hexagonSide * sqrt3over2 * 2 + index.x * hexagonSide * sqrt3over2 * 2, // odd lines
      hexagonSide + index.y * hexagonSide * 2);
}
```

You will have to figure out the formula for the other conformations. Or send a merge request to this repository adding more information.

# Voxels and Grid 3D

Grids in 3D works the same way as in 2D, but you need to use 3D vectors/arrays or voxel volumes. Most concepts applies here. If you want to expand this section, send a merge request.

# Quadtree

Quadtree is a tree data structure where each node has 4 children. It is used to partition a space in 2D. It is used to optimize collision detection, pathfinding, and other algorithms that need to iterate over a space. It is also used to optimize rendering, because you can render only the visible part of the space.

## Quadtree implementation

Quadtree is a recursive data structure, so you can implement it using a recursive data structure. The following code is a simple implementation of a quadtree.

```c++
// this code is not tested, but it should work. It is just an example and send a merge request if you find any errors.
// node
template<class T>
struct DataAtPosition {
    Vector2f center;
    T data;
};

template<class T>
struct QuadtreeNode {
    Rectangle2f bounds;
    std::vector<DataAtPosition<T>> data;
    std::vector<QuadtreeNode<T>> children;
};

// insert
template<class T>
void insert(QuadtreeNode<T>& root, DataAtPosition<T> data) {
    if (root.children.empty()) {
        root.data.push_back(data);
        if (root.data.size() > 4) {
            root.children.resize(4);
            for (int i = 0; i < 4; ++i) {
                root.children[i].bounds = root.bounds;
            }
            root.children[0].bounds.max.x = root.bounds.center().x; // top left
            root.children[0].bounds.max.y = root.bounds.center().y; // top left
            root.children[1].bounds.min.x = root.bounds.center().x; // top right
            root.children[1].bounds.max.y = root.bounds.center().y; // top right
            root.children[2].bounds.min.x = root.bounds.center().x; // bottom right
            root.children[2].bounds.min.y = root.bounds.center().y; // bottom right
            root.children[3].bounds.max.x = root.bounds.center().x; // bottom left
            root.children[3].bounds.min.y = root.bounds.center().y; // bottom left
            for (auto& data : root.data) {
                insert(root, data);
            }
            root.data.clear();
        }
    } else {
        for (auto& child : root.children) {
            if (child.bounds.contains(data.center)) {
                insert(child, data);
                break;
            }
        }
    }
}

// query
template<class T>
void query(QuadtreeNode<T>& root, Rectangle2f bounds, std::vector<DataAtPosition<T>>& result) {
    if (root.bounds.intersects(bounds)) {
        for (auto& data : root.data) {
            if (bounds.contains(data.center)) {
                result.push_back(data);
            }
        }
        for (auto& child : root.children) {
            query(child, bounds, result);
        }
    }
}
```

## Quadtree optimization

The quadtree is a recursive data structure, so it is not cache friendly. You can optimize it by using a flat array instead of a recursive data structure. 


# Octree

Section WiP. Send a merge request if you want to contribute.

# KD-Tree

KD-Trees are a tree data structure that are used to partition a spaces in any dimension (2D, 3D, 4D, etc). They are used to optimize collision detection(Physics), pathfinding(AI), and other algorithms that need to iterate over a space. Also they are also used to optimize rendering, because you can render only the visible part of the space. Pay attention that KD-Trees are not the same as Quadtree and Octrees, even if they are similar.

In KD-trees, every node defines an orthogonal partition plan that alternate every deepening level of the tree. The partition plan is defined by a dimension, a value. The dimension is the axis that is used to partition the space, and the value is the position of the partition plan. The partition plan is orthogonal to the axis, so it is a line in 2D, a plane in 3D, and a hyperplane in 4D.

# BSP Tree

BSP inherits almost all characteristics of KD-Trees, but it is not a tree data structure, it is a graph data structure. The main difference is to instead of being orthogonal you define the plane of the section. The plane is defined by a point and a normal. The normal is the direction of the plane, and the point is a point in the plane. 

# Spatial Hashing

Spatial hashing is a data structure that is used to partition a space. It consists in a hash table where the keys are the positions of the elements, and the values are the elements in buckets. It is very fast to insert and query elements. But it is not good for iteration, because it is not cache friendly.

Usually when you want to use a spatial hashing, you create hash functions for the bucket keys, there is no limit on how you do that, but you have to keep in mind that the hash functions have to be fast and have to be good for the distribution of the elements. Here is a good example of a hashing function for 2D vectors.

```c++
namespace std {
    template<>
    struct hash<Vector2f> {
        // I am assuming size_t is 64 bits and the float is 32 bits
        size_t operator()(const Vector2f& v) const {
            // get the bits of the float in a integer
            uint64_t x = *(uint64_t*)&v.x;
            uint64_t y = *(uint64_t*)&v.y;
            // mix the bits of the floats
            uint64_t hash = x & (y << 32);
            return hash;
        }
    };
}
```

Pay attention that the hashing function above generates collisions, so you have to use a data structure that can handle collisions. You will use datastructures like `unordered_map<Vector2D, unordered_set<DATATYPE>>` or `unordered_map<Vector2D, vector<DATATYPE>>`. The first one is better for insertion and query, but it is not cache friendly. 

To avoid having one bucket per every possible position, you have to setup properly the dimension of the bucket, a good sugestion is to alwoys floor the position and have buckets dimension of 1.0f. That would be good enough for most cases.
