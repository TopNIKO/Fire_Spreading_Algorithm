#include <iostream>
#include <vector>
#include "fire.h"

void DisplayVector(std::vector<std::vector<int>>& vec);

int main(void)
{

	// CASE 1
	std::cout << "====== CASE 1 ====== \n\n";
	std::cout << "forest1:\n\n";
	std::vector<std::vector<int>> forest1;

	forest1.push_back(std::vector<int>{ 2, 1, 1 });
	forest1.push_back(std::vector<int>{ 1, 1, 0 });
	forest1.push_back(std::vector<int>{ 0, 1, 1 });

	DisplayVector(forest1);

	std::cout << "\nDays: " << fire::FireSpreadAlgo(forest1) << "\n\n";

	// CASE 2
	std::cout << "====== CASE 2 ======\n\n";
	std::cout << "forest2:\n\n";
	std::vector<std::vector<int>> forest2;
	
	forest2.push_back(std::vector<int>{ 2, 1, 1 });
	forest2.push_back(std::vector<int>{ 0, 1, 1 });
	forest2.push_back(std::vector<int>{ 1, 0, 0 });
	
	DisplayVector(forest2);
	
	std::cout << "\nDays: " << fire::FireSpreadAlgo(forest2) << "\n\n";



	// CASE 3
	std::cout << "====== CASE 3 ======\n\n";
	std::cout << "forest3:\n\n";
	std::vector<std::vector<int>> forest3;

	forest3.push_back(std::vector<int>{ 0, 2 });
	DisplayVector(forest3);

	std::cout << "\nDays: " << fire::FireSpreadAlgo(forest3) << "\n\n";

	return 0;
}


void DisplayVector(std::vector<std::vector<int>>& vec)
{

	
		for(int i{}; i < static_cast<int>(vec.size()); ++i)
		{
			std::cout << '{';
			for (int j{}; j < static_cast<int>(vec.at(0).size()); ++ j)
			{
				std::cout << vec.at(i).at(j);
				if (j + 1 < static_cast<int>(vec.at(0).size()))
				{
					std::cout << ',';
				}
			}
			std::cout << '}' << std::endl;
		}


	
}
