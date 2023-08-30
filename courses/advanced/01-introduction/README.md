# Advanced Programming with C++

# Recapitulation

Before we start, let's recapitulate what we have learned in the previous course. Use the links below to refresh your memory. Or go straigth to the [Introduction to Programming Course](../../intro/README.md).

- [Variables](../../intro/03-datatypes/README.md)
- [Decision making](../../intro/04-conditionals/README.md)
- [Loops](../../intro/05-loops/README.md);
- [Functions](../../intro/06-functions/README.md);
- [Strings](../../intro/03-datatypes/README.md);
- [Arrays](../../intro/08-arrays/README.md);
- [Multidimensional arrays](../../intro/08-arrays/README.md);

# Structs

Structs in C++ are a way to represent a collection of data packed sequentially into a single data structure. 

```cpp
struct Enemy
{
    double health; 
    float x, y, z;
    int score;
};
```

The code above defines a type named as `Enemy`. This type has members(fields) named `health`, `score` with different types, and `x`, `y` and `z` with the same type. 

```cpp
struct Enemy
{
    double health; // 8 bytes
    float x, y, z; // 4 bytes each. 12 bytes total
    int score; // 4 bytes
};
```

The **memory usage of a struct** is defined *roughly* by the **sum of the memory usage of its members**. Assuming the default sizing of common data types in C++, in the example above, the struct will use 8 bytes for the `double`, 3 times 4 bytes for the `float`s and 4 bytes for the `int`. The total memory usage for the struct will be 20 bytes.

# Data Alignment

The memory usage of a struct is not always exactly the sum of the memory usage of its members. The compiler may add padding bytes between the members of a struct to align the data in memory. This is done to improve the performance of the program. If you are programming in a multi-platform, cross-platform or even using different compilers, the size of the struct may vary even if it is the same.

```cpp
struct InneficientMemoryLayoutExample
{
    char a;
    int b;
    char c;
    char d;
    char e;
};
```

The struct above stores a total of 8 bytes of data, but the compiler allocates more. It will add 3 padding bytes between the `int` and the last `char` to align the data with biggest field in the struct. In this case, the total memory usage of the struct will be 12 bytes instead of the expected 8.

```cpp
struct InneficientMemoryLayoutExample
{
    char a; // 1 byte
    // compiler will add 3 padding bytes here
    int b; // 4 bytes
    char c; // 1 byte
    char d; // 1 bytes
    char e; // 1 byte
    // compiler will add 1 padding byte here
}; // total of 12 bytes allocated for this layout
```

You might think C++ compilers are smart and reorder the fields for us, but in order to maintain compatibility to C, the standard forbids it. So if you want to pack more data you will have to reorder the layout manually to something like this:

```cpp
struct EfficientMemoryLayoutExample
{
    int b; // 4 bytes
    char a; // 1 byte
    char c; // 1 byte
    char d; // 1 bytes
    char e; // 1 byte
}; // total of 8 bytes allocated for this layout
```

Alternatively you can use the `#pragma pack` directive to tell the compiler to pack the data in memory without padding bytes. But be aware that it will force the compiler to do more memory operations to get the data, thus it will slow your software. Besides that, `pragma pack` may not work in all compilers. 

```cpp
#pragma pack(push, 1) // push current alignment to stack and set alignment to 1 byte boundary
struct EfficientMemoryLayoutExample
{
    char a; // 1 byte
    int b; // 4 bytes
    char c; // 1 byte
    char d; // 1 bytes
    char e; // 1 byte
};
#pragma pack(pop)
```

## Bitfields

If you really want to specify the layout location for each field and want to be sure that in will work on every compiler/platform, you will have to specify the number of bits each field will be able to use. This is called **bitfields**. But if you follow this path, you will have to be aware of the endianness of the platform you are working on.

```cpp
struct BitfieldExample
{
    char a : 8; // 8 bits = 1 byte
    int b : 32; // 32 bits = 4 bytes
    char c : 8; // 8 bits = 1 byte
    char d : 8; // 8 bits = 1 byte
    char e : 8; // 8 bits = 1 byte
}; // total of 8 bytes allocated for this layout
```

Another nice application of bitfields is when you do not want to use the full range of a data type. For example, if you want to store a number between 0 and 7, as in a chess game or other board games, you can use a `char` and waste 5 bits or you can use a bitfield and use only 3 bits.

```cpp
struct BitfieldExample
{
    char row : 3; // 3 bits
    char column : 3; // 3 bits
    unsigned int state : 2; // 2 bit. will store 0, 1, 2 or 3
}; // total of 1 byte allocated for this layout
```
