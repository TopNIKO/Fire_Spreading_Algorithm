


#ifndef FIRE
#define FIRE


#include <iostream>
#include <vector>


// Pre-processor defined macros
// for ease of reading code
#define BURNED_TREE 2
#define HEALTHY_TREE 1
#define NO_TREE 0
#define EMPTY 0

// Creating namespace to simulate possible name conflicts
namespace fire
{
	int FireSpreadAlgo(std::vector<std::vector<int>>& forest);
}


// Cell Data structure
struct Cell
{
	int y;
	int x;

	Cell() = delete;
	Cell(int y, int x): y(y), x(x){} // Type Constructor
	Cell(const Cell& copy): y(copy.y), x(copy.y){} // COPY CTOR
	
	int Value(std::vector<std::vector<int>>& forest) const;
	int Up(std::vector<std::vector<int>>& forest) 	 const;
	int Down(std::vector<std::vector<int>>& forest)	 const;
	int Left(std::vector<std::vector<int>>& forest)  const;
	int Right(std::vector<std::vector<int>>& forest) const;
};


#endif
