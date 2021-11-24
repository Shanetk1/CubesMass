#ifndef PATH_H
#define PATH_H

#include "../../../Vector.h"
#include <vector>

struct Path
{
	//Contains current 

	//Defaults to 0 
	std::vector<int> vectorList;

	

	int currentIndex = 0;
	int currentNode = 0;



	Path(std::vector<int> path)
	{
		vectorList = path;
		currentNode = path[path.size() - 1];
		currentIndex = path.size() - 1;


	}


	

	Vector2 getCurrentNodePosition(std::vector<std::vector<TileDemo*>>& tiles_)
	{
		//This will need to know about the tile map....
		
		//From this we can find our values its hard to do however....


		for (int i = 0; i < 20; i++)
		{
			//Loop through the tilesize until we find the node 
		
			for (int j = 0; j < 25; j++)
			{
				//
				if (tiles_[i][j]->getNode() == currentNode)
				{
					return tiles_[i][j]->getPosition();
				}
			}
		}
	}
	


	void incrementCurrentNode(int inc_)
	{
		//Meaning go to the next node in the list or path

		if (currentIndex - inc_  < vectorList.size())
		{
			currentNode = vectorList[currentIndex - inc_];
			currentIndex = currentIndex - inc_;
			//Update node as well...
		}
		else
		{
			printf("Error");
		}
	}


};




#endif // !PATH_H
