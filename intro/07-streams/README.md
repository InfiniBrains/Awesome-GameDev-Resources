# Streams and File IO

At this point, you already are familiar with the `iostream` header. But we never discussed what it is properly. It is a basic stream and it has two static variable we already use: `cin` for reading variables from the console input and `cout` to output things to console, [see details here](https://en.cppreference.com/w/cpp/header/iostream). It is possible to interact with all streams via the `>>` and `<<` operators.

But C++ have 2 other relevant streams that we need to cover: [`fstream`](https://en.cppreference.com/w/cpp/header/fstream) and [`sstream`](https://en.cppreference.com/w/cpp/header/sstream).

# String Stream

The [`sstream` header](https://en.cppreference.com/w/cpp/header/sstream) describes string stream, which is a type of memory stream and is very useful to do string manipulation. For our intent, we aro going to focus 3 types of memory streams.

- `ostringstream`: works just like `cout` but the content will printed to a memory region.
  - it is more efficient to build a complex string in this way than `cout`ing multiple times;  
- `istringstream`: works just like `cin` but it will read from a memory area.
  - it is safer to read from a closed memory area than, and you ran reset the reading pointer to re-read previous elements easier than with `cin`.

```c++
#include <iostream>
#include <sstream>
using namespace std;
int main() {
    ostringstream oss; // declare the output stream
    // print numbers from 0 to 100
    for(int i=0; i<=100; i++)
        oss << i << ' '; // store the data into memory
    cout << oss.str(); // convert the stream into a string to be printed all at once
}
```

```c++
#include <iostream>
#include <sstream>
using namespace std;
int main() {
    // read input
    string input;
    getline(cin, input);

    // initialize string stream with the content from a console line
    istringstream ss(input); // declare the stream to read from

    // extract input
    string name;
    string course;
    string grade;

    iss >> name >> course >> grade;
}
```

# File streams

File streams are streams 
