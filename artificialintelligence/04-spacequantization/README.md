# Space quantization

Space quantization is a way to sample continuous space to be used in in many fields, such as Artificial Intelligence, Physics, Rendering, and more. Here we are going to focus primarily Spatial Quantization for AI, because it is the base for pathfinding, line of sight, field of view, and many other techniques.

Some of the most common techniques for space quantization are: grids, voxels, graphs, quadtrees, octrees, BSP, Spatial Hashing and more. Another notable techniques are line of sight(or field of view), map flooding, caching, and movement zones.

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
for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) { 
        int index = x + y * width;
        // do something with the cell at index
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

!!! note

    This code is not working yet, it is just a draft. Please send a merge request to fix it. Mobagen has an implementation of this. 
 
```c++
Vector2int quantize(Vector2f position, float resolution) {
    int x = (int)(position.x / resolution);
    int y = (int)(position.y / resolution);
    int rx = abs(x - (int)floor(x/2.0f) * 2);
    int ry = abs(y - (int)floor(y/2.0f) * 2);
    if(rx == 1 && ry == 1) {
        x = (int)floor(x/2.0f) * 2;
        y = (int)floor(y/2.0f) * 2;
    } else {
        x = (int)floor(x/2.0f) * 2 + 1;
        y = (int)floor(y/2.0f) * 2 + 1;
    }
}
```

If you need to get the center of the cell in the world coordinates following the quantization resolution, you can use the following code.
