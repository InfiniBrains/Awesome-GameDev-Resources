# Conditionals, Switch, Boolean Operations

- [Boolean Operations](#boolean-operations)
- [Bitwise Operations](#bitwise-operations)
- [Conditionals](#conditionals)
- [Switch](#switch)

# Boolean Operations

In C++, the boolean operators are used to perform logical operations on boolean values (values that can only be true or false).

## AND

*And* operators can be represented by `&&`(most common syntax) or `and`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative)). This operator represents the logical `AND` operation. It returns `true` if both operands are `true`, and `false` otherwise.
- It needs only if one `false` element to make the result be `false`;
- It needs all elements to be `true` in order the result be `true`;

| `p`     | `q`     | `p and q` |
|---------|---------|-----------|
| `true`  | `true`  | `true`    |
| `true`  | `false` | `false`   |
| `false` | `true`  | `false`   |
| `false` | `folse` | `false`   |

For example:

```c++
bool x = true;
bool y = false;
bool z = x && y; // z is assigned the value false
```

## OR

*Or* operators can be represented by `||`(most common syntax) or `or`(C++20 and up - - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative)). This operator represents the logical `OR` operation. It returns `true` if one operands are `true`, and `false` if all are `false`.
- It needs only if one `true` element to make the result be `true`;
- It needs all elements to be `false` in order the result be `false`; 

| `p`     | `q`     | `p or q` |
|---------|---------|----------|
| `true`  | `true`  | `true`   |
| `true`  | `false` | `true`   |
| `false` | `true`  | `true`   |
| `false` | `folse` | `false`  |

For example:

```c++
bool x = true;
bool y = false;
bool z = x || y; // z is assigned the value true
```

## NOT

*Not* operator can be represented by `!`(most common syntax) or `not`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative)). This operator represents the logical `NOT` operation. It returns `true` if operand after it is `false`, and `true` otherwise._

| `p`     | `not p` |
|---------|---------|
| `true`  | `false` |
| `false` | `true`  |

For example:

```c++
bool x = true;
bool y = !x; // y is assigned the value false
```

# Bitwise operations

In C++, the bitwise operators are used to perform operations on the individual bits of an integer value.

## AND

Bitwise `and` can be represented by `&` or `bitand`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative): This operator performs the bitwise AND operation. It compares each bit of the first operand to the corresponding bit of the second operand, and if both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0. For example:

```c++
int x = 5; // binary representation is 0101
int y = 3; // binary representation is 0011
int z = x & y; // z is assigned the value 1, which is binary 0001
```

## OR

Bitwise `or` can be represented by `|` or `bitor`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative): This operator performs the bitwise OR operation. It compares each bit of the first operand to the corresponding bit of the second operand, and if either bit is 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0. For example:

```c++
int x = 5; // binary representation is 0101
int y = 3; // binary representation is 0011
int z = x | y; // z is assigned the value 7, which is binary 0111
```

## XOR

Bitwise `xor` can be represented by `^` or `bitxor`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative): This operator performs the bitwise XOR (exclusive OR) operation. It compares each bit of the first operand to the corresponding bit of the second operand, and if the bits are different, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

```c++
int x = 5; // binary representation is 0101
int y = 3; // binary representation is 0011
int z = x ^ y; // z is assigned the value 6, which is binary 0110
```

Bitwise xor is a type of binary sum without carry bit.

## NOT

Bitwise `not` can be represented by `~` or `bitnot`(C++20 and up - [alternative operator representation](https://en.cppreference.com/w/cpp/language/operator_alternative): This operator performs the bitwise NOT (negation) operation. It inverts each bit of the operand (changes 1 to 0 and 0 to 1). For example:

```c++
int x = 5; // binary representation is 0101
int y = ~x; // y is assigned the value -6, which is binary 11111010. See complement of two for more details.
```

## SHIFT

In C++, the shift operators are used to shift the bits of a binary number to the left or right. Pay attention to not mix with the same ones used to strings, in that case they are called stream operators. There are two shift operators:

1. `<<`: This operator shifts the bits of the left operand to the left by the number of positions specified by the right operand. For example:

```c++
int x = 2; // binary representation is 10
x = x << 1; // shifts the bits of x one position to the left and assigns the result to x
// x now contains 4, which is binary 100
```

2. `>>`: This operator shifts the bits of the left operand to the right by the number of positions specified by the right operand. For example:

```c++
int x = 4; // binary representation is 100
x = x >> 1; // shifts the bits of x one position to the right and assigns the result to x
// x now contains 2, which is binary 10
```

The shift operators are often used to perform operations more efficiently than can be done with other operators. They can also be used to extract or insert specific bits from or into a value.

# Conditionals

Conditionals are used to branch and execute different blocks of code based on whether a certain condition is true or false. There are several types of conditionals, including:

## if clause

`if` statements: These execute a block of code if a certain condition is `true`. If statements usually uses comparison operators or any result that can be transformed as boolean - any number different than `0` is considered `true`, only `0` is considered `false`. 

Comparison operator is used to compare the value of two operands. The operands can be variables, expressions, or constants. The comparison operator returns a Boolean value of true or false, depending on the result of the comparison. There are several comparison operators available:

- `==`: returns `true` if the operands are equal;
- `!=`: returns `true` if the operands are not equal;
- `>`: returns `true` if the left operand is greater than the right operand;
- `<`: returns `true` if the left operand is less than the right operand;
- `>=`: returns `true` if the left operand is greater than or equal to the right operand;
- `<=`: returns `true` if the left operand is less than or equal to the right operand;

For example:
```c++
if (x > y) {
  // code to execute if x is greater than y
}
```

If it appears without scope `{}`, the condition will applied only to the next statement. For example 
```c++
if (x > y) 
  doSomething(); // only happens if x > y is evaluated as true
otherThing(); // this will always occur.  
```
Inline conditional:
```c++
if (x > y) doSomething(); // only happens if x > y is evaluated as true
```
```c++
if (x > y) {doSomething();} // only happens if x > y is evaluated as true
```

A common source of error is adding a `;` after the condition. In this case, the compiler will understand that it is an empty statement and always execute the next statement. 
```c++
if (x > y); // note the inline empty statement here finished with a `;`
  doSomething(); // this will always happen
```

!!! note 

    It is preferred to always create scopes with `{}`, but there is no need to have them if you have only one statement that will happen for that condition.

## if-else clause

All the explanations from `if` applies here but now we have a fallback case.

`if-else` statements: These execute a block of code if a certain condition is true, and a different block of code if the condition is false. For example:

```c++
if (x > y) {
  // code to execute if x is greater than y
} else {
  // code to execute if x is not greater than y
}
```

All the explanations about scope on the `if` clause described before, can be applied to the `else`.

## Ternary Operator 

The ternary operator is also known as the conditional operator. It is used to evaluate a condition and return one value if the condition is true and another value if the condition is false. The syntax for the ternary operator is:

```c++
condition ? value_if_true : value_if_false
```

For example:

```c++
int a = 5;
int b = 10;
int min = (a < b) ? a : b;  // min will be assigned the value of a, since a is less than b
```

Here, the condition `a < b` is evaluated to be true, so the value of a is returned. If the condition had been `false`, the value of b would have been returned instead.

The ternary operator can be used as a shorthand for an if-else statement. For example, the code above could be written as:
```c++
int a = 5;
int b = 10;
int min;
if (a < b) {
  min = a;
} else {
  min = b;
}
```

## Switch

`switch` statement allows you to execute a block of code based on the value of a variable or expression. The switch statement is often used as an alternative to a series of if statements, as it can make the code more concise and easier to read. Here is the basic syntax for a switch statement in C++:

```c++
switch (expression) {
  case value1:
    // code to be executed if expression == value1
    break;
  case value2:
    // code to be executed if expression == value2
    break;
  // ...
  default:
    // code to be executed if expression is not equal to any of the values
}
```

The expression is evaluated once, and the value is compared to the values in each case statement. If a match is found, the code associated with that case is executed. The break statement is used to exit the switch statement and prevent the code in subsequent cases from being executed. The default case is optional, and is executed if none of the other cases match the value of the expression.

Here is an example of a switch statement that checks the value of a variable x and executes different code depending on the value of x:

```c++
int x = 2;

switch (x) {
  case 1:
    cout << "x is 1" << endl;
    break;
  case 2:
    cout << "x is 2" << endl;
    break;
  case 3:
    cout << "x is 3" << endl;
    break;
  default:
    cout << "x is not 1, 2, or 3" << endl;
}
```

In this example, the output would be "x is 2", as the value of x is 2.

!!! note

    It's important to note that C++ uses strict type checking, so you need to be careful about the types of variables you use in your conditionals. For example, you can't compare a string to an integer using the `==` operator.

### Switch fallthrough

In C++, the `break` statement is used to exit a `switch` statement and prevent the code in subsequent cases from being executed. However, sometimes you may want to allow the code in multiple cases to be executed if certain conditions are met. This is known as a "fallthrough" in C++.

To allow a `switch` statement to fall through to the next case, you can omit the break statement at the end of the case's code block. The code in the next case will then be executed, and the switch statement will continue to execute until a break statement is encountered or the end of the switch is reached.

Here is an example of a switch statement with a fallthrough:

```c++
int x = 2;

switch (x) {
  case 1:
    cout << "x is 1" << endl;
  case 2:
    cout << "x is 2" << endl;
  case 3:
    cout << "x is 3" << endl;
  default:
    cout << "x is not 1, 2, or 3" << endl;
}
```

In this example, the output would be "x is 2" and "x is 3", as the break statement is omitted in the `case 2` block and the code in the `case 3` block is executed as a result.

It is generally considered good practice to include a `break` statement at the end of each case in a `switch` statement to avoid unintended fallthrough. However, there may be cases where a fallthrough is desired behavior. In such cases, it is important to document the intended fallthrough in the code to make it clear to other programmers.

### Issues with switch and enums

A nice usecase for `switch`es is to be used to select between possible choices and `enum`s are one of the best ways of expressing choices. So it seems natural to combine both, right? Well, not so fast. There are some issues with this combination that you might be aware of.

The main issue with this approach relies on the `switch`'s `default` behavior. If you use `deafult` on `swich`es in conjunction with stringly typed `enum`s (`enum class` or `enum struct`), the compiler won't be able to warn you about missing cases. This is because the `default` case will be triggered for any value that is not explicitly handled by the `switch`. This is a problem because it is very easy to forget to add a new case when a new value is added to the `enum` and the compiler won't warn you about it. Example:

```c++ title="ColorEnum.h"
enum class Color { Red, Green };
```

```c++ title="UseCaseX.cpp"
// this code goes inside some function that uses Color c
switch(c){
  case Color::Red:
    // do something
    break;
  default: // covers Color::Green and any other value
    // do something else
    break;
}
```

But you just remembered that now you should cover the `Blue` state. So you add it to the `enum`:

```c++ title="ColorEnum.h"
enum class Color { Red, Green, Blue };
```

But you might forget to add the coverage for the new case to the `switch`, it will fall into the `default` case without warnings.

So the best combination is to use `switch`es with `enum class`es and **do not** use `default` cases. This way, the compiler will warn you about missing cases. So if you add a new `enum` value had this code instead, you will be warned about missing cases.

```c++ title="UseCaseX.cpp"
// this code goes inside some function that uses Color c
switch(c){
  case Color::Red:
    // do something
    break;
  case Color::Green:
    // do something else
    break;
}
// this code will throw a warning if you forget to add a case for the new enum value
```

## Homework

- Do all exercises up to this topic [here](https://www.w3schools.com/cpp/exercise.asp).

- [Coordinates of a Point](https://www.beecrowd.com.br/judge/en/problems/view/1041). In this activity, you will have to code a way to find the quadrant of a given coordinate.

# Outcomes

It is expected for you to be able to solve all questions before this one `1041` on beecrowd. Sort Beecrowd questions from the most solved to the least solved questions [here](https://www.beecrowd.com.br/judge/en/search?q=&sort=Problems.solved&direction=desc) in the link. If you don't, see [Troubleshooting](#troubleshooting). Don`t let your study pile up, this homework is just a small test, it is expected from you to do other questions on Beecrowd or any other tool such as leetcode.

# Troubleshooting
If you have problems here, start a [discussion](https://github.com/InfiniBrains/Awesome-GameDev-Resources/discussions). Nhis is publicly visible and not FERPA compliant. Use discussions in Canvas if you are enrolled in a class with me. Or visit the tutoring service.