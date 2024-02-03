# Spatial Hashing

A Spatial Hashing is a common technique to speed up queries in a multidimensional space. It is a data structure that allows you to quickly find all objects within a certain area of space. It is commonly used in games and simulations to speed up, artificial intelligence world queries, collision detection, visibility testing and other spatial queries.

Advantages of the spatial hashing:

- simple to implement;
- very fast: as fast as your key hashing function; 
- easy to parallelize;
- a good choice for big worlds;

Problem with spatial hashing:

- it is not precise;
- it is not good for small worlds;
- needs fine tune to find the right cell size;
- have to update the bucket when the object moves;
- find the nearest objects is not trivial, you will have to query the adjacent cells;

## Buckets

The core of the spatial hashing is the bucket. It is a container that holds all the objects that are within a certain area of space contained in the cell area or volume. The terms cell and bucket can be interchangeable in this context.

In order to find buckets, you will have to create ways to quantize the world space into a grid of cells. It is hard to define the best cell size, but it is a good practice to make it be a couple of times bigger than the biggest object you have in the world. The cell size will define the precision of the spatial hashing, and the bigger it is, the less precise it will be.

## Spatial quantization

The spatial quantization is the process of converting a continuous space into a discrete space. This is the core process of finding the right bucket for an object. Let's assume that we have a 2D space, and we want to find the bucket for a given object. 

```c++
// assuming Vector2f is a 2D vector with float components;
// and Vector2i is a 2D vector with integer components;
// the quantizations gunction will be:
Vector2i quantize(Vector2f position, float cellSize) {
    return Vector2i{
        (int)(position.x / cellSize),
        (int)(position.y / cellSize)};
}
```

## Data structures

### Data structure for the bucket

First, we have to decide the data structure your bucket will use to store the objects. The common choices are:

- `vector<GameObject*>` - a vector of pointers to game objects;
- `set<GameObject*>` - a set of pointers to game objects;
- `unordered_set<GameObject*>` - an unordered_set of pointers to game objects;

- The problem of using a `vector` is that it is not efficient to remove, and find an object in it: `O(n)`; but it is efficient to add (amortized `O(1)`) and iterate over it (random access is `O(1)`).
- The underlying data structure of a `set` and `map` is a binary search tree, so it is efficient to find, add and remove objects: `O(lg(n))`, but it is not efficient to iterate over it. 
- Now, the `unordered_set` and `unordered_map` is a hash table, so it is efficient to find, add and remove objects: `O(1)`, and it is efficient to iterate over it. The overhead of using a hash table is the memory usage and the hashing function. It will be as fast as your hashing function.

In our use case, we will frequently list all elements in a bucket, we will add and remove elements from it, while they move in the world. So, the best choice is to use an `unordered_set` of pointers to game objects.

So lets define the bucket:

```cpp
using std::unordered_set<GameObject*> = bucket_t;
```

### Data structure for indexing buckets

Ideally, we are looking for a data structure that will give us a bucket for a given position. We have some candidates for this job:

- `bucket_t[width][height]` - a 2D array of buckets;
- `vector<vector<bucket_t>>` - a 2D vector of buckets;
- `map<Vector2i, bucket_t>` - a map of buckets;
- `unordered_map<Vector2i, bucket_t>` - a map of buckets;

- `array`s and `vector`s are the fastest data structures to use, but they are not good choices if you have a sparse world;
- `map` is a binary search tree;
- `unordered_map` is a hash table.

The `unordered_map` is the best choice for this use case.

```c++
// quantized world
unordered_map<Vector2i, go_bucket_t> world;
```

### Iterating over the whole world at once

Sometimes we just want to iterate over all objects in the world, add and remove elements. In this case, we can use a `unordered_set` to store all game objects.

```c++
// all game objects for faster global world iteration and cleanup
go_bucket_t worldObjects;
```

## Implementation

This sample here is a bit complex, but I added a bunch of support code  to make it more complete, feel free to simplify it to your needs.

```cpp
#include <iostream> // for cout
#include <unordered_map> // for unordered_map
#include <unordered_set> // for unordered_set
#include <random> // for random_device and default_random_engine
#include <cmath> // for floor
#include <cstdint> // for int32_t
#include <memory> // for shared_ptr

using namespace std;

// to allow derivated structs to be used as keys in sorted containers and binary search algorithms
template<typename T>
struct IComparable { virtual bool operator<(const T& other) const = 0; };
// to allow derivated structs to be used as keys in hash based containers and linear search algorithms
template<typename T>
struct IEquatable { virtual bool operator==(const T& other) const = 0; };

// generic Vector2
// requires that T is a int32_t or float_t
template<typename T>
#ifdef __cpp_concepts
requires std::is_same_v<T, int32_t> || std::is_same_v<T, float_t>
#endif
struct Vector2: public IComparable<Vector2<T>>, public IEquatable<Vector2<T>> {
    T x, y;
    Vector2(): x(0), y(0) {}
    Vector2(T x, T y): x(x), y(y) {}
    // operator equals
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    // operator < for being able to use it as a key in a map or set
    bool operator<(const Vector2& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    // quantize the vector to a 2d index
    // you may want to simplify this function to use less instructions
    Vector2<int32_t> quantized(float_t cellSize=1.0f) const {
        return Vector2<int32_t>{
                static_cast<int32_t>(std::floor(x + cellSize/2) / cellSize),
                static_cast<int32_t>(std::floor(y + cellSize/2) / cellSize)
        };
    }
};

// specialized Vector2 for int and float
using Vector2i = Vector2<int32_t>;
// float32_t is only available in c++23, so we use float_t instead
using Vector2f = Vector2<float_t>;

// helper struct to generate unique id for game objects
// mostly debug purposes
struct uid_type {
private:
    static inline size_t nextId = 0; // to be used as a counter
    size_t uid; // to be used as a unique identifier
public:
    // not thread safe, but it is not a problem for this example
    uid_type(): uid(nextId++) {}
    inline size_t getUid() const { return uid; }
};

// generic game object implementation
// replace this with your own data that you want to store in the world
class GameObject: public uid_type, public enable_shared_from_this<GameObject> {
    Vector2f position;
public:
    GameObject(): uid_type(){};
    GameObject(const GameObject& other): uid_type(other), position(other.position) {}
    // todo: add your other custom data here
    // when the it moves, it should check if it needs to update its bucket in the world
    void setPosition(const Vector2f& newPosition);
    Vector2f getPosition() const { return position; }
};

// hashing
namespace std {
    // Hash specialization for Vector2 types
    template<typename T>
    struct hash<Vector2<T>> {
    size_t operator()(const Vector2<T>& v) const {
        // given both x and y are 32 bits, we can shift and xor operator the other to get a unique hash
        // the problem of this approach is that it will generate neighboring cells with similar hashes
        // to fix that, you might want to use a more complex hashing function from std::hash<T>
        // hash<size_t>{}((*(size_t*)&v.x << 32) ^ (*(size_t*)&v.y))
        return (*(size_t*)&v.x << 32) ^ (*(size_t*)&v.y);
    }
};
}

// game object pointer
// shared pointer is used to avoid memory leaks
using GameObjectPtr = std::shared_ptr<GameObject>;
// alias for the game object bucket
using go_bucket_t = std::unordered_set<GameObjectPtr>;
// alias for the world type
using world_t = std::unordered_map<Vector2i, go_bucket_t>;

// singletons here are being used to avoid global variables and to allow the world to be used in a visible scope
// you should use a better wrappers and abstractions in a real project
// singleton world
world_t& world() {
    static world_t world;
    return world;
}
// singleton world objects
go_bucket_t& worldObjects(){
    static go_bucket_t worldObjects;
    return worldObjects;
}

// this function requires the world to be in a visible scope like this or change it to access through a singleton
void GameObject::setPosition(const Vector2f& newPosition) {
    // check if it needs to update its bucket in the world
    if (position.quantized() == newPosition.quantized())
        return;
    // remove from old bucket
    world()[position.quantized()].erase(shared_from_this());
    // update position
    position = newPosition;
    // add to new bucket
    world()[position.quantized()].insert(shared_from_this());
}

// random vector2f
Vector2f randomVector2f(float_t min, float_t max) {
    static random_device rd;
    static default_random_engine re(rd());
    static uniform_real_distribution<float_t> dist(min, max);
    return Vector2f{dist(re), dist(re)};
}

int main() {
    // fill the world with some random game objects
    for (int i = 0; i < 121; i++) {
        auto obj = std::make_shared<GameObject>();
        obj->setPosition(randomVector2f(-5, 5));
        world()[obj->getPosition().quantized()].insert(obj);
        worldObjects().insert(obj);
    }
    // randomlly move the game objects
    // move them, this will update their position and their bucket in the world
    for (auto& obj: worldObjects()) {
        obj->setPosition(randomVector2f(-5, 5));
    }

    // print the bucket id and every object in it
    for (auto& bucket: world()) {
        cout << "bucket " << bucket.first.x << ", " << bucket.first.y << endl;
        for (auto& obj: bucket.second)
            cout << "  object " << obj->getUid() << " at " << obj->getPosition().x << ", " << obj->getPosition().y << endl;
    }

    return 0;
}
```

## Homework

1. Implement a spatial hashing for a 3D world;
2. Implement another space partition technique, such as a quadtree/octree/kdtree and compare:
    1. the performance of both in scenarios of moving objects, searching for objects and adding / removing objects;
    2. memory consumption;
    3. which one will be slow down faster the bigger the world becomes; 