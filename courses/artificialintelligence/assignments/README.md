# Setup the repos

1. Read about Privacy and FERPA compliance [here](../../../blog/posts/FerpaCompliance/FerpaCompliance.md)
2. This one, for in class coding assignments. https://github.com/InfiniBrains/Awesome-GameDev-Resources
3. MoBaGEn, for interactive assignments. https://github.com/InfiniBrains/mobagen
4. Install `CLion` :simple-clion: (has `CMake` :simple-cmake: embedded) or see [#development-tools](#development-tools)
5. Those repositories are updated constantly. Pay attention to syncing your repo frequently.

## Types of coding assignments

There are two types of coding assignments:

1. Algorithm: [Beecrowd](https://www.beecrowd.com.br/) - This is an automatic grading system, and I am still creating assignments for it. I will try my best to make it work through it. If it does not work, you could just submit the code on canvas and I will grade it manually. Those should solved using C++ :simple-cplusplus:;
2. Interactive: For the interactive assignments you can choose whatever Game Engine you like, but I recommend you to use the framework I created for you: [MoBaGEn](https://github.com/InfiniBrains/mobagen). If you use a Game Engine or custom solution for that, you will have to create all debug interfaces to showcase and debug AI wich includes, but it is not limited to:

    - Draw vectors to show forces applied by the AI;
    - Menus to change AI parameters;

!!! danger

    Under no circunstaces, you should make your algorithm solutions public. Be aware that I spend so much time creating them and it is hard to me to always create new assignments.

## Code assignments

!!! warning inline end

    If you are a enrolled in a class that uses this material, you SHOULD use the institutional and internal git server to be [FERPA](https://www2.ed.gov/policy/gen/guid/fpco/ferpa/index.html) compliant. If you want to use part of this assignments to build your portfolio I recommend you to use github and make only the interactive assignment public. If you are just worried about privacy concerns, you can use a private repo on github.

1. Create an account on github.com or any `git` hosting on your preference;
2. Fork repos or duplicate the target repo on your account; 
   
    1. If you want to make it count as part of your portfolio, fork the repo follow [this](https://docs.github.com/en/get-started/quickstart/fork-a-repo);
    2. If you want to keep it private or be FERPA compliant, duplicate the repo following [this](https://docs.github.com/en/repositories/creating-and-managing-repositories/duplicating-a-repository);
   
3. Add my user to your repo to it with `read` role. My userid is `tolstenko`(or your professor) on github, for other options, talk with me in class. Follow [this](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/managing-repository-settings/managing-teams-and-people-with-access-to-your-repository);
4. Send me a message on canvas with the link to your repo;

## Recordings

In all interactive assignmets, you will have to record a 5 minute video explaing your code. Use [OBS](https://obsproject.com/) or any software you prefer to record your screen while you explain your code. But for this one, just send me the video showing the repo and the repo invites sent to me.

## Development tools

I will be using `CMake` :simple-cmake: for the classes, but you can use whatever you want. Please [read this](../../intro/02-tooling/README.md) to understand the `C++` :simple-cplusplus: toolset.

In this class, I am going to use `CLion` :simple-clion: as the `IDE`, because it has nice support for `CMake` :simple-cmake: and automated tests.

- Download it [here](https://www.jetbrains.com/clion/).
- If you are a student, you can get a free license [here](https://www.jetbrains.com/community/education/#students).

If you want to use `Visual Studio` :simple-visualstudio:, be assured that you have the `C++ Desktop Development` :simple-cplusplus: workload installed, more info [this](https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-160). And then go to `Individual Components` and install `CMake Tools for Windows` :simple-cmake:.

!!! note

    If you use `Visual Studio` :simple-visualstudio:, you won't be able to use the automated testing system that comes with the assignments.

[OPINION]: If you want to use a lightweight environment, don't use VS Code for C++ development. Period. It is not a good IDE for that. It is preferred to code via sublime, notepad, vim, or any other text editor and then compile your code via terminal, and debug via gdb, than using VS Code for C++ development.

### Openning the Repos

1. (Fork and) clone the repos;
2. Open `CLion` :simple-clion: or yor preferred `IDE` with `CMake` :simple-cmake: support;
3. Open the `CMakeLists.txt` as project from the root of the repo;
4. Wait for the setup to finish (it will download the dependencies automatically, such as `SDL`);

For the interactive assignments, use this [repo](https://github.com/InfiniBrains/mobagen) and the assignments are located in the `examples` folder.

For the algorithmic assignments, use this [repo](https://github.com/InfiniBrains/Awesome-GameDev-Resources) and the assignments are located in the `courses/artificialintelligence/assignments` folder. I created some automated tests to help you debug your code and ensure 100% of correctness. To run them, follow the steps (only available though `CLion` :simple-clion: or terminal, not `Visual Studio` :simple-visualstudio:):

1. Go to the executable drop down selection (top right, near the green `run` :material-play: or `debug` :material-bug: button) and select the assignment you want to run. It will be something like `ai-XXX` where `XXX` is the name of the assignment;
2. If you want to test your assignment against the automated inputs/outputs, select the `ai-XXX-test` build target. Here you should use the `build` :fontawesome-solid-hammer: button, not the `run` :material-play: or `debug` :material-bug: button. It will run the tests and show the results in the `Console` :material-console: tab;

