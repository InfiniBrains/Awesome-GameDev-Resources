# Streams and File IO

At this point, you already are familiar with the `iostream` header. But we never discussed what it is properly. It is a basic stream and it has two static variable we already use: `cin` for reading variables from the console input and `cout` to output things to console, [see details here](https://en.cppreference.com/w/cpp/header/iostream). It is possible to interact with all streams via the `>>` and `<<` operators.

But C++ have 2 other relevant streams that we need to cover: [`fstream`](https://en.cppreference.com/w/cpp/header/fstream) and [`sstream`](https://en.cppreference.com/w/cpp/header/sstream).

# File streams

File streams are streams that target files instead of the terminal console. The [`fstream` header](https://en.cppreference.com/w/cpp/header/fstream) describes the file streams and the ways you can interact with it.

The main differences between console and file streams are:
- You have to target the filesystem path for files because we can manage different files at the same, but for console, you only have one, so you dont need to target which console we are streaming. In order to not mess each target, you have to declare a different variable to store the target and state.
- Files are persistent, so if you write something to them, and try to read from it again, the that will be there saved.

Files are a kind of resource managed by the operation system. So every time you request something to be read or write, behind the scenes you are requesting something to the operating system, and it can be slow or subject by lock control. When you open a file to be read or write, the OS locks it to avoid problems. You can open a file to be read multiple times simultaneously, but you cannot write more than once. So to avoid problems, after reading or writing the file, you should close the file.

```c++
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Open the file
  // this file path is relative to the executable, so be assured it exists in the same folder the executable is placed
  // fin is the variablename and it is function initialized via a file path to target, but it can be any valid identifier
  // I am using fin as variable to follow the same metaphor `fin` as `file input` as we have with console input `cin`, 
  ifstream fin("file.txt"); 

  // Check if the file is open
  // it is a good practice to check if the file is really there before doing anything
  if (!fin.is_open()) {
    cerr << "Error opening file" << endl;
    return 1; // quits the program with an error code
  }

  // Read the contents of the file line by line
  string line;
  // getline can target streams in general, so you can pass the file stream as a target
  while (getline(fin, line)) { // while the file have lines, read and store the content inside the line variable
    cout << line << endl; // output each string into the console
  }

  // Close the file
  fin.close();

  return 0;
}
```

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

You can combine string stream and file stream to read a whole file and store into a single string.

```c++
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  // Open the file
  ifstream file("file.txt");

  // Check if the file is open
  if (!file.is_open()) {
    cerr << "Error opening file" << endl;
    return 1;
  }

  // Read the contents of the file into a stringstream
  stringstream ss;
  ss << file.rdbuf(); // read the whole file buffer and stores it into a string stream

  // Close the file
  file.close();

  // Convert the stringstream into a string
  string contents = ss.str();

  cout << contents << endl; // prints the whole file at once

  return 0;
}
```

# Homework

You have the job of creating a small program to read a file image in the format PGMA and inverse the colors as a negative image.

You can test your code with different images if you want. You can download more images [here](https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html). But here goes 2 examples:

- Sample input easy: [baboon.ascii.pgm](baboon.ascii.pgm) - max intensity is not 255 and don't have comments.
- Sample input harder: [lena.ascii.pgm](lena.ascii.pgm) - have comments, and the max intensity is different than 255.

You can test if your output file is correct using [this tool](https://www.gimp.org/). You can open this file via any text reader, use the online viewer, or use any app that reads pnm images.

## Attention:

- To create the inverse image, you should read the file header and search for the maximum intensity. You should use this number as a base to inverse. In the Lena case, it is 245.
- You should pay attention that every line shouldn't be bigger than 70 chars;
- Pay attention that the line 2 might exists or not. And any comment found in the file should be skipped.

The user should input the filename to be read. So you should store it into a string variable. The output filename should be the same as the input but with '.inverse' concatenated in the end. Ex.: lena.pgm becomes lena.inverse.pgm; If you find this too complicated, just concatenate with .inverse.pgm would be acceptable. ex.: lena.pgm becomes lena.pgm.inverse.pgm

In order for your program to find the file to be read, you should provide the fullpath to the file or simply put the file in the same folder your executable is.

HINT:
In order to find comments and ignore them do something like that:
```c++
string widthstr;
int width;
fin >> widthstr;
if(widthstr.at(0)=='#')
    getline(fin, widthstr); // ignore line
else
    width = stoi(widthstr); // covert string to integer
```