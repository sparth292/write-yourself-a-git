Write Yourself a git (C++ Version)

In this Documentation, 
I'll be sharing a journey of 
building my own git from scratch using C++

I'll be referring this article throughout this journey - https://wyag.thb.lt/

Prerequisites :

I’m only going to assume some level of familiarity with the most basic git commands 

1. init: Creates a new, empty Git repository or reinitializes an existing one.
2. add: Stages changes from your working directory to the staging area for the next commit.
3. rm: Removes files from your working directory and stages the deletion for the next commit.
4. commit: Records staged changes permanently into the repository's history.
5. checkout: Switches between different branches or restores working tree files.

Language wise, i will be implementing this in C++ , 

I'm not trying to do anything too fancy
in fact, I chose C++ because it often reads like pseudocode,
so it should be fairly easy to follow , I guess.

Let's first understand the structure of this project:

wyag/

├── src/

│   ├── main.cpp

│   ├── object.cpp

│   ├── repository.cpp

│   ├── utils.cpp

│   ├── object.h

│   ├── repository.h

│   ├── utils.h

├── wyag


We will use this command to run output file and make it executable:

g++ -std=c++17 -o wyag src/main.cpp src/repository.cpp src/utils.cpp

after this command 
use this to run the executable file 
I'm doing my shit in linux. 
So, I'll be using

./wyag

in the terminal
 






