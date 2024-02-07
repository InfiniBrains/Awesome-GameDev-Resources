# Pointers

## Pointer arithmetic

Pointer arithmetic is the arithmetic of pointers. You can call operators `+`, `-`, `++`, `--`, `+=`, and `-=` on pointers passing an integer as the right operand.
    
```c++
#include <iostream>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int* ptr = arr; // ptr points to the first element of the array
  std::cout << *ptr << std::endl; // prints 1
  ptr++; // ptr points to the second element of the array
  std::cout << *ptr << std::endl; // prints 2
  ptr += 2; // ptr points to the fourth element of the array
  std::cout << *ptr << std::endl; // prints 4
  ptr--; // ptr points to the third element of the array
  std::cout << *ptr << std::endl; // prints 3
  std::cout << *(ptr + 1) << std::endl; // prints 4
  std::cout << *(arr + 1) << std::endl; // prints 2
  return 0;
}
```


## Dynamic arrays

Dynamic arrays are arrays that can be allocated and deallocated at runtime. They are useful when the size of the array is not known at compile time.

```c++
#include <iostream>

int main() {
  int n;
  std::cin >> n; // read the size of the array
  int* arr = new int[n]; // dynamic arry allocation
  for (int i = 0; i < n; i++) {
    arr[i] = i; // fill the array with values
  }
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  delete[] arr; // return the memory to the system
  return 0;
}
```

In the example above, we read the size of the array from the standard input, allocate the array, fill it with values, print the values, and then deallocate the array.

## Array decay

When an array is passed to a function, it decays into a pointer to its first element. This means that the size of the array is lost, and the function cannot know the size of the array.

```c++
#include <iostream>

// another possible declaration: void print_array(int* arr, int n) {
void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  print_array(arr, 5);
  return 0;
}
```

So every time you pass an array to a function, you should also pass the size of the array.

## Matrix

A matrix is a two-dimensional array. It can be represented as an array of arrays;

```c++
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m; // read the size of the matrix
  int** matrix = new int*[n]; // allocate the rows
  // allocate the columns
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m]; 
  }
  // fill the matrix with values
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = i * m + j; 
    }
  }
  // print the matrix
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] matrix[i]; // deallocate the columns
  }
  delete[] matrix; // deallocate the rows
  return 0;
}
```

In the example above, we read the size of the matrix from the standard input, allocate the rows, allocate the columns, fill the matrix with values, print the matrix, and then deallocate the matrix.

You can extend the concept of a matrix to a three-dimensional array, and so on.

## Matrix linearization

A matrix can be linearized into a one-dimensional array. This is useful when you want to be cache friendly.

```c++
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m; // read the size of the matrix
  int* matrix = new int[n * m]; // allocate the matrix
  // fill the matrix with values
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i * m + j] = i * m + j; 
    }
  }
  // print the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i * m + j] << " ";
    }
    std::cout << std::endl;
  }
  delete[] matrix; // deallocate the matrix
  return 0;
}
```

## Passing parameters

The common way of passing parameter is a copy of the value. This is not efficient for large objects ex.: the contents of a huge text file.

```c++
#include <iostream>

void printAndIncrease(int x) { // x is a copy of the value
  std::cout << x << std::endl; 
  x++; // the copy is increased but the outer variable is not
}

int main() {
  int x = 42;
  printAndIncrease(x); // prints 42
  printAndIncrease(x); // prints 42
  return 0;
}
```

You can pass a reference to the variable, so the function can modify the outer variable.

```c++
#include <iostream>

void swap(int& a, int& b) { // a and b are references to the variables
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 42, y = 24;
  swap(x, y);
  std::cout << x << " " << y << std::endl; // prints 24 42
  return 0;
}
```

You can also pass a pointer to the variable, so the function can modify the outer variable.

```c++
#include <iostream>

void swap(int* a, int* b) { // a and b are pointers to the variables
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 42, y = 24;
  swap(&x, &y);
  std::cout << x << " " << y << std::endl; // prints 24 42
  return 0;
}
```

As you can see passing as reference is more readable and less error-prone than passing as pointer. But both are valid, and you should be aware of both.

## Smart pointers

Smart pointers are wrappers to raw pointers that manage the memory automatically. They are useful to avoid memory leaks and dangling pointers.

You can implement a naive smart pointer using a struct that will deallocate when it goes out of scope.

```c++
#include <iostream>

template <typename T>
struct SmartPointer {
  T* ptr;
  SmartPointer(T* ptr) : ptr(ptr) {}
  ~SmartPointer() {
    delete ptr;
  }
};

int main() {
  SmartPointer<int> sp(new int(42));
  std::cout << *sp.ptr << std::endl; // prints 42
  return 0;
} // when sp goes out of scope, the destructor is called and the memory is deallocated
```

!!! note
    
    The Standard Library implements 3 types of smart pointers: `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.

### `std::unique_ptr`

The `std::unique_ptr` is a smart pointer that owns the object exclusively. It is useful when you want to transfer the ownership of the object to another smart pointer.

```c++
#include <iostream>
#include <memory>

int main() {
  // make_unique is a C++14 feature
  std::unique_ptr<int> up = std::make_unique<int>(42);
  // or you can just use:
  // std::unique_ptr<int> up(new int(42));
  std::cout << *up << std::endl; // prints 42
  return 0;
} // when up goes out of scope, the destructor is called and the memory is deallocated
```

### `std::shared_ptr`

The `std::shared_ptr` is a smart pointer that owns the object with shared ownership. It is useful when you want to share the ownership of the object with another smart pointer. It is deallocated when the last `std::shared_ptr` goes out of scope.

```c++
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sp1 = std::make_shared<int>(42);
  std::shared_ptr<int> sp2 = sp1;
  std::cout << *sp1 << " " << *sp2 << std::endl; // prints 42 42
  return 0;
} // when sp1 and sp2 goes out of scope, the destructor is called and the memory is deallocated
```

### `std::weak_ptr`

The `std::weak_ptr` is a smart pointer that owns the object with weak ownership. It is useful when you want to observe the object without owning it. It is deallocated when the last `std::shared_ptr` goes out of scope.

!!! note

    `std::weak_ptr` will help solve the circular reference problem.

```c++
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sp1 = std::make_shared<int>(42);
  std::weak_ptr<int> wp = sp1;
  // in order to use a weak pointer, you have to lock it to tell others that you are using it
  std::cout << *sp1 << " " << *wp.lock() << std::endl; // prints 42 42
  return 0;
} // when sp1 goes out of scope, the destructor is called and the memory is deallocated
```

Exaple of a circular reference:

```c++
#include <iostream>
#include <memory>

struct A;
struct B;

struct A {
  std::shared_ptr<B> b;
  ~A() {
    std::cout << "A destructor" << std::endl;
  }
};

struct B {
  std::shared_ptr<A> a;
  ~B() {
    std::cout << "B destructor" << std::endl;
  }
};

int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->b = b;
  b->a = a;
  return 0;
} // memory is leaked: the destructors are not called, and the memory is not deallocated
```

You can solve the circular reference problem using `std::weak_ptr`.

```c++
#include <iostream>
#include <memory>

struct A;
struct B;

struct A {
  std::shared_ptr<B> b;
  ~A() {
    std::cout << "A destructor" << std::endl;
  }
};

struct B {
  std::weak_ptr<A> a;
  ~B() {
    std::cout << "B destructor" << std::endl;
  }
};

int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->b = b;
  b->a = a;
  return 0;
} // when a and b goes out of scope, the destructors are called and the memory is deallocated
```
