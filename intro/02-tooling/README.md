# Tools for C++ development

In order to effectively code in C++ you will need some tools.

## Version Control - GIT 

> [Git](https://git-scm.com/downloads) is a version control system that is used to track changes to files, including 
source code, documents, and other types of files. It allows multiple people to work on the same files concurrently, 
and it keeps track of all changes made to the files, making it easy to go back to previous versions or merge changes 
made by different people. Git is widely used by developers for managing source code, but it can be used to track changes
to any type of file. It is particularly useful for coordinating work on projects that involve multiple 
people, as it allows everyone to see and track changes made by others. [Reference](https://chat.openai.com/).

> [Github](https://github.com) is a web-based platform for version control and collaboration on software 
projects. It is a popular platform for developers to share and collaborate on code, as well as to track and manage 
software development projects. GitHub provides version control using Git, a version control system that allows 
developers to track changes to their codebase and collaborate with other developers on the same codebase. It also
includes a range of features such as bug tracking, project management, and team communication tools. In addition to 
being a platform for software development, GitHub is also a community of developers and a marketplace for buying and 
selling software development services. [Reference](https://chat.openai.com/).

In this course we are going to extensively use GITHUB functionalities. So create an account now with your 
personal account. Use a meaningful username. Avoid names that hard to associate with you. If you have a educational 
email or student id, apply for the [Github Student Pack](https://education.github.com/pack), so you will have access 
to lots of free tools.

> [GitKraken](https://www.gitkraken.com/) GitKraken is a Git client for Windows, Mac, and Linux that provides a 
graphical interface for working with Git repositories. It allows users to manage Git repositories, create and review 
changes to code, and collaborate with other developers. Some features of GitKraken include a visual representation 
of the repository's commit history, the ability to stage and discard changes, and support for popular version 
control systems like GitHub and GitLab. GitKraken is designed to be user-friendly and to make it easier for 
developers to work with Git, particularly for those who may be new to version control systems. 
[Reference](https://chat.openai.com/).

Gitkraken is a paid software, and it is free for public repositories, but you can have all enterprise and premium
functionalities enabled for free with the student pack and described before.  

## Compiler
> A compiler is a type of computer program that translates source code written in a programming language into machine 
code that can be executed by a computer. The machine code is a sequence of instructions that are specific to a 
particular computer architecture and operating system. The source code is written in a high-level programming 
language, such as C++, Java, or Python, which is easier for humans to read and write. The compiler converts the 
source code into machine code that can be run on a computer. There are different types of compilers, including 
cross-compilers, which can compile code for one type of computer to run on another type of computer, and 
just-in-time (JIT) compilers, which compile code at runtime. Compilers are an important part of the software 
development process, as they allow developers to write code in a high-level language that is then translated into 
machine code that can be run on a specific platform. [Reference](https://chat.openai.com/)

This where things get tricky, C++ compiles the code into a binary that runs directly on the processor and interacts 
with the operating system. So we can have multiple combinations here. Most compilers are cross-platform, but there 
is exceptions. And to worsen it, some Compilers are tightly coupled with some IDEs(see below, next item). 

I personally prefer to use CLang to be my target because it is the one that is most reliable cross-platform 
compiler. Which means the code will work as expected in most of the scenarios, the feature support table is the same 
across all platforms. But GCC is the more bleeding edge, which means usually it is the first to support all new 
fancy features C++ introduces.

No need to download anything here.

## CMake
> [CMake](https://cmake.org/) CMake is a cross-platform free and open-source software tool for managing the build 
process of software using a compiler-independent method. It is designed to support directory hierarchies and 
applications that depend on multiple libraries. It is used to control the software compilation process using simple 
platform and compiler independent configuration files, and generate native makefiles and workspaces that can be used in the compiler environment of your choice. [Reference](https://chat.openai.com/).

If you use a good IDE(see next topic), you won't need to download anything here. 

<details>
CMake is typically used in conjunction with native build environments such as Make, Ninja, or Visual Studio. It can 
also generate project files for IDEs such as Eclipse, Xcode, and Visual Studio.

Here is a simple example of a CMakeLists.txt file that can be used to build a program called "myproject" that consists of a single source file called "main.cpp":

```cmake
cmake_minimum_required(VERSION 3.10)
project(myproject)
add_executable(myproject main.cpp)
```

To build the project, you would first generate a build directory, and then run CMake to build the files using the 
detected compiler or IDE:
```bash
cmake -S. -Bbuild
cmake --build build -j20
```
This will create a Makefile or a Visual Studio solution file in the build directory, depending on your platform and compiler. You can then use the native build tools to build the project by running "make" or opening the solution file in Visual Studio.

CMake provides many options and variables that can be used to customize the build process, such as setting compiler flags, specifying dependencies, and configuring installation targets. You can learn more about CMake by reading the documentation at https://cmake.org/.
</details>

## IDE

> An integrated development environment (IDE) is a software application that provides comprehensive facilities to 
computer programmers for software development. An IDE typically integrates a source code editor, build automation 
tools, and a debugger. Some IDEs also include additional tools, such as a version control system, a class browser, 
and a support for literate programming. IDEs are designed to maximize programmer productivity by providing tight-knit
components with similar user interfaces. This can be achieved through features such as auto-complete, syntax
highlighting, and code refactoring. Many IDEs also provide a code debugger, which allows the programmer to step through
code execution and find and fix errors. Some examples of popular IDEs include Eclipse, NetBeans, Visual Studio, and
Xcode. Each of these IDEs has its own set of features and capabilities, and developers may choose one based on their
specific needs and preferences. [Reference](https://chat.openai.com/).

In this course, it is strongly suggested to use an IDE in order to achieve higher quality of deliveries, a good IDE 
effectively flatten the C++ learning curve. You can opt out and use everything by hand, of course, and it will deepen 
your knowledge on how things work but be assured it can slow down your learning process. Given this course is result 
oriented, it is not recommended to not use an IDE here. So use one.

OPINION: The most pervasive C++ IDE is [CLion](https://www.jetbrains.com/clion/) and this the one I am going to use. If 
you use it too, it would be easier to follow my recorded videos. It works on all platforms Windows, Linux and Mac. I 
recommend downloading it via [Jetbrains Toolbox](https://www.jetbrains.com/toolbox-app/). If you are a student, apply
for student pack [for free here](https://www.jetbrains.com/community/education/#students). On Windows, CLion embeds 
a GCC compiler or optionally can use visual studio, while on Macs it requires the xcode command line tools, and on 
Linux, uses GCC from the system installation.

The other options I suggest are:

### On all platforms

[REPLIT](https://replit.com/) - an online and real-time multiplayer IDE. It is slow and lack many functionalities, 
but can be used for small scoped activities or work with a friend.

[VSCode](https://code.visualstudio.com/) - a small and highly modularized code editor, it have lots of extensions, 
but it can be complex to set up everything needed: git, cmake, compiler and other stuff.

### On Windows:
[Visual Studio](https://visualstudio.microsoft.com/) - mostly for Windows. When installing, mark C++ development AND 
search and install additional tools "CMake". Otherwise, this repo won't work smoothly for you.

[DevC++](https://www.bloodshed.net/) - an outdated and small IDE. Lacks lots of functionalities, but if you don't 
have HD space or use an old machine, this can be your option. In long term, this choice would be bad for you for the 
lack of functionalities. It is better to use REPLIT than this tool, in my opinion.

### On OSX

[XCode](https://developer.apple.com/xcode/) - for OSX and Apple devices. It is required at least to have the Command 
Line Tools. CLion on Macs depends on that. 
<details>
Xcode Command Line Tools is a small suite of software development tools that are installed on your Mac along with Xcode. These tools include the GCC compiler, which is used to compile C and C++ programs, as well as other tools such as Make and GDB, which are used for debugging and development. The Xcode Command Line Tools are necessary for working with projects from the command line, as well as for using certain software development tools such as Homebrew.

To install the Xcode Command Line Tools, you need to have Xcode installed on your Mac. To check if Xcode is already installed, open a Terminal window and type:

```xcode-select -p```

If Xcode is already installed, this command will print the path to the Xcode developer directory. If Xcode is not installed, you will see a message saying "xcode-select: error: command line tools are not installed, use xcode-select --install to install."

To install the Xcode Command Line Tools, open a Terminal window and type:

```xcode-select --install```

This will open a window that prompts you to install the Xcode Command Line Tools. Follow the prompts to complete the installation.

Once the Xcode Command Line Tools are installed, you can use them from the command line by typing commands such as gcc, make, and gdb. You can also use them to install and manage software packages with tools like Homebrew.
</details>

### On Linux

If you are using Linux, you know the drill. No need for further explanations here, you are ahead of the others. 
<details>
If you are using an Ubuntu distro, you can try this to install most of the tools you will need here:

```console
  sudo apt-get update && sudo apt-get install -y build-essential git cmake lcov xcb libx11-dev libx11-xcb-dev 
  libxcb-randr0-dev
```

You will have a plethora of editors and IDEs. The one I can suggest is the VSCode, Code::Blocks or KDevelop. But I 
really prefer CLion.
</details>

# Homework

1. Setup your environment for your needs. If you are unsure, use CLion. 
2. Fork this repo privately. You will have to do your assignments there. Go to the home repo and hit
[fork](https://github.com/InfiniBrains/Introduction-to-Game-Programming-With-CPP/fork).
3. Clone this repo to your machine. [gitkraken + github](https://www.youtube.com/watch?v=5nhNfMcczlQ)
[gitkraken clone](https://www.youtube.com/watch?v=Mxd-0dO2uyI)
[gitkraken big tutorial](https://www.youtube.com/watch?v=ceT3pm5hYvs)
4. Make sure the CMake option "ENABLE_INTRO" is set as ON in CMakeLists.txt file in the root directory in order to see 
   and enable all activities.
5. (enrolled students) If you are enrolled in a class with me, share your repo with me, so I can track your evolution.
And do the activities described there.
6(optional) star the repo :-)

# Troubleshooting
If you have problems here, start a
[discussion](https://github.com/InfiniBrains/Introduction-to-Game-Programming-With-CPP/discussions) this is publicly 
visible and not FERPA compliant. Use discussions in Canvas if you are enrolled in a class with me.