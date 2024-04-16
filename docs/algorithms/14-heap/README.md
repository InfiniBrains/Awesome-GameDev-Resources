# Heap

Heap is a data structure and algorithm that always keep the highest or lowest element at the top. You can implement it in many ways, a tree or a priority queue.

## Heap in a tree

In a tree implementation, it can have many children per node, but the most common is a binary heap tree. In this scenario, the parent is always greater than the both children, this is called max heap. The opposite is min heap. 

The complexity of a heap is `O(log(n))` for insert and remove operations on average if balanced and `O(n)` in the worst case. For peeking the top element is `O(1)`. 

## Heap in a priority queue

The most common implementation of a heap in a priority queue is in a array(vector). Assuming the current element is at index `i`, the parent is at `(i-1)/2`, the left child is at `2*i+1` and the right child is at `2*i+2`. This approach is called tree linearization. It is more memory efficient and cache friendly.

The complexity of a heap in a priority queue in array is the same as in a tree, but with lower overhead.

## Operation Peek and Pop

Peek will return the top element of the heap, but not remove it. Pop is similar to peek, but it will remove the top.

## Heapfy

Heapfy is an operation that for a given array, it will transform it into a heap. The complexity is `O(n)` if done bottom-up. That's one of the reasons heaps are so efficient. After that, all calls to get the top element will be `O(1)`.

The algorithm is simple, for each element in the array, it will compare with the parent and swap if necessary. It will do it until the element is in the right place.

See animation here https://www.cs.usfca.edu/~galles/JavascriptVisual/Heap.html

## Insert