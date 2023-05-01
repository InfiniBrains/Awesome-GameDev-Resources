# Loops, for, while and goto

A loop is a control flow statement that allows you to repeat a block of code. 

# while loop

This loop is used when you want to execute a block of code an unknown number of times, as long as a certain condition is true. It has the following syntax:

Syntax:
```c++
while (condition) {
    // code block to be executed
}
```
Example:
```c++
int nums = 10;
while (nums>=0) {
    cout << nums << endl;
    nums--;
}
```

If the block is only one statement, it can be expressed without `{}`s.

Syntax:
```c++
while (condition) 
    // statement goes here
```
Example:
```c++
int nums = 10;
while (nums>=0) 
    cout << nums-- << endl;
```

# do-while loop

This is similar to the `while` loop, but it is guaranteed to execute at least once.

Syntax: 

```c++
do {
    // code block to be executed
} while (condition);
```

Example:
```c++
int x = 0;
do{
    cout << x << endl;
    x++;
} while(x<10);
```

If the block is only one statement, it can be expressed without `{}`s.

Syntax:
```c++
do
    // single statement goes here
while (condition);    
```
Example:
```c++
int x = 0;
do 
    cout << x++ << endl;
while (x<=10);
```

# for loop

This loop is used when you know in advance how many times you want to execute a block of code.

- The initialization part is executed only once, at the beginning of the loop. It is used to initialize any loop variables.
- The condition is evaluated at the beginning of each iteration of the loop. If the condition is true, the code block inside the loop is executed. If the condition is false, the loop is terminated.
- The increment part is executed at the end of each iteration of the loop. It is used to update the loop variables.

Syntax:
```c++
for (initialization; condition; step_iteration) {
    // code block to be executed
}
```

Example:
```c++
for(int i=10; i<=0; i--){
    cout << i << endl; 
}
```

If the block is only one statement, it can be expressed without `{}`s.

Syntax:
```c++
for (initialization; condition; step_iteration)
    // single statement goes here
```
Example:
```c++
for(int i=10; i<=0; i--)
    cout << i << endl;
```

# range based loops

A range-based loop is a loop that iterates over a range of elements. The declaration type should follow the same type of the elements in the range. 

Syntax:
```c++
for (declaration : range) {
    // code block to be executed
}
```
or
```c++
for (declaration : range)
    // single statement
```

To avoid explaining arrays and vectors now, assume `v` as an iterable container that can hold multiple elements. I am going to use auto here to avoid explaining this topic any further.
```c++
auto v = {1, 2, 3, 4, 5}; // an automatically inferred iterable container with multiple elements
for (int x : v) {
    cout << x << " ";
}
```

It is possible to automatically generate ranges  
```c++
#include <ranges>
#include <iostream>
using namespace std;
int main() {  
    // goes from 0 to 9. in iota, the first element is inclusive and the last one is exclusive.
    for (int i : views::iota(0, 10))  
        cout << i << ' ';
}
```

# Loop Control Statements

## `break`

`break` keyword defines a way to break the current loop and end it immediately.

```c++
// check if it is prime
int num; 
cin >> num; // read the number to be checked if is prime or not
bool isPrime = true;
for(int i=2; i<num; i++){
    if(num%i==0){ // check if i divides num
        isPrime = false;
        break; // this will break the loop and prevent further precessing
    }
}
```

## `continue`

`continue` keyword is used to skip the following statements of the loop and move to the next iteration.

```c++
// print all even numbers
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 1)
        continue;
    cout << i << " "; // this statement is skipped if odd numbers
}
```

## `goto`

[You should avoid `goto` keyword](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-goto). PERIOD. The only acceptable usage is to break multiple nested loops at the same time. But even in this case, is better to use `return` statement and `functions` that you're going to see later in this course.  

The `goto` keyword allows you to transfer control to a labeled statement elsewhere in your code. 

Example on how to create a loop using labels and goto. You can create a loop just using labels(anchors) and goto keywords. But this syntax is hard to debug and read. Avoid it at all costs:

```c++
#include <iostream>
using namespace std;
int main() {
    int i=0;
    start: // this a label named as start.
    cout << i << endl;
    i++;
    if(i<10)
        goto start; // jump back to start
    else
        goto finish; // jump to finish
    finish: // this a label named as finish.
    return 0;
}
```

Example on how to jump over and skip statements:
```c++
#include <iostream>

int main() {
    int x = 10;

    goto jump_over_this;  // control jumps to the label below

    x = 20;  // this line of code is skipped

    jump_over_this:  // label for goto statement
    std::cout << x << std::endl;  // outputs 10

    return 0;
}
```

Example of an arguably acceptable use of `goto`. Here you can see the usage of a way to break both loops at the same time. If you use `break`, you will only break the inner loop. In this situation it is better to break your code into functions to reduce complexity and nesting. 
```c++
for (int i = 0; i < imax; ++i)
    for (int j = 0; j < jmax; ++j) {
        if (i + j > elem_max) goto finished;
        // ...
    }
finished:
// ...
```

# Loop nesting

You can nest loops by placing one loop inside another. The inner loop will be executed completely for each iteration of the outer loop. Here is an example of nesting a for loop inside another for loop:

```c++
for (int i = 0; i < 10; i++) {
  for (int j = 0; j < 5; j++) {
    cout << "i: " << i << " j: " << j << endl;
  }
}
```

# Infinite loops

A infinite loop is when the code loops indefinitely without having a way out. Here goes some examples:

```c++
while(true)
    cout << "Hello World!" << endl; 
```

```c++
for(;;)
    cout << "Hello World!" << endl; 
```

```c++
int i = 0;
while(i<10); // note the ';' here, it will run indefinitely an empty statement because it won't reach the scope.
{
    cout << i << endl;
    i++;
}
```

# Accumulator Pattern

The accumulator pattern is a way to accumulate values in a loop. Here is an example of how to use it:

```c++
int fact = 1; // accumulator variable
for(int i=2; i<5; i++){
    fact *= i; // multiply the accumulator by the current value of i
}
// fact = 1*1*2*3*4 = 24
cout << fact << endl;
```

# Search pattern

The search pattern is a way to search for a value in a loop, the most common implementation is a boolean flag. Here is an example of how to use it:

```c++
int num;
cin >> num; // read the number to be checked if is prime or not
bool isPrime = true; // flag to indicate if the number is prime or not
for(int i=2; i<num; i++){
    if(num%i==0){ // check if i divides num
        isPrime = false;
        break; // this will break the loop and prevent further precessing
    }
}
cout << num << " is " << (isPrime ? "" : "not ") << "prime" << endl;
// (isPrime ? "" : "not ") is the ternary operator, it is a shorthand for if-else
```

# Debugging

Debugging is the act of instrumentalize your code in order to track problems and fix them.

The most naive way of doing it is by printing variables random texts to find the problem. Don't do it. Use debugger tools instead. Each IDE has his its ows set of tools, if you are using CLion, use this [tutorial](https://www.jetbrains.com/help/clion/debugging-code.html).

# Automated tests

There are lots of methodologies to guarantee your code is correct and solve the problem it is supposed to solve. The one that stand out is Automated tests.

When you are using beecrowd, leetcode, hackerrank or any other tool to solve problems to learn how to code, a problem is posted to be solved and they test your code solution against a set of expected outputs. This is automated testing. You can generate custom automated tests for your code and cover all cases that you can imagine before you start coding the solution. This is a good practice and is documented in the industry as Test Driven Development.

# Homework

Do all exercises up to this topic [here](https://www.w3schools.com/cpp/exercise.asp).

In this activity, you will have to solve Fibonacci sequence. You should implement using loops, and variables. Do not use arrays nor closed-form formulas.

- [Easy Fibonacci](https://www.beecrowd.com.br/judge/en/problems/view/1151)

Optional Readings on [Fibonacci Sequence](https://en.wikipedia.org/wiki/Fibonacci_number);

Hint: Create two variables, one to store the current value and the previous value. For each iteration step, calculate the sum of both and store and put into a temp variable. Copy the current into the previous and set the current with the temporary you calculated before.

# Outcomes

It is expected for you to be able to solve all questions before this one `1151` on beecrowd. Sort Beecrowd questions from the most solved to the least solved questions [here](https://www.beecrowd.com.br/judge/en/search?q=&sort=Problems.solved&direction=desc) in the link. If you don't, see [Troubleshooting](#troubleshooting). Don`t let your study pile up, this homework is just a small test, it is expected from you to do other questions on Beecrowd or any other tool such as leetcode.

# Troubleshooting
If you have problems here, start a [discussion](https://github.com/InfiniBrains/Awesome-GameDev-Resources/discussions). Nhis is publicly visible and not FERPA compliant. Use discussions in Canvas if you are enrolled in a class with me. Or visit the tutoring service.