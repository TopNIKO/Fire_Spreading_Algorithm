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
