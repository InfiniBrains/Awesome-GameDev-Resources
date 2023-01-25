# Case Study

## Index
- [Activity 1](#activity-1)
- [Activity 2](#activity-2)
- [Considerations](#considerations)
- [Evaluated Portfolios](#evaluated-portfolios)

This class will be focused in planning, portfolio evaluation, github processes, ci/cd and in-class activities.

# Activity 1

Start setting up your Github pages. We are going to use github pages mostly for two intentions: Webpage hosting for your portfolio and Demo project hosting.

## Webpage

For your webpage, you can develop something from ground up using your preferred web framework and we are going to show you how to do it, but the fastest way is to just follow any template. Here goes a bunch of open sourced developer portfolios you can fork and modify for your intent. https://github.com/topics/developer-portfolio?l=html . Try to take a look on them and check if you want to fork any of them. So in this activity you will have to fork and try to run a clone of a portfolio you like just to got into some action and discover how things work.

1. Find a developer portfolio on github
2. Fork it
3. Clone in your machine
4. Make some changes
5. Build it
6. Deploy it to gh-pages either via automated ci/cd or via publishing a build from a empty branch or the main one

## Demo reels
For project demo, game, or whatever interaction you want to allow the user to do, I built some boilerplates for you. Later on, you will be able to embed those webgl/html5 builds into your portfolio, so it is a good moment for you to start doing it now. As extras, optionally you can add badges for your repo from here: https://shields.io/

### SDL2

In order to showcase your ability to build something from ground up, this repo holds a boilerplate with C++, SDL2, IMGUI, SDL2IMAGE, SDL2TTF, SDL2MIXER, CI/CD automation for automatic deployment: https://github.com/InfiniBrains/SDL2-CPM-CMake-Example

1. fork it
2. go to the repo settings, actions, general, in the bottom, enable workflow permission, read and write, save
3. run github action at least once
4. enable actions and automatic page deployment from a branch gh-pages

### AI + SDL2
If you enjoy AI programming and want to test yourself, you can try forking this repo and implement what is inside the examples folder https://github.com/InfiniBrains/mobagen 

1. fork it
2. run github action at least once
3. enable actions and automatic page deployment from a branch gh-pages

### Unity
If you want to showcase your ability with Untiy, you can follow this boilerplate to have an automatic build set up. https://github.com/InfiniBrains/UnityBoilerplate

1. Fork it 
2. run github action for getting an unit licence at least once
3. grab the generated file, and upload it to https://license.unity3d.com/manual
4. get the signed licence and copy the text content to your clipboard 
5. go to your repo settings, security, secrets and variables, actions and setup a new repository secret with the name 'UNITY_LICENSE' and the content from your clipboard
6. go to the repo settings, actions, general, in the bottom, enable workflow permission, read and write, save
7. run the main action
8. enable actions and automatic page deployment from a branch gh-pages
9. edit webgl template with your logo or image

# Activity 2
This class is totally up to you. Here goes what you should do in class and finish at home. The idea is for you to feel a whole process on how to create merge and pull requests to a public repo.

1. Search a good portfolio published online
   - use Twitter, LinkedIn, Google to search for good game developer portfolios;
   - another good query on google would be "awesome developer portfolio", or "curated list of developer portfolios" try it!. Example: https://github.com/emmabostian/developer-portfolios 
   - You can use this time to search a good and open sourced portfolio to fork and start your own based on other. https://github.com/topics/developer-portfolio
2. Fork this repo
3. Create a markdown file in this folder with a meaningful name about the benchmarked repository.
   - Follow this [example](example.com.md)
   - The file name should be the website domain name followed by .md
   - If another student is aiming to evaluate the same portfolio, just edit the file adding your evaluation to the text.
4. Your file should contain:
   - A summary
   - The portfolio evaluated
   - The date the evaluation happened
   - Print-screens uploaded to image hosting services such as [imgur](https://imgur.com/) or others
   - What things you judge as good and you are aiming to follow and target
   - What things you judge that needs attention and should be improved
   - Why you would hire the owner of the portfolio
   - General considerations
5. Edit [this file](README.md) on github to link your work here if you want to showcase it here.
6. Be Kind and constructive
7. Send a push request

# Considerations
- The portfolios evaluated here are just opinions

# Evaluated Portfolios
- [Example](example.com.md)