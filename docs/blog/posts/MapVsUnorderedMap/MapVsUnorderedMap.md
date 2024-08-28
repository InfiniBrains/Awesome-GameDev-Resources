---
date: 2024-01-29T16:14:00Z
categories:
  - algorithms
  - data structures
  - c++
  - optimization
  - memory
  - cache
  - map
  - unordered_map
authors:
  - tolstenko
---

# Differences between map vs unordered_map

Both `std::map` and `std::unordered_map` are associative containers that store key-value pairs, let's have a deep dive into the differences between them.

![img.png](img.png)

<!-- more -->

## Underlying Data Structure:

- `std::map`: Implements a balanced binary search tree:
    - Usually a red-black tree, but it is defined by the STL implementation provided by your compiler;
    - Ensures that elements are always sorted, which allows for efficient range queries and ordered traversal;
- `std::unordered_map`: Implements a hash table.
    - The elements are not sorted and are stored in buckets based on the hash value of the keys.

- On a `map`, if the tree become too deep, it can have performance issues, because it is O(lg(N)) for almost all functions. The jumps between nodes pointers might not be cache friendly.
- On an `unordered_map`, the keys are stored as hashes and might have collisions, if it does collide to be stored on the same bucket, the search inside it is linear. Given the size of the bucket is usually small, this search is usually fast. 

## Complexity:

On a `map`, when you query, you will pay the price for **navigating a tree** until you find the element you are searching for. While on a `unordered_map` you pay the price for the **hashing function** you use and when it have colision, and pay the price to **find** an element **in a vector** that is the bucket.

- `map`: query(key) -> navigate tree(might be not cache friendly) -> your value;
- `unordered_map`: query(key) -> hash the key(can be costly) -> find the bucket -> linear search in all elements inside the bucket(cache friendly)

### Algorithm analysis:

Evaluate the cost of:

- `map`: 
    1. How many node hops; 
    2. How many key comparisons; 
    3. Tree indexing can fit in the cache the whole time;
- `unordered_map`:
    1. How many CPU cycles the hashing function uses; 
    2. How frequent collisions happens; 
    3. How many elements you will have in the bucket on average?

**Example**:

Assume you have $1024$ elements, a balanced tree can potentially reach 10 levels deep. $\log_{2}(1024) = 10$ .

In a tree search we will **fetch content** of pointers `10` times and make `10` **key comparisons** until we reach the leaves;

If the key is just a pair of `int32_t`, you can easily implement a hash function that concatenates the bits of one into the another and have a `uint64_t` value as the key. This `shift` operation followed by `xor` is really cheap, but still have a constant cost. If your key is anything more complex, you might face a performance penalty. In this case, the cost here will be `2` **basic CPU operations**;

After paying the cost of hashing your key, you will have to **fetch the content of pointer** `1` time to receive the address of an array of elements which is the bucket. Hopefully you just have one element inside it, if not, you will have to **iterate inside the bucket** array.

In a **hashing-bucket** approach you pay the cost of **hashing funtion**, **1 fetch content**, and then the **linear search inside the bucket** array.

**So what is better?** 

a. Jump between memory locations in tree nodes;
b. pay the price for a hashing function and then potentially a search inside an array?

## Insertion, Query, and Deletion Complexity:

- `std::map`:
    - Insertion/Deletion: `O(log n)`
    - Query: `O(log n)`
- `std::unordered_map`:
    - Average-case complexity (amortized):
        - Insertion/Deletion: `O(1)`
        - Query: `O(1)`
    - Worst-case complexity (when dealing with hash collisions):
        - Insertion/Deletion: `O(n)` in the worst case
        - Query: `O(n)` in the worst case

## Ordered vs. Unordered:

- `std::map` maintains order based on the keys, allowing for efficient range queries and ordered traversal of elements.
- `std::unordered_map` does not guarantee any specific order of elements.

## Memory Overhead:

`std::map` typically has a higher memory overhead due to the additional structure needed for the balanced binary search tree.

`std::unordered_map` may have a lower memory overhead, but it can be affected by the load factor and hash collisions.

## Use Cases:

Use `std::map` when you need ordered traversal or range queries and can tolerate slightly slower insertion and deletion.
Use `std::unordered_map` when you need fast average-case constant-time complexity for insertion, deletion, and queries, and the order of elements is not important.

## Closing

In summary, the choice between `std::map` and `std::unordered_map` depends on the specific requirements of your application. If you need ordered elements and can tolerate slightly slower operations, `std::map` might be a better choice. If you prioritize fast average-case constant-time operations and the order of elements is not important, `std::unordered_map` may be more suitable.

I challenge you to implement your own associative container following what you learned here. It is a great exercise to learn how to implement a hash table and a binary search tree. Talk with me via discord if you want to discuss your implementation.
