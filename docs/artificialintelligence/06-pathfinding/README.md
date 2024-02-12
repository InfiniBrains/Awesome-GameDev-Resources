# Pathfinding on a 2D grid

## Data structures

In order to build an A-star pathfinding algorithm, we need to define some data structures. We need:

- Index for the quantized map;
- Position for the game objects;
- Bucket to query in O(1) if the elements are there;
- Map from Index to Buckets;
- Priority Queue to store the frontier of visitable buckets;
- Vector of Indexes to store the path;

```c++
/**
In order to build an A-star pathfinding algorithm, we need to define some data structures. We need:
- Index for the quantized map;
- Position2 for the game objects;
- Bucket to query in O(1) if the elements are there;
- Map from Index to Buckets;
- Priority Queue to store the frontier of visitable buckets;
- Vector of Indexes to store the path;
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <queue>

// generic vector2 struct to work with floats and ints
template <typename T>
// requires T to be int32_t or float_t
requires std::is_same<T, int32_t>::value || std::is_same<T, float_t>::value
struct Vector2 {
    // data
    T x, y;
    // constructors
    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}
    // copy constructor
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}
    // assignment operator
    Vector2& operator=(const Vector2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }
    // operators
    Vector2 operator+(const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }
    Vector2 operator-(const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }
    // distance
    float distance(const Vector2& v) const {
        return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }
    // distance squared
    float distanceSquared(const Vector2& v) const {
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
    }
    // quantize to index2
    Vector2<int32_t> quantized(float scale=1) const {
        return {(int32_t)std::round(x / scale), (int32_t)std::round(y / scale)};
    }
    // operator < for std::map
    bool operator<(const Vector2& v) const {
        return x < v.x || (x == v.x && y < v.y);
    }
    // operator == for std::map
    bool operator==(const Vector2& v) const {
        return x == v.x && y == v.y;
    }
};

using Index2 = Vector2<int32_t>;
using Position2 = Vector2<float_t>;

struct uid_type {
private:
    static inline size_t nextId = 0; // to be used as a counter
    size_t uid; // to be used as a unique identifier
public:
    // not thread safe, but it is not a problem for this example
    uid_type(): uid(nextId++) {}
    inline size_t getUid() const { return uid; }
};


// implement this struct to store game objects by yourself
struct GameObject: public uid_type {
    Position2 position;
    // add here your other data

    GameObject(const Position2& position) : position(position) {}
    GameObject() : position(Position2()) {}
};

// hash function for std::unordered_map
template <typename T>
struct std::hash<Vector2<T>> {
    size_t operator()(const Vector2<T> &v) const {
        return hash<T>()(v.x) ^ hash<T>()(v.y);
    }
};

using Bucket = std::unordered_set<GameObject*>;
using QuantizedMap = std::unordered_map<Index2, Bucket>;
using CostMap = std::unordered_map<Index2, float>;
using BlockMap = std::unordered_map<Index2, bool>;
using FlowField = std::unordered_map<Index2, Index2>;

// The game objects organized into buckets
QuantizedMap quantizedMap;
// all game objects
Bucket gameObjects;
// The cost of each bucket
CostMap costMap;
// The walls
BlockMap isWall;

std::vector<Index2> getUnblockedNeighbors(const Index2& v) {
    std::vector<Index2> neighbors;
    auto candidates = {Index2(1, 0), Index2(-1, 0), Index2(0, 1), Index2(0, -1)};
    for (const auto& c : candidates) {
        Index2 n = v + c;
        if (!isWall.contains(n)) {
            neighbors.push_back(n);
        }
    }
    return neighbors;
}

// Pathfinding algorithm from position A to position B
std::vector<Index2> findPath(const Position2& startPos, const Position2& endPos) {
    // quantize
    Index2 start = startPos.quantized();
    Index2 end = endPos.quantized();

    // datastructures
    BlockMap visited; // to store if a bucket has been visited
    CostMap accumulatedCosts; // to store the cost to reach a bucket
    std::priority_queue<std::pair<float, Index2>> frontier;
    BlockMap isOnFrontier; // to store if a bucket is on the frontier
    FlowField cameFrom; // to easily reconstruct the path

    // initialize
    visited[start] = false;
    accumulatedCosts[start] = 0;
    frontier.emplace(0, start);
    isOnFrontier[start] = true;
    cameFrom[start] = start;

    // main loop
    while (!frontier.empty()) {
        // consume first element from the frontier
        auto current = frontier.top().second;
        frontier.pop();
        isOnFrontier.erase(current);

        // mark it as visited to avoid revisiting
        visited[current] = true;

        // quit early
        if (current == end)
            break;

        // iterate over neighbors
        for (const auto& next : getUnblockedNeighbors(current)) {
            // if the neighbor has not been visited and is not on frontier
            if (!visited[next] && !isOnFrontier.contains(next)) {
                // calculate the cost to reach the neighbor
                float newCost =
                        accumulatedCosts[current] + // cost so far
                        current.distance(next) + // cost to reach the neighbor
                        (costMap.contains(next) ? costMap[next] : 0); // cost of the neighbor
                // if the cost is lower than the previous cost
                if (!accumulatedCosts.contains(next) || newCost < accumulatedCosts[next]) {
                    // update the cost
                    accumulatedCosts[next] = newCost;
                    // calculate the priority
                    float priority = newCost + next.distance(end);
                    // push the neighbor to the frontier
                    frontier.emplace(-priority, next);
                    // mark the neighbor as on frontier
                    isOnFrontier[next] = true;
                    // store the flow field
                    cameFrom[next] = current;
                }
            }
        }
    }

    // reconstruct path
    std::vector<Index2> path;
    Index2 current = end;
    while (current != start) {
        path.push_back(current);
        current = cameFrom[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}



int main() {
/*
map. numbers are bucket cost, letters are objects, x is wall
A 0 5 0 0
0 X X 0 0
5 X 0 0 0
0 0 0 0 B
 */

    // Create 2 Game Objects
    GameObject a(Position2(0.1, 0.1));
    GameObject b(Position2(3.9, 4.1));

    // place walls
    isWall[Index2(1, 1)] = true;
    isWall[Index2(1, 2)] = true;
    isWall[Index2(2, 1)] = true;

    // add cost to some buckets
    costMap[Index2(2, 0)] = 5;
    costMap[Index2(0, 2)] = 5;

    // add game objects to the set
    gameObjects.insert(&a);
    gameObjects.insert(&b);

    // add game objects to the quantized map
    for (auto& g : gameObjects)
        quantizedMap[g->position.quantized()].insert(g);

    // find path
    auto path = findPath(a.position, b.position);

    // todo: smooth the path between the points

    // print path
    for (auto& p : path)
        std::cout << "(" << p.x << ", " << p.y << ") ";
    std::cout << std::endl;
    // will print (0, 0) (1, 0) (1, -1) (2, -1) (3, -1) (3, 0) (3, 1) (3, 2) (3, 3) (4, 3) (4, 4)

    return 0;
}

```