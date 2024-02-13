# Introduction to Object-Oriented Programming

C++ in a language that keeps evolving and adding new features. The language is now a multi-paradigm language, which means that it supports different programming styles, and we are going to cover the Object-Oriented Programming (OOP) paradigm in this course.

![img.png](img.png)

## What is OOP?

Object-Oriented Programming is a paradigm that encapsulate data and their interactions into a single entity called object. The object is an instance of a class, which is a blueprint for the object. The class defines the data and the operations that can be performed on the data.

## Class declaration

Here goes a simple declaration of a class Greeter:

```cpp title="Greeter.h"
#include <string>
class Greeter {
    std::string name; // this is a private attribute
public:
    Greeter(std::string username) {
        name = username;
    }
    void Greet(){
        std::cout << "Hello, " << name << "!" << std::endl;
    }
};
```

```cpp title="main.cpp"
#include "Greeter.h"
int main() {
    Greeter greeter("Stranger");
    greeter.Greet();
}
```

If you run this code, the output will be:

```bash
Hello, Stranger!
```

Here goes a rework of the previous example using more robust concepts and multiple files:

```cpp title="Greeter.h"
#include <string>
class Greeter {
    // class members are private by default
    std::string name;
public:
    // public constructor
    // explicit to avoid implicit conversions
    // const to avoid modification
    // ref to avoid copying
    explicit Greeter(const std::string& name);
    ~Greeter(); // public destructor
    void Greet(); // public method
};
```

```cpp title="Greeter.cpp"
#include "Greeter.h"
#include <iostream>
// :: is the scope resolution operator
Greeter::Greeter(const std::string& name): name(name) {
    std::cout << "I exist and I received " << name << std::endl;
}
Greeter::~Greeter() {
    std::cout << "Goodbye, " << name << "!" << std::endl;
}
void Greeter::Greet() {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

```cpp title="main.cpp"
#include "Greeter.h"
int main() {
    Greeter greeter("Stranger");
    greeter.Greet();
    // cannot use greeter.name because it is private
}
```

## Advantages of OOP

![img_2.png](img_2.png)

### Modularity

Classes can be used it in different parts of your code. You can even create libraries and share it with other people.

### Encapsulation

Classes can hide their implementation details from the developer. The developer only needs the header file to use the class which acts as an interface.

### Inheritance

Classes can inherit from other classes. This allows you to reuse code and extend the functionality of existing classes expanding the original behavior. 

We will cover details about inheritance in another moment.

### Polymorphism

By its roots, the word polymorphism means "many forms". It can be applied to classes in many different aspects:

- **Function overload**: Class can have multiple definitions of the same member function, and the compiler will choose the correct one based on the type of the object.
- **Casting**: Classes can be casted to other classes. This allows you to treat an object of a derived class as an object of its base class, or more complex behaviors;

We will cover details about polymorphism in another moment.

## Class internals

![img_1.png](img_1.png)

### Constructors

Constructors are special methods, they are called when an object is created, and don't return anything. They are used to initialize the object. If you don't define a constructor, the compiler will generate a default constructor for you.

```c++
class Greeter {
    std::string name;
public:
    Greeter(const std::string& name) {
        this->name = name;
    }
};
```

#### Default constructor

A default constructor should be one of the following:
- A constructor that can be called with no arguments; 
- A constructor that can be called with default arguments;

```c++
class Greeter {
    std::string name;
public:
    // Default constructor
    Greeter() {
        this->name = "Stranger";
    }
};
```

or

```c++
class Greeter {
    std::string name;
public:
    Greeter(const std::string& name = "Stranger") {
        this->name = name;
    }
};
```

If no constructor is defined, the compiler will generate a default constructor for you.

#### Copy constructor

A copy constructor is a constructor that takes a reference to an object of the same type as the class. It is used to initialize an object with another object of the same type.

```c++
class Greeter {
    std::string name;
public:
    Greeter(const Greeter& other) {
        this->name = other.name;
    }
};
```

#### Move constructor

A move constructor is a constructor that takes a reference to an object of the same type as the class. It is used to initialize an object with another object of the same type. The difference between a copy constructor and a move constructor is that the move constructor takes ownership of the data from the other object, while the copy constructor copies the data from the other object.

```c++
class Greeter {
    std::string name;
public:
    Greeter(Greeter&& other) {
        this->name = std::move(other.name);
    }
};
```

#### Explicit constructor

A constructor that can be called with only one argument is called an explicit constructor. This means that the compiler will not allow implicit conversions to happen.

Explicit constructors are useful to avoid unexpected behavior when calling the constructor.

```c++
class Greeter {
    std::string name;
public:
    explicit Greeter(const std::string& name) {
        this->name = name;
    }
};
```

### Destructors

Destructors are special methods, they are called when an object is destroyed.

Following the **single responsibility principle**, the destructor should be responsible for cleaning up the dynamically allocated data the object is holding.

If no destructor is defined, the compiler will generate a default destructor for you that might not be enough to clean up the data.

```c++
class IntContainer {
    int* data;
    // other members / methods
public:
    // other members / methods
    ~IntContainer() {
        // deallocate data
        delete[] data;
    }
};
```

### Private and Public

By default, all members of a class are private. This means that they can only be accessed by the class itself. If you want to expose a member to the outside world, you have to declare it as public.

```c++ 
class Greeter {
    std::string name; // private by default
public:
    Greeter(const std::string& name) {
        this->name = name;
    }
};
```
#### Dealing with private members

If your data is private, but you need to provide access or modify it, you can create public methods to do that.

- **Accessors**: are the type of public methods that provides **readability** of the specific content;
- **Mutators**: are the type of public methods that provides **writability** of the specific content;

```c++ 
class User {
    std::string name; // private by default
public:
    explicit User(const std::string& name) {
        this->name = name;
    }
    // Accessor that returns a copy
    // const at the end means that this function does not modify the object
    std::string GetName() const {
        return name;
    }

    // Accessor that returns a const reference
    // returning ref does not use extra memory
    // returning const the caller cannot modify the object
    const std::string& GetNameRef() const {
        return name;
    }

    // Mutator
    void SetName(const std::string& name) {
        this->name = name;
    }
};
```

## Operator "." and "->"

When you have an object, you can access its members using the dot operator `.`. If you have a pointer to an object, you can access its members using the arrow operator `->`.

```c++

int main(){
    Greeter greeter("Stranger");
    greeter.Greet(); // dot operator
    Greeter* greeterPtr = &greeter;
    greeterPtr->Greet(); // arrow operator
}
```

## Scope resolution operator "::"

It can be used to access members of a class that are not part of an object. It can also be used to access members of a namespace.

```c++
namespace MyNamespace {
    int myInt = 0;
    class MyClass {
    public:
        // static vars are allocated in the data segment instead of the stack
        static inline const int myInt = 1;
        int myOtherInt = 2;
    };
    void MyFunction() {
        int myInt = 3;
        std::cout << myInt << std::endl; // 3
        std::cout << MyNamespace::myInt << std::endl; // 0
        std::cout << MyNamespace::MyClass::myInt << std::endl; // 1
        std::cout << MyClass::myInt << std::endl; // 1
        std::cout << MyNamespace::MyClass().myOtherInt << std::endl; // 2
    }
}

```

## Differences between class and struct

In C++, the only difference between a class and a struct is the default access level. In a class, the default access level is private, while in a struct, the default access level is public.

```c++
class MyClass {
    int myInt; // private by default
public:
    MyClass(int myInt) {
        this->myInt = myInt;
    }
    int GetMyInt() const {
        return myInt;
    }
};

struct MyStruct {
    // to achieve the same behavior as the class above
private:
    int myInt; 
public:
    MyStruct(int myInt) {
        this->myInt = myInt;
    }
    int GetMyInt() const {
        return myInt;
    }
};
```