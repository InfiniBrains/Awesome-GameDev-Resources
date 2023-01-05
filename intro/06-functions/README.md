# Base Conversion, Functions, Pointers, Parameter Passing

# Base conversion

Data containers use binary coding to store data where every digit can be 0 or 1, this is called base 2, but there are different types of binary encodings and representation, the most common integer representation is [Complement of two](https://en.wikipedia.org/wiki/Two%27s_complement) for representing positive and negative numbers and for floats is [IEEE754](https://en.wikipedia.org/wiki/IEEE_754). Given that, it is relevant to learn how to convert the most used common bases in computer science in order to code more efficiently.

Most common bases are:
- Base 2 - Binary. Digits can go from 0 to 1. `{0, 1}`;
- Base 8 - Octal. Digits can go from 0 to 7. `{0, 1, 2, 3, 4, 5, 6, 7}`; 
- Base 10 - Decimal. Digits can go from 0 to 9. `{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}`;
- Base 16 - Hexadecimal. Digits can go from 0 to 9 and then from A to F. `{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}`;

## Converting from Decimal to any base

There are several methods for performing base conversion, but one common method is to use the repeated division and remainder method. To convert a number from base 10 to another base `b`, you can divide the number by `b` and record the remainder. Repeat this process with the quotient obtained from the previous division until the quotient becomes zero. The remainders obtained during the process will be the digits of the result in the new base, with the last remainder being the least significant digit.

For example, to convert the decimal number 75 to base 2 (binary), we can follow these steps:

```
75 ÷ 2 = 37 remainder 1
37 ÷ 2 = 18 remainder 1
18 ÷ 2 = 9 remainder 0
9 ÷ 2 = 4 remainder 1
4 ÷ 2 = 2 remainder 0
2 ÷ 2 = 1 remainder 0
1 ÷ 2 = 0 remainder 1
```

The remainders obtained during the process (1, 1, 0, 1, 0, 0, 1) are the digits of the result in base 2, with the last remainder (1) being the least significant digit. Therefore, the number 75 in base 10 is equal to 1001011 in base 2.

## Converting from any base to decimal

The most common way to convert from any base to decimal is to follow the formula:

> d<sub>n-1</sub>*b<sup>n-1</sup> + d<sub>n-2</sub>*b<sup>n-2</sup> + ... + d<sub>1</sub>*b<sup>1</sup> + d<sub>0</sub>*b<sup>0</sup> 

Where d<sub>x</sub> represents the digit at the corresponding position x in the number, n is the number of digits in the number, and b is the base of the number.

For example, to convert the number 1001011 (base 2) to base 10, we can use the following formula:

(1 * 2^6) + (0 * 2^5) + (0 * 2^4) + (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0) = 75

Therefore, the number 1001011 in base 2 is equal to 75 in base 10.

# Functions

A function is a block of code that performs a specific task. It is mostly used to isolate specific reusable functionality from the rest of the code. It has a name, a return type, and a list of parameters. Functions can be called from other parts of the program to execute the task. Here is an example of a simple C++ function that takes two integers as input and returns their sum.

```c++
int add(int x, int y) {
  int sum = x + y;
  return sum;
}
```

To call the function, you would use its name followed by the arguments in parentheses:

```c++
int a = 2, b = 3;
int c = add(a, b); // c will be equal to 5
```

Functions can also be declared before they are defined, in which case they are called "prototypes." This allows you to use the function before it is defined, which can be useful if you want to define the function after it is used. For example:

```c++
int add(int x, int y);

int main() {
  int a = 2, b = 3;
  int c = add(a, b);
  return 0;
}

int add(int x, int y) {
  int sum = x + y;
  return sum;
}
```

# Reference Declaration

NOTE: this only covers an introduction to the topic.  

The `&` is used to refer memory address of the variable. When used in the declaration, it is the Lvalue reference declarator. It is an alias to an already-existing, variable, object or function. [Read more here](https://en.cppreference.com/w/cpp/language/declarations).

When used as an prefix operator before the name of a variable, it will return the memory address where the variable is allocated.

Example:
```c++
string s;

// the variable r has the same memory address of s
// the declaration requires initialization
string& r = s; 

s = "Hello";

cout << &s << endl; // prints the variable memory address location. in my machine: "0x7ffc53631cd0"
cout << &r << endl; // prints the same variable memory address location. in my machine: "0x7ffc53631cd0"

cout << s << endl; // prints "Hello"
cout << r << endl; // prints "Hello"

// update the content
r += " world!";

cout << s << endl; // prints "Hello world!"
cout << r << endl; // prints "Hello world!"
```

# Pointer Declaration

NOTE: this only covers an introduction to the topic. 

The `*` is used to declare a variable that holds the address of a memory position. A pointer is an integer number that points to a memory location of a container of a given type. [Read more here](https://en.cppreference.com/w/cpp/language/pointer).

```c++
string* r = nullptr; // it is not required do initialize, but it is a good practice to always initialize a pointer pointing to null address (0). 
string s = "Hello";
r = &s; // the variable r stores the memory address of s

cout << s << endl; // prints the content of the variable s. "Hello"
cout << &s << endl; // prints the address of the variable s. in my machine "0x7fffdda021b0"

cout << r << endl;  // prints the numeric value of the address the pointer points, in this case it is "0x7fffdda021b0".
cout << &r << endl; // prints the address of the variable r. it is a different address than s, in my machine "0x7fffdda021d0".
cout << *r << endl; // prints the content of the container that is pointing, it prints "Hello".

string other = "world";
r = &s; // r now points to another variable

cout << *r << endl; // prints the content of the container that is pointing, it prints "world"
```

# Passing parameter to a function by value

Pass-by-value is when the parameter declaration follows the traditional variable declaration without `&`. A copy of the value is made and passed to the function. Any changes made to the parameter inside the function have don't change on the original value outside the function.

```c++
#include <iostream>
using namespace std;
void times2(int x) {
    x = x * 2;
    // the value x here is doubled. but it dont change the value outside the scope
}

int main()
{
    int y = 2;
    times2(y); // this dont change the value, it passes a copy to the function
    cout << y << endl;  // output: 2
    return 0;
}
```

# Passing parameter to a function by reference

Pass-by-reference occurs when the function parameter uses the `&` in the parameter declaration. It will allow the function to modify the value of the parameter directly in the other scope, rather than making a copy of the value as it does with pass-by-value. The mechanism behind the variable passed is that it is an alias to the outer variable because it uses the same memory position.

```c++
#include <iostream>
using namespace std;
void times2(int &x) { // by using &, x has the same address the variable passed where the function is called 
  x*=2; // it will change the variable in caller scope
}

int main() {
  int y = 2;
  times2(y);
  cout << y << endl;  // Outputs 4
  return 0;
}
```

# Passing parameter to a function by pointer

Pass-by-pointer occurs when the function parameter uses the `*` in the parameter declaration. It will allow the function to modify the value of the parameter in the other scope via memory pointer, rather than making a copy of the value as it does with pass-by-value. The mechanism behind it is to pass the memory location of the outer variable as a parameter to the function.

```c++
#include <iostream>
using namespace std;
void times2(int *x) { // by using *, x has the same address the variable passed where the function is called
    // x holds the address of the outer variable
    // *x is the content of what x points.
  *x *= 2; // it will change the variable in caller scope
}

int main() {
  int y = 2;
  times2(&y); // the function expects a pointer, given pointer is an address, we pass the address of the variable here
  cout << y << endl;  // Outputs 4
  return 0;
}
```

# Function overload

A function with a specific name can be overload with different not implicitly convertible parameters.

```c++
#include <iostream>
using namespace std;

float average(float a, float b){
    return (a + b)/2;
}

float average(float a, float b, float c){
    return (a + b + c)/3;
}

int main(){
    cout << average(1, 2) << endl; // print 1.5
    cout << average(1, 2, 3) << endl; // print 2
    return 0;
}
```

# Default parameter

Functions can have default parameters that should be used if the parameter is not provided, making it optional.

```c++
#include <iostream>
using namespace std;

void greet(string username = "user") {
    cout << "Hello " << mes << endl;
}

int main() {
  // Prints "Hello user"
  greet(); // the default parameter user is used here

  // Prints "Hello John"
  printMessage("John");
  
  return 0;
}
```

# Scopes

Scope is a region of the code where a identifier is accessible. A scope usually is specified by what is inside `{` and `}`. The global scope is the one that do not is inside any `{}`.

```c++
#include <iostream>
#include <string>
using namespace std;
string h = "Hello"; // this variable is in the global scope
int main() {
  string w = " world"; // this variable belongs to the scope of the main function
  cout << h << w << endl; // both variables are visible and accessible
  return 0;
}
```

Multiple identifiers with same name can not be created in the same scope. But in a nested scope it is possible to shadow the outer one when declared in the inner scope.

```c++
#include <iostream>
#include <string>
using namespace std;
string h = "Hello"; // this variable is in the global scope
int main() {
  cout << h; // will print "Hello"
  string h = " world"; // this will shadow the global variable with the same name h
  cout << h; // will print " world"
  return 0;
}
```

# Homework

Do all exercises up to this topic here https://www.w3schools.com/cpp/exercise.asp

- [Hexadecimal converter](https://www.beecrowd.com.br/judge/en/problems/view/1957). In this activity, you will have to code a way to find the convert to hexadecimal.

# Outcomes

It is expected for you to be able to solve all questions before this one `1957` on beecrowd. Sort Beecrowd questions from the most solved to the least solved questions [here](https://www.beecrowd.com.br/judge/en/search?q=&sort=Problems.solved&direction=desc) in the link. If you don't, see [Troubleshooting](#troubleshooting). Don`t let your study pile up, this homework is just a small test, it is expected from you to do other questions on Beecrowd or any other tool such as leetcode.

# Troubleshooting
If you have problems here, start a [discussion](https://github.com/InfiniBrains/Introduction-to-Game-Programming-With-CPP/discussions). Nhis is publicly visible and not FERPA compliant. Use discussions in Canvas if you are enrolled in a class with me. Or visit the tutoring service.