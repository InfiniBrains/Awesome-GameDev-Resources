# Pathfinding on a 2D grid



```c++
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <queue>
// Simple A-star pathfinding algorithm

// vector2 struct
template <typename T>
// requires T to be int32_t or float_t
requires std::is_same<T, int32_t>::value || std::is_same<T, float_t>::value
struct Vector2 {
    T x, y;
    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}
    Vector2& operator=(const Vector2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }
    Vector2 operator+(const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }
    Vector2 operator-(const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }
    float distance(const Vector2& v) const {
        return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }
    float distanceSquared(const Vector2& v) const {
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
    }
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

using Vector2i = Vector2<int32_t>;
using Vector2f = Vector2<float_t>;

struct uid_type {
private:
    static inline size_t nextId = 0; // to be used as a counter
    size_t uid; // to be used as a unique identifier
public:
    // not thread safe, but it is not a problem for this example
    uid_type(): uid(nextId++) {}
    inline size_t getUid() const { return uid; }
};


struct GameObject: public uid_type {
    Vector2f position;
    GameObject(const Vector2f& position) : position(position) {}
    GameObject() : position(Vector2f()) {}

    // operator < for std::map
    bool operator<(const GameObject& g) const {
        return getUid() < g.getUid();
    }

    // operator == for std::map
    bool operator==(const GameObject& g) const {
        return getUid() == g.getUid();
    }
};

// hash function for std::unordered_map
template <typename T>
struct std::hash<Vector2<T>> {
    size_t operator()(const Vector2<T> &v) const {
        return hash<T>()(v.x) ^ hash<T>()(v.y);
    }
};

// hash function for std::unordered_map
template <>
struct std::hash<GameObject> {
    size_t operator()(const GameObject &g) const {
        return std::hash<size_t>()(g.getUid());
    }
};

std::unordered_map<Vector2i, std::unordered_set<GameObject>> quantizedMap;
std::unordered_set<GameObject> gameObjects;
std::unordered_map<Vector2i, bool> isWall;

std::vector<Vector2i> getVisitableNeighbors(const Vector2i& v) {
    std::vector<Vector2i> neighbors;
    auto candidates = {Vector2i(1, 0), Vector2i(-1, 0), Vector2i(0, 1), Vector2i(0, -1)};
    for (auto c : candidates) {
        Vector2i n = v + c;
        if (!isWall.contains(n)) {
            neighbors.push_back(n);
        }
    }
    return neighbors;
}

// Pathfinding algorithm from position A to position B
std::vector<Vector2i> findPath(const Vector2f& start, const Vector2f& end) {
    // quantize
    Vector2i startQuantized = start.quantized();
    Vector2i endQuantized = end.quantized();

    // datastructures
    std::unordered_map<Vector2i, bool> isVisited;
    std::unordered_map<Vector2i, Vector2i> cameFrom;
    std::unordered_map<Vector2i, float> costSoFar;
    std::unordered_map<Vector2i, float> priority;
    std::priority_queue<std::pair<float, Vector2i>> frontier;

    // initialize
    isVisited[startQuantized] = false;
    costSoFar[startQuantized] = 0;
    priority[startQuantized] = 0;
    frontier.push({0, startQuantized});

    // main loop
    while (!frontier.empty()) {
        auto current = frontier.top().second;
        frontier.pop();

        if (current == endQuantized) {
            break;
        }

        for (auto next : getVisitableNeighbors(current)) {
            float newCost = costSoFar[current] + current.distance(next);
            if (!costSoFar.contains(next) || newCost < costSoFar[next]) {
                costSoFar[next] = newCost;
                float priority = newCost + next.distance(endQuantized);
                frontier.push({-priority, next});
                cameFrom[next] = current;
            }
        }
    }

    // reconstruct path
    std::vector<Vector2i> path;
    Vector2i current = endQuantized;
    while (current != startQuantized) {
        path.push_back(current);
        current = cameFrom[current];
    }
    path.push_back(startQuantized);
    std::reverse(path.begin(), path.end());
    return path;
}



int main() {
    // Create 2 Game Objects
    GameObject a(Vector2f(0, 0));
    GameObject b(Vector2f(10, 10));

    // place walls
    isWall[Vector2i(1, 1)] = true;
    isWall[Vector2i(1, 2)] = true;
    isWall[Vector2i(1, 3)] = true;
    isWall[Vector2i(1, 4)] = true;
    isWall[Vector2i(1, 5)] = true;

    // add game objects to the set
    gameObjects.insert(a);
    gameObjects.insert(b);

    // add game objects to the quantized map
    for (auto& g : gameObjects)
        quantizedMap[g.position.quantized()].insert(g);

    // find path
    auto path = findPath(a.position, b.position);

    // print path
    for (auto& p : path) {
        std::cout << p.x << " " << p.y << std::endl;
    }

    return 0;
}
```