# Variables, Data Types, Expressions, Assignment, Formatting

# Variables

Variables are containers to store information and facilitates data manipulation. They are named and typed. [Detailed Reference](https://en.cppreference.com/book/intro/variables)

Container sizes are measured in Bytes. Bytes are the smallest addressable unit in a computer. Each byte is composed by 8 bits. Each bit can be `1` or `0` (`true` or `false`). If one byte have 8 bits and each bit one can hold 2 different values, the combination of all possible cases that a byte can be is `2^8` which is `256`, so one byte can hold up to `256` different states or possibilities. 

## Data Types

There are several types of variables in C++, including:

- Primitive data types: These are the most basic data types in C++ and include integer, floating-point, character, and boolean types.
- Derived data types: These data types are derived from the primitive data types and include arrays, pointers, and references.
- User-defined data types: These data types are defined by the programmer and include structures, classes, and enumerations.

[Detailed Reference](https://en.cppreference.com/w/cpp/language/types)

### Numeric types

There are some basic integer container types with different sizes. It can have some type modifiers to change the default behavior or the type.

The common size of the integer containers are `1`(`char`), `2`(`short int`), `4`(`int`) or `8`(`long long`) bytes. [For a more detailed coverage read this](https://en.cppreference.com/w/cpp/language/types).

!!! note

    But the only guarantee the C++ imposes is: `1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)` and it can result in compiler defined behaviours where a `char` can have 8 bytes and a `long long` can be 1 byte.

!!! note

    If you care about being cross-platform conformant, you have to always specify the sign modifier or use a more descriptive type such as listed [here](https://en.cppreference.com/w/cpp/header/cstdint).

For floating pointing numbers, the container size can be `4`(`float`), `8`(`double`), `10`(deprecated) or `16`(`long double`) bytes.

The sign modifiers can be `signed` and `unsigned` and are applicable only for integer types. 

The default behavior of the types in a x86 cpu are as signed numbers and the first bit of the container is the signal. If the first bit is `0`, it means it is positive.  If the first bit is `1`, it means it is negative. [More details](https://en.wikipedia.org/wiki/Two%27s_complement).

Which means that if the container follow two complement and is the size of 1 byte(8 bits), it have 1 bit for the signal and 7 bit for the content. So this number goes from `-128` up to `127`, this container is typically a `signed char`. The positive size has 1 less quantity in absolute than the negative because 0 is represented in positive side. There are `256` numbers between `-128` and `127` inclusive.

#### Char

A standard `char` type uses 1 byte to store data and follows complement of 1. Going `-127` to `127`, so tipically represents `255` numbers.

A `signed char` follows complement of 2 and it can represent `2^8` or `256` different numbers. By default, in x86 machine char is signed and the represented numbers can go from `-2^7` or `-128` up to `2^7 - 1` or `127`.

An `unsigned char`

Chars can be used to represent letters following the [ascii table](https://www.asciitable.com/) where each value means a specific letter, digit or symbol.

!!! note

    A `char` can have different sizes to represent different character coding for different languages. If you are using hebrew, chinese, or others, you probably will need more than 1 byte to represent the chars. Use `char8_t` (UTF8), `char16_t`(UTF16) or `char36_t`(UTF32), to cover your character encoding for the language you are using.

##### ASCII table

ASCII - American Standard Code for Information Interchange - maps a number to a character. It is used to represent letters, digits and symbols. It is a standard that is used by most of the computers in the world. 

It is a 7 bit table, so it can represent `2^7` or `128` different characters. The first 32 characters are control characters and the rest are printable characters. [Reference](https://en.cppreference.com/w/cpp/language/ascii). There are other tables that extend the ASCII table to 8 bits, or even 16 bits. 

The printable chacacters starts at number 32 and goes up to 126. The first 32 characters are control characters and the rest are printable.

| Dec  | Hex | Binary    | Representation                      | 
|---------------|------|-----------|-------------------------------------|
| 0  | 0x00 | 0000 0000 | `NUL` (`null`)                      |
| 1  | 0x01 | 0000 0001 | `SOH` (`start of heading`)          |
| 2  | 0x02 | 0000 0010 | `STX` (`start of text`)             |
| 3  | 0x03 | 0000 0011 | `ETX` (`end of text`)               |
| 4  | 0x04 | 0000 0100 | `EOT` (`end of transmission`)       |
| 5  | 0x05 | 0000 0101 | `ENQ` (`enquiry`)                   |
| 6  | 0x06 | 0000 0110 | `ACK` (`acknowledge`)               |
| 7  | 0x07 | 0000 0111 | `BEL` (`bell`)                      |
| 8  | 0x08 | 0000 1000 | `BS` (`backspace`)                  |
| 9  | 0x09 | 0000 1001 | `HT` (`horizontal tab`)             |
| 10 | 0x0A | 0000 1010 | `LF` (`NL` line feed, `new line`)   |
| 11 | 0x0B | 0000 1011 | `VT` (`vertical tab`)               |
| 12 | 0x0C | 0000 1100 | `FF` (`NP` form feed, `new page`)   |
| 13 | 0x0D | 0000 1101 | `CR` (`carriage return`)            |
| 14 | 0x0E | 0000 1110 | `SO` (`shift out`)                  |
| 15 | 0x0F | 0000 1111 | `SI` (`shift in`)                   |
| 16 | 0x10 | 0001 0000 | `DLE` (`data link escape`)          |
| 17 | 0x11 | 0001 0001 | `DC1` (`device control 1`)          |
| 18 | 0x12 | 0001 0010 | `DC2` (`device control 2`)          |
| 19 | 0x13 | 0001 0011 | `DC3` (`device control 3`)          |
| 20 | 0x14 | 0001 0100 | `DC4` (`device control 4`)          |
| 21 | 0x15 | 0001 0101 | `NAK` (`negative acknowledge`)      |
| 22 | 0x16 | 0001 0110 | `SYN` (`synchronous idle`)          |
| 23 | 0x17 | 0001 0111 | `ETB` (`End of Transmission Block`) |
| 24 | 0x18 | 0001 1000 | `CAN` (`cancel`)                    |
| 25 | 0x19 | 0001 1001 | `EM` (`end of medium`)              |
| 26 | 0x1A | 0001 1010 | `SUB` (`substitute`)                |
| 27 | 0x1B | 0001 1011 | `ESC` (`escape`)                    |
| 28 | 0x1C | 0001 1100 | `FS` (`file separator`)             |
| 29 | 0x1D | 0001 1101 | `GS` (`group separator`)            |
| 30 | 0x1E | 0001 1110 | `RS` (`record separator`)           |
| 31 | 0x1F | 0001 1111 | `US` (`unit separator`)             |
| 32 | 0x20 | 0010 0000 | `space` (empty space)               |
| 33 | 0x21 | 0010 0001 | `!`                                 |
| 34 | 0x22 | 0010 0010 | `"`                                 |
| 35 | 0x23 | 0010 0011 | `#`                                 |
| 36 | 0x24 | 0010 0100 | `$`                                 |
| 37 | 0x25 | 0010 0101 | `%`                                 |
| 38 | 0x26 | 0010 0110 | `&`                                 |
| 39 | 0x27 | 0010 0111 | `'`                                 |
| 40 | 0x28 | 0010 1000 | `(`                                 |
| 41 | 0x29 | 0010 1001 | `)`                                 |
| 42 | 0x2A | 0010 1010 | `*`                                 |
| 43 | 0x2B | 0010 1011 | `+`                                 |
| 44 | 0x2C | 0010 1100 | `,`                                 |
| 45 | 0x2D | 0010 1101 | `-`                                 |
| 46 | 0x2E | 0010 1110 | `.`                                 |
| 47 | 0x2F | 0010 1111 | `/`                                 |
| 48 | 0x30 | 0011 0000 | `0`                                 |
| 49 | 0x31 | 0011 0001 | `1`                                 |
| 50 | 0x32 | 0011 0010 | `2`                                 |
| 51 | 0x33 | 0011 0011 | `3`                                 |
| 52 | 0x34 | 0011 0100 | `4`                                 |
| 53 | 0x35 | 0011 0101 | `5`                                 |
| 54 | 0x36 | 0011 0110 | `6`                                 |
| 55 | 0x37 | 0011 0111 | `7`                                 |
| 56 | 0x38 | 0011 1000 | `8`                                 |
| 57 | 0x39 | 0011 1001 | `9`                                 |
| 58 | 0x3A | 0011 1010 | `:`                                 |
| 59 | 0x3B | 0011 1011 | `;`                                 |
| 60 | 0x3C | 0011 1100 | `<`                                 |
| 61 | 0x3D | 0011 1101 | `=`                                 |
| 62 | 0x3E | 0011 1110 | `>`                                 |
| 63 | 0x3F | 0011 1111 | `?`                                 |
| 64 | 0x40 | 0100 0000 | `@`                                 |
| 65 | 0x41 | 0100 0001 | `A`                                 |
| 66 | 0x42 | 0100 0010 | `B`                                 |
| 67 | 0x43 | 0100 0011 | `C`                                 |
| 68 | 0x44 | 0100 0100 | `D`                                 |
| 69 | 0x45 | 0100 0101 | `E`                                 |
| 70 | 0x46 | 0100 0110 | `F`                                 |
| 71 | 0x47 | 0100 0111 | `G`                                 |
| 72 | 0x48 | 0100 1000 | `H`                                 |
| 73 | 0x49 | 0100 1001 | `I`                                 |
| 74 | 0x4A | 0100 1010 | `J`                                 |
| 75 | 0x4B | 0100 1011 | `K`                                 |
| 76 | 0x4C | 0100 1100 | `L`                                 |
| 77 | 0x4D | 0100 1101 | `M`                                 |
| 78 | 0x4E | 0100 1110 | `N`                                 |
| 79 | 0x4F | 0100 1111 | `O`                                 |
| 80 | 0x50 | 0101 0000 | `P`                                 |
| 81 | 0x51 | 0101 0001 | `Q`                                 |
| 82 | 0x52 | 0101 0010 | `R`                                 |
| 83 | 0x53 | 0101 0011 | `S`                                 |
| 84 | 0x54 | 0101 0100 | `T`                                 |
| 85 | 0x55 | 0101 0101 | `U`                                 |
| 86 | 0x56 | 0101 0110 | `V`                                 |
| 87 | 0x57 | 0101 0111 | `W`                                 |
| 88 | 0x58 | 0101 1000 | `X`                                 |
| 89 | 0x59 | 0101 1001 | `Y`                                 |
| 90 | 0x5A | 0101 1010 | `Z`                                 |
| 91 | 0x5B | 0101 1011 | `[`                                 |
| 92 | 0x5C | 0101 1100 | `\`                                 |
| 93 | 0x5D | 0101 1101 | `]`                                 |
| 94 | 0x5E | 0101 1110 | `^`                                 |
| 95 | 0x5F | 0101 1111 | `_`                                 |
| 96 | 0x60 | 0110 0000 | ``` ` ```                           |
| 97 | 0x61 | 0110 0001 | `a`                                 |
| 98 | 0x62 | 0110 0010 | `b`                                 |
| 99 | 0x63 | 0110 0011 | `c`                                 |
| 100 | 0x64 | 0110 0100 | `d`                                 |
| 101 | 0x65 | 0110 0101 | `e`                                 |
| 102 | 0x66 | 0110 0110 | `f`                                 |
| 103 | 0x67 | 0110 0111 | `g`                                 |
| 104 | 0x68 | 0110 1000 | `h`                                 |
| 105 | 0x69 | 0110 1001 | `i`                                 |
| 106 | 0x6A | 0110 1010 | `j`                                 |
| 107 | 0x6B | 0110 1011 | `k`                                 |
| 108 | 0x6C | 0110 1100 | `l`                                 |
| 109 | 0x6D | 0110 1101 | `m`                                 |
| 110 | 0x6E | 0110 1110 | `n`                                 |
| 111 | 0x6F | 0110 1111 | `o`                                 |
| 112 | 0x70 | 0111 0000 | `p`                                 |
| 113 | 0x71 | 0111 0001 | `q`                                 |
| 114 | 0x72 | 0111 0010 | `r`                                 |
| 115 | 0x73 | 0111 0011 | `s`                                 |
| 116 | 0x74 | 0111 0100 | `t`                                 |
| 117 | 0x75 | 0111 0101 | `u`                                 |
| 118 | 0x76 | 0111 0110 | `v`                                 |
| 119 | 0x77 | 0111 0111 | `w`                                 |
| 120 | 0x78 | 0111 1000 | `x`                                 |
| 121 | 0x79 | 0111 1001 | `y`                                 |
| 122 | 0x7A | 0111 1010 | `z`                                 |
| 123 | 0x7B | 0111 1011 | `{`                                 |
| 124 | 0x7C | 0111 1100 | `|`                                 |
| 125 | 0x7D | 0111 1101 | `}`                                 |
| 126 | 0x7E | 0111 1110 | `~`                                 |
| 127 | 0x7F | 0111 1111 | `DEL` (`delete`)                    |

![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/ASCII-Table-wide.svg/875px-ASCII-Table-wide.svg.png)

As you can imagine, this table is not enough to represent all the characters in the world(latin, chinese, japanese, etc). So there are other tables that extend the ASCII table to 8 bits, or even 16 bits.

#### Integer

!!! note

    Most of the information that I am covering here might be not precise, but the overall idea is correct. If you want a deep dive, [read this](https://en.cppreference.com/w/cpp/language/types).

A standard `int` type uses 4 bytes to store data. It is signed by default.

It can represent `2^32` or `4294967296` different numbers. As a signed type, it can represent numbers from `-2^31` or  `-2147483648` up to `2^31 - 1` or `2147483647`.

The type `int` can accept sign modifiers as `signed` or `unsigned` to change the behavior of the first bit to act as a sign or not.

The type `int` can accept size modifiers as `short` (2 bytes) or `long long` (8 bytes) to change the size and representation capacity of the container. Type declaration `short` and `short int` result in the same container size of 2 bytes. In the same way a `long long` or `long long int` reserves the same size of 8 bytes for the container.

The type `long` or `long int` usually gives the same size of `int` as 4 bytes. Historical fact or myth: This abnormality, comes from the evolution of the definition of `int`: in the past, 2 bytes were enough for the majority of the scenarios in the 16 bits processors, but it frequently reached the limits of the container and it overflowed. So they changed the standard definition of a integer from being 2 bytes to 4 bytes, and created the short modifier. In this scenario the long int lost the reason to exist.

Here goes a list of valid integer types and its probable size(it depends on the implementation, cpu architecture and operation system):
- Size of 2 bytes: `short int`, `short`, `signed short int`, `signed short`, `unsigned short int`, `unsigned short`, 
- Size of 4 bytes: `signed`, `unsigned`, `int`, `signed int`, `unsigned int`, `long int`, `long`, `signed long int`, `signed long`, `unsigned long int`, `unsigned long`,
- Size of 8 bytes: `long long int`, `long long`, `signed long long int`, `signed long long `, `unsigned long long int`, `unsigned long long`. 

OPINION: I highly recommend the usage of [these types instead](https://en.cppreference.com/w/cpp/header/cstdint), to ensure determinism and consistency between compilers, operating systems and cpu architectures.

#### Float pointing

There are 3 basic types of floating point containers: `float`(4 bytes) and `double`(8 bytes) and `long double`(16 bytes) to represent fractional numeric types.

The [standard IEEE754](https://en.wikipedia.org/wiki/IEEE_754) specifies how a floating point number is stored in the form of bits inside the container. The container holds 3 basic information to simulate the behavior of a fractional type inside a binary type: signal, exponent and fraction.

!!! note

    This standard was very open to implementation definition in the past, and this is one of the root causes of non-determinism physics simulation. This is the main problem you cannot guarantee the same operation with the same pair of numbers will consistently give the same result across different types of processors and compilers, thus making the physics of a multiplayer game consistency hardly achievable. Many deterministic physics engines tend to not use this standard at all, and implement those behaviors via software on top of integers instead. There are 2 approaches to solve the floating-point determinism: [softfloat](https://github.com/ucb-bar/berkeley-softfloat-3) that implement all the IEEE754 specifications via software, or implement some kind of [fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic) on top of integers.

#### Booleans

`bool` is a special type that has the container size of 1 byte but the compiler can optimize and pack up to 8 `bool`s in one byte if they are declared in sequence.

#### Enums

An enumeration is a type that consists of a set of named integral constants. It can be defined using the `enum` keyword:

```c++
enum Color {
  Red,
  Green,
  Blue
};
```

This defines a new type called `Color`, which has three possible values: `Red`, `Green`, and `Blue`. By default, the values of these constants are `0`, `1`, and `2`, respectively. However, you can specify your own values:

```c++
enum Color {
  Red = 5,
  Green,  // 6
  Blue    // 7
};
```

You can then use the enumeration type just like any other type:

```c++
Color favoriteColor = Red;
```

Enumerations can also have their underlying type explicitly specified:

```c++
enum class Color : char {
  Red, 
  Green,
  Blue
};
```

Here, the underlying type of the enumeration is `char`, so the constants `Red`, `Green`, and `Blue` will be stored as characters(1 byte size). The `enum class` syntax is known as a "scoped" enumeration, and it is recommended over the traditional `enum` syntax because it helps prevent naming conflicts. [See the CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-enum) to understand better why you should prefer using this.

```c++
// You can make the value of the constants
// explicit to make your debugging easier:
enum class Color : char {
  Red = 'r', //  
  Green = 'g',
  Blue = 'b'
};
```

### Special derived type: string

`string` is a derived type and in order to use it, string should be included in the beginning of the file or in the header. `char` are the basic unit of a `string` and is used to store words as a sequence of chars.

In C++, a string is a sequence of characters that is stored in an object of the `std::string` class. The `std::string` class is part of the C++ Standard Library and provides a variety of functions and operators for manipulating strings.

### `void type` 

When `void` type specifier is used in functions, it indicates that a function does not return a value.

It can also be used as a placeholder for a pointer to a memory location to indicate that the pointer is "universal" and can point to data of any type, but this can be arguably a bad pattern, and should be used exceptionally when interchanging types with c-style API.

We are going to cover this again when covering [pointers and functions](../06-functions/README.md).

## Variable Naming

Variable names are called identifiers. In C++, you can use any combination of letters, digits, and underscores to name a variable, it should follow some rules:

- Variables can have numbers, en any position, except the first character, so the name does not begin with a digit. Ex. `point2` and `vector2d` are allowed, but `9life` isn't;
- Variable names are case-sensitive, so "myVar" and "myvar" are considered to be different variables;
- Can have `_` in any position of the identifier. Ex. `_myname` and `user_name` are allowed;
- It is not a [reserved keyword](https://en.cppreference.com/w/cpp/keyword);

Keep in mind that it is a good practice to choose descriptive and meaningful names for your variables, as this can make your code easier to read and understand. Avoid using abbreviations or acronyms that may not be familiar to others who may read your code.

It is also important to note that C++ has some naming conventions that are commonly followed by programmers. For example, it is common to use camelCase or snake_case to separate words in a variable name, and to use all lowercase letters for variables that are local to a function and all uppercase letters for constants.


## Variable declaration

Variable declaration in C++ follows this pattern.
```c++
TYPENAME VARIABLENAME;
```
`TYPENAME` can be the name of any predefined type. See [Variable Types](#variable-types) for the types.
`VARIABLENAME` can be anything as long it follow the naming rules. See [Variable Naming](#variable-naming) for the naming rules.

!!! note

    A given variable name can only be declared once in the same context / scope. If you try to redeclare the same variable, the compiler will accuse an error.

!!! note

    You can redeclare the same variable name in different scopes. If one scope is parent of the other, the current will be used and will shadow the content of the one from outer scope. We are going to cover this more when we are covering multi-file projects and functions.

Examples:

```c++
int a;       // integer variable
float pi;    // floating-point variable
char c;      // character variable
bool d;      // boolean variable
string name; // string variable 
```

!!! note

    We are going to cover later in this course other complex types in other modules such as arrays, pointers and references.

# Variable assignment

`=` operator means that whatever the container have will be overwritten by the result of the right side statement. You should read it not as `equal` but as `receives` to avoid misunderstanding. [Reference](https://en.cppreference.com/w/cpp/language/operator_assignment)

```c++
int a = 10;         // integer variable
float pi = 3.14;    // floating-point variable
char c = 'A';       // character variable
bool d = true;      // boolean variable
string name = "John Doe"; // string variable 
```

Every variable, by default, is not initialized. It means that you have to set the content of it after declaring. If the variable is read before the assignment, its content is garbage, it will read whatever is set in the memory stack for the given container location. So the best approach is to always set a value when a variable is declared or be assured that every variable is never read before an assigment.

A `char` variable can be assigned by integer numbers or any characters between single quotes.
```c++
char c;
c = 'A'; // the content is 65 and the representation is A. see ascii table.
c = 98; // the content is 98 and the representation is b. see ascii table.
```

A `bool` is by default either `true` or `false`, but it can be assigned by numeric value following this rule:
- if the value is `0`, then the value stored by the variable is `false` (`0`);
- if the value is anything different than `0`, the value stored is `true` (`1`);

To convert a `string` to a `int`, you have to use a function [stoi](https://en.cppreference.com/w/cpp/string/basic_string/stol)(for `int`), [stol](https://en.cppreference.com/w/cpp/string/basic_string/stol)(for `long`) or [stoll](https://en.cppreference.com/w/cpp/string/basic_string/stol)(for `long long`) because both types are not compatibles.

To convert a `string` to a `float`, you have to use a function [stof](https://en.cppreference.com/w/cpp/string/basic_string/stof)(for `float`), [stod](https://en.cppreference.com/w/cpp/string/basic_string/stof)(for `double`), or [stold](https://en.cppreference.com/w/cpp/string/basic_string/stof)(for `long double`) because both types are not compatibles.

# Literals
Literals are values that are expressed freely in the code. Every numeric type can be appended with suffixes to specify explicitly the type to avoid undefined behaviors or compiler defined behaviors such as implicit cast or container size. 

## Integer literals

There are 4 types of integer literals. 
- decimal-literal: never starts with digit `0` and followed by any decimal digit;
- octal-literal: starts with `0` digit and followed by any octal digit;
- hex-literal: starts with `0x` or `0X` and followed by any hexadecimal digit;
- binary-literal: starts with `0b` or `0B` and followed by any binary digit;

```c++
// all of these variables holds the same value, 42, but using different bases.
// the right side of the = are literals
int deci = 42; 
int octa = 052; 
int hexa = 0x2a; 
int bina = 0b101010;
```

Suffixes:

- `no suffix` provided: it will use the first smallest signed integer container that can hold the data starting from `int`;
- `u` or `U`: it will use the first smallest unsigned integer container that can hold the data starting from `unsigned int`;
- `l` or `L`: it will use the first smallest signed integer container that can hold the data starting from `long`;
- `lu` or `LU`: it will use the first smallest unsigned integer container that can hold the data starting from `unsigned long`;
- `ll` or `LL`: it will use the long long signed integer container `long long`;
- `llu` or `LLU`: it will use the long long unsigned integer container `unsigned long long`;

```c++
unsigned long long l1 = 15731685574866854135ull;
```

[Reference](https://en.cppreference.com/w/cpp/language/integer_literal)

## Float point literals

There are 3 suffixes in floating point decimals.

- `no suffix` means the container is a double;
- `f` suffix means it is a float container;
- `l` suffix means it is a long double container;

A floating point literal can be defined by 3 ways:

- digit-sequence decimal-exponent suffix(optional). 
    - `1e2` means its a `double` with the value of `1*10^2` or `100`;
    - `1e-2f` means its a `float` with the value of `1*10^-2` or `0.01`;
- digit-sequence . decimal-exponent(optional) suffix(optional).  
    - `2.` means it is a `double` with value of `2`; 
    - `2.f` means it is a `float` with value of `2`;
    - `2.1l` means it is a `long double` with value of `2.1`;
- digit-sequence(optional) . digit-sequence decimal-exponent(optional) suffix(optional)
    - `3.1415f` means it is a `float` with value of `3.1415`;
    - `.1` means it is a `double` with value of `0.1`;
    - `0.1e1L` means it is a `long double` with value of `1`;

[Reference](https://en.cppreference.com/w/cpp/language/floating_literal)

# Arithmetic Operations

In C++, you can perform common arithmetic operations is statements using the following operators [Reference](https://en.cppreference.com/w/cpp/language/operator_arithmetic):

- Addition: `+`
- Subtraction: `-`
- Multiplication: `*`
- Division: `/`
- Modulus (remainder): `%`

There are two special cases called unary increment / decrement operators that may occur in before(prefixed) or after(postfixed) the variable name [reference](https://en.cppreference.com/w/cpp/language/operator_incdec). If prefixed it is executed first and then return the result, if postfixed, it returns the current value and then execute the operation:

- Increment: `++`; 
- Decrement: `--`;

There are shorthand assignment operators [reference](https://en.cppreference.com/w/cpp/language/operator_assignment) that reassign the value of the variable after executing the arithmetic operation with the right side of the operator with the old value of the variable:

- Addition: `+=`
- Subtraction: `-=`
- Multiplication: `*=`
- Division: `/=`
- Modulus (remainder): `%=`

Here is an example of how to use these operators in a C++ program:

```c++
#include <iostream>

int main() {
  int a = 5;
  int b = 2;

  std::cout << a + b << std::endl; // Outputs 7
  std::cout << a - b << std::endl; // Outputs 3
  std::cout << a * b << std::endl; // Outputs 10
  std::cout << a / b << std::endl; // Outputs 2
  std::cout << a % b << std::endl; // Outputs 1
  a++;
  std::cout << a << std::endl; // Outputs 6
  a--;
  std::cout << a << std::endl; // Outputs 5
  
  std::cout << a++ << std::endl; // Outputs 5 because it first returns the current value and then increments.
  std::cout << a << std::endl; // Outputs 6
  
  std::cout << --a << std::endl; // Outputs 5 because it first decrements the value and then return it already changed;
  std::cout << a << std::endl; // Outputs 5
  
  b *= 2; // it is a short version of b = b * 2; 
  std::cout << b << std::endl; // Outputs 4
  
  b /= 2; // it is a short version of b = b / 2; 
  std::cout << b << std::endl; // Outputs 2

  return 0;
}
```

Note that the division operator (`/`) performs integer division if both operands are integers. If either operand is a floating-point type, the division will be performed as floating-point division. So `5/2` is `2` because both are integers, se we use integer division, but `5/2.` is `2.5` because the second one is a `double` literal.

Also, the modulus operator (`%`) returns the remainder of an integer division. For example, `7 % 3` is equal to `1`, because `3` goes into `7` two times with a remainder of `1`.

## Implicit cast

Implicit casting, also known as type coercion, is the process of converting a value of one data type to another data type without the need for an explicit cast operator. In C++, this can occur when an expression involves operands of different data types and the compiler automatically converts one of the operands to the data type of the other in order to perform the operation.

For example:

```c++
int a = 1;
double b = 1.5;

int c = a + b; // c is automatically converted to a double before the addition
```
In this example, the value of `b` is a double, while the value of `a` is an `int`. When the addition operator is used, the compiler will automatically convert a to a `double` before performing the addition. The result of the expression is a `double`, so `c` is also automatically converted to a `double` before being assigned the result of the expression.

Implicit casting can also occur when assigning a value to a variable of a different data type. For example:

```c++
int a = 2;
double b = a; // a is automatically converted to a double before the assignment
```

In this case, the value of `a` is an int, but it is being assigned to a double variable. The compiler will automatically convert the value of `a` to a `double` before making the assignment.

It's important to be aware of implicit casting, because it can sometimes lead to unexpected results or loss of precision if not handled properly. In some cases, it may be necessary to use an explicit cast operator to explicitly convert a value to a specific data type.

## Explicit cast

In C++, you can use an explicit cast operator to explicitly convert a value of one data type to another. The general syntax for an explicit cast are:

```c++
// ref: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Programming_Languages/C%2B%2B/Code/Statements/Variables/Type_Casting
(TYPENAME) value; // regular c-style. do not use this extensively
static_cast<TYPENAME>(value); // c++ style conversion, arguably it is the preferred style. use this if you know what you are doing.
TYPENAME(value); // functional initialization, slower but safer. might not work for every case. Use this if you are unsure or want to be safe.
TYPENAME{value}; // initialization style, faster, convenient, concise and arguably safer because it triggers warnings. use this for the general case. 
```

For example:
```c++
int a = 7;
double b = (double) a; // a is explicitly converted to a double
```

In this example, the value of `a` is an `int`, but it is being explicitly converted to a `double` using the explicit cast operator. The result of the cast is then assigned to the `double` variable `b`.

Explicit casts can be useful in situations where you want to ensure that a value is converted to a specific data type, regardless of the data types of the operands in an expression. However, it's important to be aware that explicit casts can also lead to unexpected results or loss of precision if not used carefully. This behaviour is called *narrowing*.

C-style:
```c
int a = 20001;
char b = (char) a; // b is assigned the ASCII value for the character '!'
```

In this case, the value of `a` is an `int`, but it is being explicitly converted to a `char` using the explicit cast operator. However, the range of values that can be represented by a `char` is much smaller than the range of values that can be represented by an `int`, so the value of `a` is outside the range that can be represented by a `char`. As a result, `b` is assigned the ASCII value for the character `1`, which is not the same as the original value of `a`. The value `!` is `33` in ASCII table, and `33` is the result of the `20001 % 256` where `256` is the number of elements the `char` can represent. In this case, what happened was a bug that is hard to track called `int overflow`.

# `auto` keyword

[`auto` keyword](https://en.cppreference.com/w/cpp/language/auto) is mostly a syntax sugar to automatically infer the data type. It is used to avoid writing the full declaration of complex types when it is easily inferred. `auto` is not a dynamic type, once it is inferred, it cannot be changed later like in other dynamic typed languages such as javascript.

```c++
auto i = 0; // automatically inferred as an integer type;
auto f = 0.0f; // automatically inferred as a float type;

i = "word"; // this won't work, because it was already inferred as an integer and integer container cannot hold string
```

# Formatting

There are many functions to help you format the output in the way it is expected, here goes a selection of the most useful ones I can think. Yon can find more functions and manipulators [here](https://en.cppreference.com/w/cpp/header/iomanip) and [here](https://en.cppreference.com/w/cpp/header/ios).

To set a fixed precision for floating point numbers in C++, you can use the `std::setprecision` manipulator from the `iomanip` header, along with the `std::fixed` manipulator.

Here's an example of how to use these manipulators to output a floating point number with a fixed precision of 3 decimal places:
```c++
#include <iostream>
#include <iomanip>

int main() {
  double num = 3.14159265;

  std::cout << std::fixed << std::setprecision(3) << num << std::endl;
  // Output: 3.142
  return 0;
}
```

You can also use the `std::setw` manipulator to set the minimum field width for the output, which can be useful for aligning the decimal points in a table of numbers.

For example:
```c++
#include <iostream>
#include <iomanip>

int main() {
  double num1 = 3.14159265;
  double num2 = 123.456789;

  std::cout << std::fixed << std::setprecision(3) << std::setw(8) << num1 << std::endl;
  std::cout << std::fixed << std::setprecision(3) << std::setw(8) << num2 << std::endl;
  // Output:
  //   3.142
  // 123.457
  return 0;
}
```

Note that these manipulators only affect the output stream, and do not modify the values of the floating point variables themselves. If you want to store the numbers with a fixed precision, you will need to use a different method such as rounding or truncating the numbers.

To align text to the right or left in C++, you can use the `setw` manipulator in the `iomanip` header and the `right` or `left` flag. [More details here](https://en.cppreference.com/w/cpp/io/manip/left) 

Here is an example:

```c++
#include <iostream>
#include <iomanip>

int main() {
  std::cout << std::right << std::setw(10) << "Apple" << std::endl;
  std::cout << std::left << std::setw(10) << "Banana" << std::endl;
  return 0;
}
```

Both will print inside a virtual column with the size of 10 chars. This will output the following:
```shell
    Apple
Banana   
```

# Optional Exercises

Do all exercises up to this topic [here](https://www.w3schools.com/cpp/exercise.asp).

In order to get into coding, the easiest way to learn is by solving coding challenges. It is like learning any new language, you have to be exposed and involved. Do not do only the homeworks, otherwise you are going to fail. Another metaphor is: the homework is the like a competition that you have to run to prove that you are trained, but in order to train, you have to do small runs and do small steps first, so you have to train yourself ot least 2x per week.

The best way to train yourself in coding and solving problems in my opinion is this:

1. Sort Beecrowd questions from the most solved to the least solved questions [here](https://www.beecrowd.com.br/judge/en/search?q=&sort=Problems.solved&direction=desc) is the link of the list already filtered.
2. Start solving the questions from the top to the bottom. Chose one from de the beginning, it would be one of the easiest;
3. If you are feeling comfortable and being able to solve more than 3 per hour, you are allowed to skip some of the questions. It is just like in a gym, when you get used with the load, you increase it. Otherwise continue training slowly.

# Homework
[banknotes and coins](https://www.beecrowd.com.br/judge/en/problems/view/1021) - Here you will use formatting, modulus, casting, arithmetic operations, compound assignment. You don't need to use if-else.

Hint. Follow this only if dont find your way of solving it. You can read the number as a double, multiply by 100 and then do a sequence of modulus and division operations.
```c++
double input; // declare the container to store the input
cin >> input; // read the input

long long cents = static_cast<long long>(input * 100); // number of cents. Note: if you just use float, you will face issues. 

long long notes100 = cents/10000; // get the number of notes of 100 dollar (100 units of 100 cents) 
cents %= 10000; // remove the amount of 100 dollars
```

Another good way of solving it avoiding casting is reading the number as string and removing the point. [Never use `float` for money](https://husobee.github.io/money/float/2016/09/23/never-use-floats-for-currency.html)

```c++
string input; // declare the container to store the input
cin >> input; // read the input

// given every input will have the dot, we should remove it. remove the dot `.`
input = input.erase(str.find('.'), 1);

// not it is safe to use int, because no bit is lost in floating casting and nobody have more than MAX_INT cents.  
int cents = stoll(input); // number of cents. 

long long notes100 = cents/10000; // get the number of notes of 100 dollar (100 units of 100 cents) 
cents %= 10000; // update the remaining cents by removing the amount of 100 dollars in cents units
```

# Troubleshooting
If you have problems here, start a [discussion](https://github.com/InfiniBrains/Awesome-GameDev-Resources/discussions). Nhis is publicly visible and not FERPA compliant. Use discussions in Canvas if you are enrolled in a class with me. Or visit the tutoring service.
