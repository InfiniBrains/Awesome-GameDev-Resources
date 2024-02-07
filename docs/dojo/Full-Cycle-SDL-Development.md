# Full Cycle Cross-platform Game Development with SDL, CMAKE and GitHub 

This Dojo is focused in training professionals on setting up a full cycle project using SDL, CMAKE and GitHub actions.

# Agenda:
- Introduction (5 minutes): The facilitator introduces the coding dojo and the goal of the session, which is to create a CMake build system for an SDL project using GitHub Actions.
- Warm-up exercise (10 minutes): A brief exercise is conducted to get participants warmed up and familiar with SDL and CMake.
- Setting up the project (30 minutes): Participants work in pairs or small groups to clone the SDL project from GitHub and create a CMake build system for it.
- Adding GitHub Actions (30 minutes): Participants continue to work on their CMake build systems and add GitHub Actions to automate the build and test process.
- Review and discussion (10 minutes): Participants share their solutions and discuss the various approaches taken to create the CMake build system and implement GitHub Actions.
- Retrospective (5 minutes): Participants reflect on the session and provide feedback on what went well and what could be improved for future sessions.
- Closing (5 minutes): The facilitator concludes the session and thanks the participants for their contributions.

## Introduction

## Warm-up
- Write down what do you expect from this Dojo [here](https://github.com/InfiniBrains/Awesome-GameDev-Resources/issues/2);

## Setup
You can either fork [Modern CPP Starter Repo](https://github.com/InfiniBrains/ModernCppStarter) (and star it) or create your own from scratch.

Ensure that you have the following software installed in your machine:

- C++ Compiler. Ex.: GCC(build-essential, and cmake) on Linux, MS Visual Studio on Windows(select C++ and in additional tools, select cmake), Command Line Tools for OSX.
- Git. Ex.: Gitkraken(free for students);
- IDE. Ex.: Clion(free for students);
- CMake. Ex.: cmake-gui, but clion already bundle it for you.

## Action
### 1. Clone.

Clone your repository you created or forked in the last step ([Modern CPP Starter Repo](https://github.com/InfiniBrains/ModernCppStarter));

### 2. CMake Glob

Edit your CMakeLists.txt to glob your files (naive and powerful approach). Example:

Minimum CMake:
```cmake
cmake_minimum_required(VERSION 3.25)
project(MY_PROJECT)
set(CMAKE_CXX_STANDARD 17)
add_executable(mygamename main.cpp)
```
Add a GLOB to search for four files. 
```cmake
file(GLOB MY_INCLUDES # Rename this variable
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        )

file(GLOB MY_SOURCE # Rename this variable
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        )
```
Then edit your last line to use the result of it as the sources for your executable.
```cmake
add_executable(mygamename ${MY_SOURCE} ${MY_INCLUDE})
```

### 3. CPM

Add code for the package manager [CPM](https://github.com/cpm-cmake/CPM.cmake). 

Read their [example](https://github.com/cpm-cmake/CPM.cmake#full-cmakelists-example) and how do you [download it](https://github.com/cpm-cmake/CPM.cmake#adding-cpm). Optionally, you can download it [dynamically](https://github.com/cpm-cmake/CPM.cmake/wiki/Downloading-CPM.cmake-in-CMake), this is the way I prefer.;

### 4. SDL dependency

Use CPM to download your dependencies. Please refer to this [issue comment](https://github.com/cpm-cmake/CPM.cmake/issues/373#issuecomment-1191401527) for an example. If you want to see something already done, check [this one](https://github.com/InfiniBrains/mobagen/blob/master/external/sdl.cmake);

### 5. Linking

Link your executable to SDL;
```cmake
target_link_libraries(mygamename PUBLIC SDL2)
```
You can see it in action [here](https://github.com/InfiniBrains/SDL2-CPM-CMake-Example/blob/main/CMakeLists.txt).
In this example, we include the external cmake file manage that. It is a good practice to do that. 

### 6. Optional: ImGUI

ImGui for debugging interface purposes;

Use CPM to download ImGUI and link it to your library. [Example](https://github.com/InfiniBrains/mobagen/blob/master/external/imgui.cmake) - You can optionally remove the static link if you want.
  https://github.com/InfiniBrains/SDL2-CPM-CMake-Example/blob/main/main.cpp

Link your executable to IMGUI
```cmake
target_link_libraries(mygamename PUBLIC SDL2 IMGUI)
```

### 7. It is GAME time! 

Copy this example [here](https://github.com/ocornut/imgui/blob/master/examples/example_sdl2_sdlrenderer/main.cpp) to your `main.cpp` if you are going do use ImGUI or just use something like this:

```c++
#include <stdio.h>

#include "SDL.h"

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *screen = SDL_CreateWindow("My application",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            0);
    if(!screen) {
        fprintf(stderr, "Could not create window\n");
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    if(!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 0;
}
```

### 8. Github Actions. 

Create folder `.github` and inside it another one `workflows`. Inside it create a `.yml` file.

Here you will code declaratively how your build should proceed. The basic steps are usually: Clone, Cache, Install dependencies, Configure, Build, Test and Release conditionally to branch.

Check and try to reproduce the same thing you see [here](https://github.com/InfiniBrains/mobagen/tree/master/.github/workflows). 

If you are following the [Modern CPP Starter Repo](https://github.com/InfiniBrains/ModernCppStarter), you can explore automated tests. Be my guest and try it.

## Review
How far you went? Share your repos [here](https://github.com/InfiniBrains/Awesome-GameDev-Resources/issues/2).

## Retrospective

Please give me feedbacks in what we did today. If you like or have something to improve, say something in [here](https://github.com/InfiniBrains/Awesome-GameDev-Resources/issues/2). Ah! you can always fork this repo, improve it and send a pull request back to this repo.

## Closing

Give stars to all repos you saw here as a way to contribute to the continuity of the project. [![say thanks](https://img.shields.io/badge/Say%20Thanks-👍-1EAEDB.svg)](https://github.com/InfiniBrains/Awesome-GameDev-Resources/stargazers)

Propose a new Dojo and be in touch. [![Discord](https://img.shields.io/discord/956922983727915078)](https://discord.gg/9CdJeQ2XKB)