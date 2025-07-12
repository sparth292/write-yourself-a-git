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
I ain't trynna using anything too fancy
and cpp code looks like a pseudo code anyways, so it will be easy to follow I guess ,
IMO the most complicated part will be the command line args parsing logic 

We will use this command to run out file and make it executable

g++ -std=c++17 -o wyag main.cpp repository.cpp object.cpp ...

We can add fancy Shebang for fancy ux

#!/usr/bin/env wyag