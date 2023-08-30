# Recursion

Recursion is a method of solving problems where the solution depends on solutions to smaller instances of the same problem. It is a common technique used in computer science, and is one of the central ideas of functional programming. Let's explore recursion by looking at some examples.

You have to be aware that recursion isn't always the best solution for a problem. Sometimes it can be more efficient to use a loop and a producer-consumer strategy instead of recursion. But, in some cases, recursion is the more elegant solution.

When you call functions inside functions, the compiler will store the return point, value and variables on the stack, and it has limited size. Each time you call a function, it is added to the top of the stack. When the function returns, it is removed from the top of the stack. The last function to be called is the first to be returned. This is called the call stack. A common source of problems in programming is when the call stack gets too big. This is called a stack overflow. This is why you should be careful when using recursion.

## Fibonacci numbers

The Fibonacci numbers are a sequence of numbers where each number is the sum of the two numbers before it. The constraints are: the first number is 0, the second number is 1, it only run on integers and it is not negative. The sequence looks like this:

```c++
int fibonacci(int n) {
    // base case
    if (n == 0 || n == 1)
        return n;
    else // recursive case
        return fibonacci(n - 1) + fibonacci(n - 2);
}
```

## Factorial numbers

The factorial of a number is the product of all the numbers from 1 to that number. It only works for positive numbers greater than 1.

```c++
int factorial(int n) {
    // base case
    if (n <= 1)
        return 1;
    else // recursive case
        return n * factorial(n - 1);
}
```

# Divide and Conquer

Divide and conquer is a method of solving problems by breaking them down into smaller subproblems. It is extensively used to reduce the complexity of some algorithms and increase readability.

## Binary search

Imagine that you already have a sorted array of numbers and you want to find the location of a specific number in that array. You can use a binary search to find it. The binary search works by dividing the array in half and checking if the number you are looking for is in the first half or the second half. If it is in the first half, you repeat the process with the first half of the array. If it is in the second half, you repeat the process with the second half of the array. You keep doing this until you find the number or you know that it is not in the array.

```c++
// recursive binary search on a sorted array to return the position of a number
int binarySearch(int arr[], int start, int end, int number) {
    // base case
    if (start > end)
        return -1; // number not found
    else {
        // recursive case
        int mid = (start + end) / 2;
        // return the middle if wi find the number
        if (arr[mid] == number)
            return mid;
        // if the number is smaller than the middle, search in left side
        else if (arr[mid] > number)
            return binarySearch(arr, start, mid - 1, number);
        // if the number is bigger than the middle, search in right side
        else
            return binarySearch(arr, mid + 1, end, number);
    }
}
```

Binary search plays a fundamental role in Newton's method, which is a method to find and approximate the result of complex mathematical functions such as the square root of a number. Binary-sort is extensively used in sorting algorithms such as quick sort and merge sort. 

## Merge sort

Please refer to the [Merge sort](../08-sorting/README.md#merge-sort) section in the sorting chapter.