# Arrays

An array is a collection of similar data items, stored in contiguous memory locations. The items in an array can be of any built-in data type such as int, float, char, etc. An array is defined using a syntax similar to declaring a variable, but with square brackets indicating the size of the array.

Here's an example of declaring an array of integers with a size of 5:

```c++
int arr[5]; // declare an array of size 5 at the stack
```

The above declaration creates an array named arr of size 5, which means it can store 5 integers. The array elements are stored in contiguous memory locations, which means the next element is stored at the immediate next memory location. The first element of the array is stored at the 0th index, the second element at the 1st index, and so on up to 4. Between 0 an 4 all inclusive we have 5 elements.

This creates an array called "myArray" that can hold 5 integers. The first element of the array is accessed using the index 0, and the last element is accessed using the index 4. You can initialize the array elements during declaration by providing a comma-separated list of values enclosed in braces:

```c++
int myArr[5] = {10, 20, 30, 40, 50}; // initialize the array with 5 elements
```

In this case, the first element of the array will be 10, the second element will be 20, and so on.

You can also use loops to iterate over the elements of an array and perform operations on them. For example:

```c++
for (int i = 0; i < 5; i++) { 
  myArray[i] *= 2;
}
```

This loop multiplies each element of the "myArray" by 2.

Arrays are a useful data structure in C++ because they allow you to store and manipulate collections of data in a structured way. However, they have some limitations, such as a fixed size that cannot be changed at runtime, and the potential for buffer overflow if you try to access elements beyond the end of the array.

# Buffer overflow

A buffer overflow occurs when a program attempts to write more data to a fixed-size buffer than it can hold. This can happen when a program attempts to write more data to a buffer than the buffer can hold, or when a program attempts to read more data from a buffer than the buffer contains. This can happen when a program attempts to write more data to a buffer than the buffer can hold, or when a program attempts to read more data from a buffer than the buffer contains.

A buffer overflow can be caused by a number of different factors, including:

- A program that attempts to write more data to a buffer than the buffer can hold
- A program that attempts to read more data from a buffer than the buffer contains

Buffer overflow vulnerabilities are a common type of security vulnerability, as they can be exploited by malicious attackers to execute arbitrary code or gain unauthorized access to a system. To prevent buffer overflow vulnerabilities, it's important to carefully manage memory allocation and use bounds checking functions or techniques such as using safe C++ library functions like `std::vector` or `std::array`, and ensuring that input data is properly validated and sanitized.

# Multi-dimensional arrays

A multi-dimensional array is an array of arrays. For example, a 2-dimensional array is an array of arrays, where each element of the array is itself an array. A 3-dimensional array is an array of 2-dimensional arrays, where each element of the array is itself a 2-dimensional array. And so on.

For example, to declare a two-dimensional array with 3 rows and 4 columns of integers, you would use the following code:

```c++
int arr[3][4]; // Declare a 2-dimensional array with 3 rows and 4 columns at the stack
```

You can access elements in a multidimensional array using multiple sets of square brackets. For example, to access the element at row 2 and column 3 of myArray, you would use the following code:

```c++
int element = myArray[1][2]; // Access the element at row 2 and column 3
```

In C++, you can have arrays with any number of dimensions, but keep in mind that as the number of dimensions increases, it becomes more difficult to manage and visualize the data.

# Array dynamic allocation

In some cases, you dont know the size of the array at compile time. In this case, you can use dynamic memory allocation to allocate the array at runtime. This is done using the `new` operator, which allocates a block of memory on the heap and returns a pointer to the beginning of the block. For example, to allocate an array of 5 integers on the heap, you would use the following code:

```c++  
int *arr = new int[5]; // Allocate a block of memory on the heap
```

The above code allocates a block of memory on the heap that is large enough to hold 5 integers. The `new` operator returns a pointer to the beginning of the block, which is assigned to the pointer variable `arr`. You can then use the pointer to access the elements of the array. You can access individual elements of the array using the array subscript notation:

```c++
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
arr[3] = 40;
arr[4] = 50;
```

When you are done using the array, you should free the memory using the `delete` operator. For example, to free the memory allocated to the array in the previous example, you would use the following code:

```c++
delete[] arr; // Free the memory by telling the operation system you are done with it
arr = nullptr; // Reset the pointer to null to avoid dangling pointers and other bugs
```

The `delete` operator takes a pointer to the beginning of the block of memory to free. The `[]` operator is used to indicate that the block of memory contains an array, and that the `delete` operator should free the entire array.

## Dynamic allocation of multi-dimensional arrays

In the case of dynamically allocate memory for a multidimensional array, first you have to understand that in the same way you can have an array of arrays, you can have a pointer to a pointer. This is called a double pointer. So, if you want to allocate a 2-dimensional array dynamically, you can do it like this:

```c++
int lines, columns;
cin >> lines >> columns;
int **arr = new int*[lines]; // Allocate an array of pointers to pointers
for (int i = 0; i < lines; i++) {
  arr[i] = new int[columns]; // Allocate an array of integers for each pointer
}
// do stuff with the array
for (int i = 0; i < lines; i++) {
  delete[] arr[i]; // Free the memory for each array of integers
}
delete[] arr; // Free the memory for the array of pointers
```

# Smart pointers to rescue

You probably noticed the number of bugs and vulnerabilities that can be caused by improper memory management. To help address that, C++ introduced smart pointers. The general purpose smart contract you will be mostly using is `shared_ptr` that in the end of the scope and when all references to it become 0 will automatically free the memory. The other smart pointers are `unique_ptr` and `weak_ptr` that are used in more advanced scenarios. But for now, we will focus on `shared_ptr`.

In C++11, smart pointers were introduced to help manage memory allocation and deallocation. Smart pointers are classes that wrap a pointer to a dynamically allocated object and provide additional features such as automatic memory management. The most commonly used smart pointers are `std::unique_ptr` and `std::shared_ptr`. The `std::unique_ptr` class is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `std::unique_ptr` goes out of scope. The `std::shared_ptr` class is a smart pointer that retains shared ownership of an object through a pointer. Several `std::shared_ptr` objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens:

- the last remaining `std::shared_ptr` owning the object is:
    - destroyed
    - is assigned another pointer via `operator=` or `reset()` 
    - is reset or released 
    - moved from
    - is swapped with another `std::shared_ptr` using `swap()`
    - the function `std::shared_ptr::swap()` is called with the last remaining `std::shared_ptr` owning the object as an argument
- the object is no longer reachable from the program (for example, when the program terminates)
- the program:
    - throws an exception that is not caught within the same thread
    - calls terminating calls such as `std::terminate()`, `std::abort()`, `std::exit()`, or `std::quick_exit()`

To create a dynamic array of int using shared pointers, you can use the std::shared_ptr class template. Here's an example:

```c++
#include <memory> // for std::shared_ptr
std::shared_ptr<int[]> arr(new int[5]);
```

This creates a shared pointer to an array of 5 integers. The `new int[5]` expression dynamically allocates memory for the array on the heap, and the shared pointer takes ownership of the memory. When the shared pointer goes out of scope, the memory is automatically freed.

You can access individual elements of the array using the array subscript notation, just like with a regular C-style array:

```c++
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
arr[3] = 40;
arr[4] = 50;
``` 

To deallocate the memory, you don't need to call delete[] explicitly, because the shared pointer takes care of it automatically. When the last shared pointer that points to the array goes out of scope or is explicitly reset, the memory is deallocated automatically:

```c++
arr.reset(); // deallocates the memory and reset the shared pointer to null to avoid dangling pointers and other bugs
```

Shared pointers provide a convenient and safe way to manage dynamic memory in C++, because they automatically handle memory allocation and deallocation, and help prevent memory leaks and dangling pointers.

Smart pointers are no silver bullet. They are not a replacement for proper memory management, but they can help you avoid common memory management bugs and vulnerabilities. For example, smart pointers can help you avoid memory leaks, dangling pointers, and double frees. They can also help you avoid buffer overflow vulnerabilities by providing bounds checking functions.

# Passing arrays to functions

You can pass arrays to functions in C++ in the same way that you pass any other variable to a function. For example, to pass an array to a function, you would use the following code:

```c++
void printArray(int arr[], int size) // Pass the array by reference to avoid copying the entire array
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}
```

Alternativelly you can pass the array as a pointer:

```c++
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}
```

If you want to pass a two dimension array, you can do it in multiple ways:

```c++
void printArray(int rows, int columns, int **arr); // Pass the array as a pointer of pointers
```

This approach is problematic as you can see it in depth [here](https://c-faq.com/aryptr/pass2dary.html). It does not check for types and it is not safe. You can also pass the array as a pointer to an array:

```c++
void printArray(int rows, int arr[][10]); // if you know the number of columns and it is fixed, in this case 10 
```

```c++
void printArray(int rows, int (*arr)[10]); // if you know the number of columns and it is fixed, in this case 10 
```

```c++
void printArray(int arr[10][10]); // if you know the number of rows and columns and they are fixed, in this case both 10
```

There is others ways to pass arrays to functions, such as **templates** but they are more advanced and **we will not cover them now**.

# EXTRA: Standard Template Library (STL)

Those are the most common data structures that you will be using in C++. But it is outside the scope of this course to cover them in depth. So we will only give entry-points for you to learn more about them.

## Arrays

If you are using fixed sized arrays, and want to be safe to avoid problems related to out of bounds, you should use the STL arrays. It is a template class that encapsulates fixed size arrays and adds protections for it. It is a safer alternative to C-style arrays. Read more about it [here](https://en.cppreference.com/w/cpp/container/array).

## Vectors

Vectors are the safest way to deal with dynamic arrays in C++, the cpp core guideline even states that you should use it whenever you can. Vector is implemented in the standard template library and provide a lot of useful functions. Read more about them [here](https://en.cppreference.com/w/cpp/container/vector).

# Extra curiosities

Context on common bugs and vulnerabilities:

- [Weaknesses in the 2022 CWE Top 25 Most Dangerous Software Weaknesses](https://cwe.mitre.org/data/definitions/1387.html)
- [US Government enforces cyber security requirements](https://nvlpubs.nist.gov/nistpubs/ir/2021/NIST.IR.8397.pdf)
- https://en.cppreference.com/w/cpp/language/array