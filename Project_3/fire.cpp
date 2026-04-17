#include "fire.h" // Fire library(static)
#include <queue>  // Queue Library(static)



// Fire Spreading Algorithm Implementation
int fire::FireSpreadAlgo(std::vector<std::vector<int>>& forest)
{

	// Check the forest is not empty
	if(forest.size() <= 0)
	{
		return -1; // no spread
	}

	int f_rows{static_cast<int>(forest.size())};		// Row Count
	int f_cols{static_cast<int>(forest.at(0).size())};	// Column Count
	int healthyTreesCount{};							// Healthy Tree's Total Count
	int healthyTreesBurnedCount{};						// Healthy burned Trees total
	int curDayBurnedTreeCount{};						// Current Day's Burned Trees
	int nextDayBurnedTreeCount{};						// Next Day's Burned Trees
	int dayCount{};										// Total Day Counter to Burn Trees

	// Appending Tree's that are going to burn(Queue)
	std::queue<Cell> burnedTrees;

	// Going through forest
	for (int row{}; row < f_rows; ++row) // Row itteration
	{
		for (int col{}; col < f_cols; ++col) // Column itteration
		{
			// Check if the current Location in forest is burning Tree
			if (forest.at(row).at(col) == BURNED_TREE)
			{
				// If so append burning tree Cell(y,x)
				burnedTrees.push(Cell(row, col));
			}
			// Count Total Healthy tree's this will be important
			// for later since we need to check if all healthy trees have
			// successfully burned
			else if (forest.at(row).at(col) == HEALTHY_TREE)
			{
				// Increase healhty tree counter
				++healthyTreesCount;
			}
		}
	}

	// Keeping track of the curent day burning trees
	// Note: this variable will help us determine once we reach the next
	// 		 day in our queue
	curDayBurnedTreeCount = burnedTrees.size();

	
	// If current day burning Tree count is none
	// this is a invalid forest
	if (curDayBurnedTreeCount == 0)
	{
		return -1; // No burning trees
	}

	// Bruning Tree process
	// This while will iterate (up,down,left,right) 
	// and burn those trees if possible
	// Once all have been burned, while loop terminates
	
	while(burnedTrees.size())
	{

		// Once all currently burning trees have been poped
		// from queue, we are now on the next day
		if(curDayBurnedTreeCount == 0)
		{
			curDayBurnedTreeCount = nextDayBurnedTreeCount;		// Set New Current day's burning tree count
			healthyTreesBurnedCount += nextDayBurnedTreeCount;  // new burned tree is the same as old healthy tree
			nextDayBurnedTreeCount = 0;							// reset next days burn tree's
		
			++dayCount;											// Next day arrived
		}
		
		Cell& b_tree = burnedTrees.front(); // Current day's most present burning tree
		burnedTrees.pop();					// Pop from queue

		if (b_tree.Up(forest) == HEALTHY_TREE)	// Check tree above of current burning tree is a healthy tree
		{
			int up_y = b_tree.y - 1; // Cell location y
			int up_x = b_tree.x;	 // Cell location x
			
			forest.at(up_y).at(up_x) = BURNED_TREE; // Mark it as now burning
			burnedTrees.push(Cell(up_y, up_x));		// Add to queue, since it's now a new contender to burn more trees
			
			++nextDayBurnedTreeCount;				// Increase next day tree's to burn counter
		}
		
		if (b_tree.Down(forest) == HEALTHY_TREE)	// Check tree to left of current burning tree
		{
			int down_y = b_tree.y + 1;	// Cell location y
			int down_x = b_tree.x;		// Cell location x
			
			forest.at(down_y).at(down_x) = BURNED_TREE; // Mark right tree as now burning
			burnedTrees.push(Cell(down_y, down_x));		// Add to queue
			
			++nextDayBurnedTreeCount;					// Increase old healthy tree count
		}
		if (b_tree.Left(forest) == HEALTHY_TREE) // Check if right tree is healthy tree
		{
			int left_y = b_tree.y;		// Cell location y
			int left_x = b_tree.x - 1;	// Cell location x
			
			forest.at(left_y).at(left_x) = BURNED_TREE;		// Mark left tree as now burning
			burnedTrees.push(Cell(b_tree.y,b_tree.x - 1));	// Add to queue

			++nextDayBurnedTreeCount;					// Increase old healthy tree count
		}
		
		if (b_tree.Right(forest) == HEALTHY_TREE)		// Check right tree if healhty
		{
			int right_y = b_tree.y;		// Cell location y
			int right_x = b_tree.x + 1;	// Cell location x
						
			forest.at(right_y).at(right_x) = BURNED_TREE;	// Set right tree to burning
			burnedTrees.push(Cell(b_tree.y, b_tree.x + 1));	// Add to queue
		
			++ nextDayBurnedTreeCount;						// Increase old healhty tree count
		}
		
		--curDayBurnedTreeCount;							// Mark off curent burning tree from
															// burning trees to itterate through
	}
	

	// If burned healhty tree's equal to total Healthy tree's
	// Means forest has burned down, else it survived the burn
	
	if (healthyTreesBurnedCount == healthyTreesCount)
	{
		return dayCount;
	}

	return -1; // FAILED TO BURN ALL HEALTHY TREES

	
}

// Get Value at current cell location
int Cell::Value(std::vector<std::vector<int>>& forest) const
{
	
	return forest.at(y).at(x); // curren cells value
	
}

// Get value upward of current cell
int Cell::Up(std::vector<std::vector<int>>& forest) const
{
	// Bounds check return -1;
	if(y - 1 < 0)
	{
		return -1;
	}

	return forest.at(y - 1).at(x); // Return upward cells value
	
}

// Get value downward of current cell location
int Cell::Down(std::vector<std::vector<int>>& forest) const
{
	// Bounds check return -1;
	if(y + 1 > (static_cast<int>(forest.size()) - 1))
	{
		return -1;
	}

	return forest.at(y + 1).at(x); // Return downard cells value
	
}

// Get value left of current cell location
int Cell::Left(std::vector<std::vector<int>>& forest) const
{
	// Bounds check return -1;
	if(x - 1 < 0)
	{
		return -1;
	}

	return forest.at(y).at(x - 1); // Return left cells value
	
}

// Get value right of current cell location
int Cell::Right(std::vector<std::vector<int>>& forest) const
{

	// Bound check return -1
	if ( x + 1 > static_cast<int>(forest.at(0).size()) - 1)
	{
		return -1;
	}

	return forest.at(y).at(x + 1); // Return right cells value

}



