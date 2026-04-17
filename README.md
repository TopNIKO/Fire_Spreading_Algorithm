// Dependencies:
    main.cpp fire.cpp fire.h

// Compilation: (GCC)(g++)
    g++ main.cpp fire.cpp

// Using make:

default:	main.cpp fire.cpp fire.h
			g++ main.cpp fire.cpp -o a.exe

// Extra:

    main.cpp : entry to program
    fire.h   : Header file for algorithm1 fire spreading
    fire.cpp : Implementation file for algorithm 1 fire spreading

About:

Input: 2D vector   "acts as a forest"
Output:			   "days it takes to burn through forest"

Grid Analysis:
burning-tree: 2
healthy-tree: 1
no-tree: 0

Day 0 starts at tree's that are burning(2). On that repsective day a burning tree can spread to a healthy tree. This healhty tree will be considered the burning trees for day 1, etc...

Once all healhty tree's have burned, return days(SUCCESS), else return -1 meaning all tree's have not burned yet(FAILURE)
